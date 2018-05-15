/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:00:01 by ehouzard          #+#    #+#             */
/*   Updated: 2018/05/15 17:36:32 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_to_image(t_iso **hop, t_pflo p)
{
	if (((int)p.x + ((int)p.y * IMG_XMAX)) < IMG_TOTAL
			&& (int)p.x < IMG_XMAX && (int)p.y < IMG_YMAX
			&& (int)p.x > 0 && (int)p.y > 0)
		(*hop)->env.image.data
			[(int)p.x + ((int)p.y * IMG_XMAX)] = (*hop)->col->color;
}
