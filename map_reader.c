/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:34:20 by ehouzard          #+#    #+#             */
/*   Updated: 2018/05/15 14:47:39 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_read(char *arg, t_limap *parsed)
{
	int fd;
	int exit;

	exit = 0;
	init_max_zero(&parsed->maxi);
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (1);
	if (ft_get_nbrofpoint(fd, &parsed->maxi) == 1)
		return (1);
	if (close(fd) == -1 || parsed->maxi.nbp == 0)
		return (1);
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (1);
	if (ft_get_point(fd, parsed, parsed->maxi.y))
		exit = 1;
	if (close(fd) == -1)
		return (1);
	ft_coordmax(parsed);
	return (exit);
}

int		ft_get_nbrofpoint(int fd, t_max *maxi)
{
	char	*line;
	char	**tab;
	int		i;
	int		nb_words;

	line = NULL;
	tab = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		nb_words = ft_count_words(line, ' ');
		if (!(tab = ft_strsplit(line, ' ')))
		{
			free(line);
			return (-1);
		}
		while (i < nb_words)
			i++;
		maxi->nbp += i;
		maxi->y++;
		free(line);
		ft_free_tab(tab, i);
	}
	return (0);
}

int		ft_get_point(int fd, t_limap *parsed, int y)
{
	char	*line;
	int		i;
	int		cmp;

	line = NULL;
	if (!(parsed->maxi.lim = malloc(sizeof(int) * y + 1)))
		return (1);
	if (!(parsed->coord = malloc((sizeof(t_point) * parsed->maxi.nbp))))
		return (1);
	i = 0;
	cmp = 0;
	while (get_next_line(fd, &line) == 1)
	{
		parsed->maxi.lim[cmp] = ft_count_words(line, ' ');
		if (ft_fill_coord(parsed->coord, line, &i, cmp) == 1)
		{
			free(line);
			return (1);
		}
		cmp++;
		if (line)
			free(line);
	}
	return (0);
}
