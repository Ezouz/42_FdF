/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:51:05 by ehouzard          #+#    #+#             */
/*   Updated: 2018/03/26 17:08:13 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		knit_map(t_idx idx, t_iso **hop)
{
	if (idx.j == ((*hop)->map->maxi.lim[idx.n - 1] - 1) && idx.i != 0
			&& (idx.i + 2) < (*hop)->map->maxi.nbp)
		knit_point_to_point((*hop)->point[idx.i + 1],
				(*hop)->point[idx.i + 2], hop);
	if (idx.j < ((*hop)->map->maxi.lim[idx.n - 1] - 1))
		knit_point_to_point((*hop)->point[idx.i],
				(*hop)->point[idx.i + 1], hop);
	if ((idx.i / (*hop)->map->maxi.lim[idx.n - 1]) <= (*hop)->map->maxi.y
			&& (idx.i + (*hop)->map->maxi.lim[idx.n - 1])
			< (*hop)->map->maxi.nbp)
	{
		if (idx.j == ((*hop)->map->maxi.lim[idx.n - 1] - 1)
				&& idx.i != 0
				&& (*hop)->map->maxi.lim[idx.n - 1]
				> (*hop)->map->maxi.lim[idx.n]
				&& idx.n < (*hop)->map->maxi.y
				&& (*hop)->map->maxi.lim[idx.n] != 0)
			;
		else
			knit_point_to_point((*hop)->point[idx.i],
					(*hop)->point[idx.i + (*hop)->map->maxi.lim[idx.n - 1]],
					hop);
	}
}

void		knit_point_to_point(t_pflo a, t_pflo b, t_iso **hop)
{
	float	m;
	int		abs1;
	int		abs2;

	m = 0;
	abs1 = ((a.x - b.x) < 0 ? ((a.x - b.x) * -1) : (a.x - b.x));
	abs2 = ((a.y - b.y) < 0 ? ((a.y - b.y) * -1) : (a.y - b.y));
	if (a.x == b.x || a.y == b.y)
		ft_draw_line(hop, a, b);
	else if (abs1 > abs2)
	{
		m = (b.y - a.y) / (b.x - a.x);
		(*hop)->map->maxi.shift_x = (int)fmin(a.x, b.x);
		(*hop)->map->maxi.shift_y = (int)fmax(a.x, b.x);
		ft_draw_diago_x(((a.x < b.x) ? a : b), m, hop);
	}
	else
	{
		m = (b.x - a.x) / (b.y - a.y);
		(*hop)->map->maxi.shift_x = (int)fmin(a.y, b.y);
		(*hop)->map->maxi.shift_y = (int)fmax(a.y, b.y);
		ft_draw_diago_y(((a.y < b.y) ? a : b), m, hop);
	}
}

void		ft_draw_line(t_iso **hop, t_pflo p1, t_pflo p2)
{
	int		sens;

	sens = 0;
	if (p1.y == p2.y)
	{
		sens = (p1.x > p2.x) ? -1 : 1;
		while (p1.x != p2.x)
		{
			set_color_mode(hop, p1);
			pixel_to_image(hop, p1);
			p1.x += sens;
		}
	}
	else if (p1.x == p2.x)
	{
		sens = (p1.y > p2.y) ? -1 : 1;
		while (p1.y != p2.y)
		{
			set_color_mode(hop, p1);
			pixel_to_image(hop, p1);
			p1.y += sens;
		}
	}
}

void		ft_draw_diago_x(t_pflo p, float m, t_iso **hop)
{
	float	start;
	int		i;
	int		n;
	t_pflo	a;

	i = (*hop)->map->maxi.shift_x;
	n = (*hop)->map->maxi.shift_y;
	start = p.y;
	a.x = i;
	a.y = start;
	set_color_mode(hop, p);
	pixel_to_image(hop, a);
	while (i < n)
	{
		set_color_mode(hop, p);
		a.x = i;
		a.y = start;
		pixel_to_image(hop, a);
		start += m;
		i++;
	}
}

void		ft_draw_diago_y(t_pflo p, float m, t_iso **hop)
{
	float	start;
	int		i;
	int		n;
	t_pflo	a;

	i = (*hop)->map->maxi.shift_x;
	n = (*hop)->map->maxi.shift_y;
	start = p.x;
	a.x = start;
	a.y = i;
	set_color_mode(hop, p);
	pixel_to_image(hop, a);
	while (i < n)
	{
		a.x = start;
		a.y = i;
		set_color_mode(hop, p);
		pixel_to_image(hop, a);
		start += m;
		i++;
	}
}
