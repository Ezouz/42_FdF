/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:40:08 by ehouzard          #+#    #+#             */
/*   Updated: 2018/05/15 18:07:36 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_coordmax(t_limap *parsed)
{
	int	i;

	i = 0;
	while (i < parsed->maxi.nbp)
	{
		if (parsed->coord[i].z < parsed->maxi.z_min)
			parsed->maxi.z_min = parsed->coord[i].z;
		if (parsed->coord[i].z > parsed->maxi.z_max)
			parsed->maxi.z_max = parsed->coord[i].z;
		i++;
	}
	i = 0;
	while (i < parsed->maxi.y)
	{
		if (parsed->maxi.lim[i] > parsed->maxi.x)
			parsed->maxi.x = parsed->maxi.lim[i];
		i++;
	}
}

void	init_max_zero(t_max *maxi)
{
	maxi->nbp = 0;
	maxi->x = 0;
	maxi->y = 0;
	maxi->z_min = 0;
	maxi->z_max = 0;
	maxi->shift_x = 0;
	maxi->shift_y = 0;
}

int		init_param(t_limap *parsed, t_iso *param)
{
	int i;

	i = 0;
	if (!(param->point = malloc(sizeof(t_pflo) * parsed->maxi.nbp))
			|| !(param->col = malloc(sizeof(t_col)))
			|| !(param->move = malloc(sizeof(t_mouse))))
		return (0);
	param->alpha = 19.8;
	param->omega = 19.8;
	param->high = 0.1;
	param->grow = 0.2;
	param->up = 0;
	param->shift = 0;
	param->col->color = WHITE;
	param->col->mode = 3;
	param->move->mx = 0;
	param->move->my = 0;
	while (i < parsed->maxi.nbp)
	{
		param->point[i].x = 0;
		param->point[i].y = 0;
		param->point[i].z = 0;
		i++;
	}
	return (1);
}

void	init_space(t_iso **iso, t_limap *parsed)
{
	int	stop;
	int	i;

	stop = 0;
	(*iso)->space = 1;
	while (stop != 1)
	{
		i = 0;
		(*iso)->space++;
		ft_recalc_coord(iso, parsed);
		while (i < parsed->maxi.nbp)
		{
			if ((*iso)->point[i].x > IMG_XMAX || (*iso)->point[i].y > IMG_YMAX
					|| (*iso)->point[i].x < 0 || (*iso)->point[i].y < 0)
			{
				stop = 1;
				break ;
			}
			i++;
		}
	}
	if ((*iso)->space > 1)
		(*iso)->space -= 1;
}

void	ft_reinit_img(t_iso **iso)
{
	unsigned int i;

	i = 0;
	while (i < IMG_XMAX * IMG_YMAX)
	{
		(*iso)->env.image.data[i] = 0;
		i++;
	}
}
