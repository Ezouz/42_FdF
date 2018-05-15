NAME = fdf
CC = gcc
CC_LIB = -L libft/ -lft
CFLAGS = -Wall -Wextra -Werror 
CFLAGSLBX = -lmlx -framework OpenGL -framework Appkit
X = /System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/
HEADER = fdf.h
INCL = -I libft/includes -I$(X)
SRCS = main.c map_reader.c get_coord.c init.c ft_draw_line.c image_iso.c ft_put_pixel.c\
	   event.c ft_event.c if_color.c
OBJS = $(SRCS:.c=.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	make -C minilibx_macos/
	make -C libft/
	$(CC) -o $(NAME) $(CFLAGS) $(CFLAGSLBX) $(OBJS) $(INCL) $(CC_LIB)

%.o: %.c
	$(CC) $(CFLAGS) $(INCL) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean
	make -C libft/ re
	make all

test : all
	@./fdf ~/Documents/fdf_maps/42.fdf
