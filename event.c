/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:59:58 by ehouzard          #+#    #+#             */
/*   Updated: 2018/05/15 17:31:04 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		my_key_func(int keycode, t_iso **iso)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		(*iso)->shift -= 5;
	if (keycode == 124)
		(*iso)->shift += 5;
	if (keycode == 126)
		(*iso)->up -= 5;
	if (keycode == 125)
		(*iso)->up += 5;
	if (keycode == 69)
		(*iso)->space += 0.2;
	if (keycode == 78)
		if ((*iso)->space >= 0.2)
			(*iso)->space -= 0.2;
	if (keycode >= 86 && keycode <= 92)
		my_key_func2(keycode, iso);
	ft_reinit_img(iso);
	direct_knit_operation(get_idx(), iso);
	mlx_put_image_to_window((*iso)->env.image.data,
						(*iso)->env.win, (*iso)->env.image.img, 0, 0);
	return (0);
}

void	my_key_func2(int keycode, t_iso **iso)
{
	if (keycode == 91)
		(*iso)->grow += 0.1;
	if (keycode == 87)
		(*iso)->grow -= 0.1;
	if (keycode == 88)
		(*iso)->high += 0.1;
	if (keycode == 92)
		(*iso)->high -= 0.1;
	if (keycode == 89)
		(*iso)->col->mode += 1;
	if (keycode == 86)
		(*iso)->col->mode -= 1;
}

void	rotation_coeff(int dx, int dy, t_iso **iso)
{
	if (dx != 0)
		dx = (dx > 0) ? 1 : -1;
	if (dy != 0)
		dy = (dy > 0) ? 1 : -1;
	if (dx == 1)
		(*iso)->alpha += 3 / (float)IMG_XMAX * 6.3;
	if (dx == -1)
		(*iso)->alpha -= 3 / (float)IMG_YMAX * 6.3;
	if (dy == 1)
		(*iso)->omega += 3 / (float)IMG_YMAX * 6.3;
	if (dy == -1)
		(*iso)->omega -= 3 / (float)IMG_YMAX * 6.3;
	if ((*iso)->alpha <= 6.3 || (*iso)->alpha >= 25.2)
		(*iso)->alpha = 18.9;
	if ((*iso)->omega <= 6.3 || (*iso)->omega > 25.2)
		(*iso)->omega = 18.9;
}

void	texte_menu(t_iso **iso)
{
	mlx_string_put((*iso)->env.image.img, (*iso)->env.win,
			70, 640, RED, "TO THE LEFT");
	mlx_string_put((*iso)->env.image.img, (*iso)->env.win,
			190, 640, WHITE, "<");
	mlx_string_put((*iso)->env.image.img, (*iso)->env.win,
			210, 610, RED, "UP");
	mlx_string_put((*iso)->env.image.img, (*iso)->env.win,
			238, 610, WHITE, "^");
	mlx_string_put((*iso)->env.image.img, (*iso)->env.win,
			280, 640, WHITE, ">");
	mlx_string_put((*iso)->env.image.img, (*iso)->env.win,
			295, 640, RED, "TO THE RIGHT");
	mlx_string_put((*iso)->env.image.img, (*iso)->env.win,
			235, 690, WHITE, "v");
	mlx_string_put((*iso)->env.image.img, (*iso)->env.win,
			255, 690, RED, "DOWN");
	mlx_string_put((*iso)->env.image.img, (*iso)->env.win,
			500, 610, WHITE, "7");
	mlx_string_put((*iso)->env.image.img, (*iso)->env.win,
			500, 640, WHITE, "4");
	texte_menu2(iso);
}

void	texte_menu2(t_iso **iso)
{
	mlx_string_put((*iso)->env.image.img, (*iso)->env.win,
			480, 680, RED, "COLOR");
	mlx_string_put((*iso)->env.image.img, (*iso)->env.win,
			570, 610, WHITE, "8");
	mlx_string_put((*iso)->env.image.img, (*iso)->env.win,
			570, 640, WHITE, "5");
	mlx_string_put((*iso)->env.image.img, (*iso)->env.win,
			555, 680, RED, "HIGH");
	mlx_string_put((*iso)->env.image.img, (*iso)->env.win,
			640, 610, WHITE, "9");
	mlx_string_put((*iso)->env.image.img, (*iso)->env.win,
			640, 640, WHITE, "6");
	mlx_string_put((*iso)->env.image.img, (*iso)->env.win,
			620, 680, RED, "HEIGHT");
	mlx_string_put((*iso)->env.image.img, (*iso)->env.win,
			710, 610, WHITE, "-");
	mlx_string_put((*iso)->env.image.img, (*iso)->env.win,
			710, 640, WHITE, "+");
	mlx_string_put((*iso)->env.image.img, (*iso)->env.win,
			695, 680, RED, "ZOOM");
}
