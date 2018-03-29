NAME = fdf
CC = gcc
CC_LIB = -L libft/ -lft
CFLAGS = -Wall -Wextra -Werror  
CFLAGSLBX = -lmlx -framework OpenGL -framework Appkit
X = /System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/
INCL = -I libft/includes -I$(X)
SRCS = main.c map_reader.c get_coord.c init.c ft_draw_line.c image_iso.c ft_put_pixel.c\
	   event.c ft_event.c if_color.c
OBJS = $(SRCS:.c=.o)
ARAJOUTERDSNAME1 = make -C libft/ fclean && make -C libft/
ARAJOUTERDSNAME2 = make -C minilibx_macos/

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(CFLAGSLBX) $(OBJS) $(INCL) $(CC_LIB)

debug: $(OBJS) 
	make -C libft/ fclean && make -C libft/
	make -C minilibx_macos/ 
	$(CC) -o $(CFLAGS) -g $(CFLAGSLBX) $(OBJS) $(INCL) $(CC_LIB)

%.o: %.c
	$(CC) $(CFLAGS) $(INCL) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

test : all
	@./fdf ~/Documents/fdf_maps/42.fdf
