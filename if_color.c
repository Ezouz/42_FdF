/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:17:06 by ehouzard          #+#    #+#             */
/*   Updated: 2018/03/26 16:35:53 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color_mode(t_iso **iso, t_pflo p)
{
	if ((*iso)->col->mode < 1)
		(*iso)->col->mode = 6;
	if ((*iso)->col->mode > 6)
		(*iso)->col->mode = 1;
	if ((*iso)->col->mode == 1)
		color_mode_2(iso, p);
	if ((*iso)->col->mode == 2)
		color_mode_1(iso, p);
	if ((*iso)->col->mode == 3)
		(*iso)->col->color = WHITE;
	if ((*iso)->col->mode == 4)
		(*iso)->col->color = RED;
	if ((*iso)->col->mode == 5)
		(*iso)->col->color = GREEN;
	if ((*iso)->col->mode == 6)
		(*iso)->col->color = BLUE;
}

void	color_mode_1(t_iso **iso, t_pflo p)
{
	if ((int)p.z % 13 == 7)
		(*iso)->col->color = VIOLET;
	if ((int)p.z % 13 == 1 || (int)p.z % 13 == 13)
		(*iso)->col->color = BLUE;
	if ((int)p.z % 13 == 2 || (int)p.z % 13 == 12)
		(*iso)->col->color = LIGHTBLUE;
	if ((int)p.z % 13 == 3 || (int)p.z % 13 == 11)
		(*iso)->col->color = LIGHTGREEN;
	if ((int)p.z % 13 == 4 || (int)p.z % 13 == 10)
		(*iso)->col->color = YELLOW;
	if ((int)p.z % 13 == 5 || (int)p.z % 13 == 9)
		(*iso)->col->color = ORANGE;
	if ((int)p.z % 13 == 6 || (int)p.z % 13 == 8)
		(*iso)->col->color = RED;
}

void	color_mode_2(t_iso **iso, t_pflo p)
{
	if ((int)(p.z + (*iso)->high) * (*iso)->grow <= -5)
		(*iso)->col->color = BLUE;
	else if ((int)(p.z + (*iso)->high) * (*iso)->grow <= 0)
		(*iso)->col->color = LIGHTBLUE;
	else if ((int)(p.z + (*iso)->high) * (*iso)->grow <= 1)
		(*iso)->col->color = YELLOW;
	else if ((int)(p.z + (*iso)->high) * (*iso)->grow <= 2)
		(*iso)->col->color = LIGHTGREEN;
	else if ((int)(p.z + (*iso)->high) * (*iso)->grow < 9)
		(*iso)->col->color = DARKGREEN;
	else if ((int)(p.z + (*iso)->high) * (*iso)->grow <= 35)
		(*iso)->col->color = BROWN;
	if ((int)(p.z + (*iso)->high) * (*iso)->grow > 35)
		(*iso)->col->color = WHITE;
}
