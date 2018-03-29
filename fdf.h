/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:27:00 by ehouzard          #+#    #+#             */
/*   Updated: 2018/03/29 20:57:56 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "X.h"
# define BUF_SIZE 36
# define WINDOW_SX 800
# define WINDOW_SY 750
# define IMG_XMAX 800
# define IMG_YMAX 600
# define IMG_TOTAL (IMG_XMAX * IMG_YMAX)
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define LIGHTBLUE 0x07B0F0
# define DARKGREEN 0x105A2B
# define LIGHTGREEN 0x3CE196
# define YELLOW 0xFFEA37
# define ORANGE 0xFF4F1A
# define VIOLET 0xD000F0
# define BROWN 0x8B4513

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_point;

typedef struct			s_pflo
{
	float				x;
	float				y;
	float				z;
	int					color;
}						t_pflo;

typedef struct			s_max
{
	int					nbp;
	int					x;
	int					y;
	int					z_min;
	int					z_max;
	int					shift_x;
	int					shift_y;
	int					*lim;
}						t_max;

typedef struct			s_limap
{
	t_point				*coord;
	t_max				maxi;
}						t_limap;

typedef struct			s_img
{
	void				*img;
	int					*data;
	int					bpp;
	int					size_l;
	int					endian;
}						t_img;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	t_img				image;
}						t_env;

typedef struct			s_event
{
	int					(*key)();
	int					(*key2)();
	int					(*mouse)();
	int					(*buttonpress)();
	int					(*buttonrelease)();
}						t_event;

typedef struct			s_mouse
{
	int					clic;
	float				mx;
	float				my;
}						t_mouse;

typedef struct			s_col
{
	int					color;
	int					mode;
}						t_col;

typedef struct			s_iso
{
	t_env				env;
	t_pflo				*point;
	t_limap				*map;
	t_event				event;
	t_mouse				*move;
	t_col				*col;
	float				omega;
	float				alpha;
	float				space;
	float				high;
	float				grow;
	float				up;
	float				shift;
}						t_iso;

int						ft_error(int ac);
int						ft_read(char *arg, t_limap *parsed);
int						ft_get_nbrofpoint(int fd, t_max *maxi);
int						ft_get_point(int fd, t_limap *parsed, int y);
int						ft_fill_coord(t_point *c, char *l, int *i, int cmp);
t_point					ft_get_coord(char *num, int x, int y);
void					init_coord_point(t_point *coord);
void					ft_coordmax(t_limap *parsed);
void					init_max_zero(t_max *maxi);
void					init_space(t_iso **iso, t_limap *parsed);
void					ft_reinit_img(t_iso **iso);
int						init_param(t_limap *parsed, t_iso *param);
int						fdf_iso(t_limap *parsed);
int						env_iso(t_iso **iso);
void					direct_knit_operation(t_idx idx, t_iso **iso);
void					ft_recalc_coord(t_iso **iso, t_limap *parsed);
void					knit_map(t_idx idx, t_iso **hop);
void					knit_point_to_point(t_pflo a, t_pflo b, t_iso **hop);
void					ft_draw_line(t_iso **hop, t_pflo p1, t_pflo p2);
void					ft_draw_diago_x(t_pflo p, float m, t_iso **hop);
void					ft_draw_diago_y(t_pflo p, float m, t_iso **hop);
void					pixel_to_image(t_iso **hop, t_pflo p);
int						func_to_turn(int x, int y, t_iso **iso);
int						func_to_press(int button, int x, int y, t_iso **iso);
int						func_to_release(int button, int x, int y, t_iso **iso);
int						my_key_func(int keycode, t_iso **iso);
void					my_key_func2(int keycode, t_iso **iso);
void					rotation_coeff(int dx, int dy, t_iso **iso);
void					texte_menu(t_iso **iso);
void					texte_menu2(t_iso **iso);
void					set_color_mode(t_iso **iso, t_pflo p);
void					color_mode_1(t_iso **iso, t_pflo p);
void					color_mode_2(t_iso **iso, t_pflo p);
#endif
