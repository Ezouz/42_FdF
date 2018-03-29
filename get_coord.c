/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:20:20 by ehouzard          #+#    #+#             */
/*   Updated: 2018/03/29 12:35:20 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_fill_coord(t_point *coord, char *line, int *i, int cmp)
{
	char	**tab;
	int		idx;
	int		nb_words;

	idx = 0;
	nb_words = ft_count_words(line, ' ');
	if ((tab = ft_strsplit(line, ' ')) == NULL)
		return (1);
	while (idx < nb_words)
	{
		coord[*i] = ft_get_coord(tab[idx], idx, cmp);
		(*i)++;
		idx++;
	}
	ft_free_tab(tab, idx);
	return (0);
}

void	init_coord_point(t_point *coord)
{
	(*coord).x = 0;
	(*coord).y = 0;
	(*coord).z = 0;
}

t_point	ft_get_coord(char *num, int x, int y)
{
	t_point coord;

	init_coord_point(&coord);
	coord.x = x;
	coord.y = y;
	coord.z = ft_atoi(num);
	return (coord);
}
