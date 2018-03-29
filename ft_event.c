/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 12:48:45 by ehouzard          #+#    #+#             */
/*   Updated: 2018/03/26 16:36:36 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		func_to_press(int button, int x, int y, t_iso **iso)
{
	x = 0;
	y = 0;
	if (button != 0)
		(*iso)->move->clic = 1;
	return (0);
}

int		func_to_release(int button, int x, int y, t_iso **iso)
{
	x = 0;
	y = 0;
	if (button == 1)
		(*iso)->move->clic = 0;
	return (0);
}

int		func_to_turn(int x, int y, t_iso **iso)
{
	if ((*iso)->move->clic == 1)
	{
		if ((*iso)->move->mx == 0 || (*iso)->move->my == 0)
		{
			(*iso)->move->mx = x;
			(*iso)->move->my = y;
			return (0);
		}
		else
		{
			if (x > 0 && y > 0 && x < IMG_XMAX && y < IMG_YMAX)
			{
				rotation_coeff((x - (*iso)->move->mx),
						y - (*iso)->move->my, iso);
				(*iso)->move->mx = x;
				(*iso)->move->my = y;
				ft_reinit_img(iso);
				direct_knit_operation(get_idx(), iso);
				mlx_put_image_to_window((*iso)->env.image.data,
						(*iso)->env.win, (*iso)->env.image.img, 0, 0);
			}
		}
	}
	return (0);
}
