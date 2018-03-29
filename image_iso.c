/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_iso.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:18:42 by ehouzard          #+#    #+#             */
/*   Updated: 2018/03/29 17:25:03 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			fdf_iso(t_limap *parsed)
{
	t_iso	*iso;
	t_iso	param;

	iso = NULL;
	param.map = parsed;
	init_param(parsed, &param);
	param.event.key = &my_key_func;
	param.event.mouse = &func_to_turn;
	param.event.buttonpress = &func_to_press;
	param.event.buttonrelease = &func_to_release;
	iso = &param;
	init_space(&iso, parsed);
	if (env_iso(&iso))
		return (1);
	return (0);
}

int			env_iso(t_iso **iso)
{
	(*iso)->env.mlx = mlx_init();
	(*iso)->env.win = mlx_new_window((*iso)->env.mlx,
												WINDOW_SX, WINDOW_SY, "fdf");
	(*iso)->env.image.img = mlx_new_image((*iso)->env.mlx, IMG_XMAX, IMG_YMAX);
	(*iso)->env.image.data = (int *)mlx_get_data_addr((*iso)->env.image.img,
			&((*iso)->env.image.bpp), &((*iso)->env.image.size_l),
			&((*iso)->env.image.endian));
	direct_knit_operation(get_idx(), iso);
	mlx_put_image_to_window((*iso)->env.image.data, (*iso)->env.win,
			(*iso)->env.image.img, 0, 0);
	texte_menu(iso);
	mlx_hook((*iso)->env.win, KeyPress, KeyRelease, (*iso)->event.key, iso);
	mlx_hook((*iso)->env.win, MotionNotify,
								PointerMotionMask, func_to_turn, iso);
	mlx_hook((*iso)->env.win, ButtonPress,
								ButtonPressMask, func_to_press, iso);
	mlx_hook((*iso)->env.win, ButtonRelease,
								ButtonReleaseMask, func_to_release, iso);
	mlx_loop((*iso)->env.mlx);
	return (0);
}

void		direct_knit_operation(t_idx idx, t_iso **iso)
{
	ft_recalc_coord(iso, (*iso)->map);
	idx.j = 0;
	while (idx.n <= (*iso)->map->maxi.y && idx.i <= (*iso)->map->maxi.nbp)
	{
		idx.j = 0;
		while (idx.j < (*iso)->map->maxi.lim[idx.n - 1])
		{
			knit_map(idx, iso);
			idx.i++;
			idx.j++;
		}
		idx.n++;
	}
}

void		ft_recalc_coord(t_iso **iso, t_limap *parsed)
{
	int		i;
	float	tmpx;
	float	tmpy;

	i = 0;
	while (i < parsed->maxi.nbp)
	{
		tmpx = ((float)parsed->coord[i].x) - (float)parsed->maxi.x / 2;
		tmpy = ((float)parsed->coord[i].y) - (float)parsed->maxi.y / 2;
		(*iso)->point[i].z = (float)parsed->coord[i].z;
		(*iso)->point[i].x = (cos((*iso)->alpha) * tmpx
								- (sin((*iso)->alpha) * tmpy));
		(*iso)->point[i].y = (sin((*iso)->alpha) * sin((*iso)->omega) * tmpx)
			+ (cos((*iso)->alpha) * sin((*iso)->omega) * tmpy)
			- (cos((*iso)->omega) * ((*iso)->point[i].z
				+ (*iso)->high) * (*iso)->grow);
		(*iso)->point[i].x *= (*iso)->space;
		(*iso)->point[i].y *= (*iso)->space;
		(*iso)->point[i].x += (IMG_XMAX / 2) + (*iso)->shift;
		(*iso)->point[i].y += (IMG_YMAX / 2) + (*iso)->up;
		i++;
	}
}
