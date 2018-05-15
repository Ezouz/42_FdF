/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:01:29 by ehouzard          #+#    #+#             */
/*   Updated: 2018/05/15 18:13:01 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_error(int ac)
{
	if (ac != 2)
	{
		ft_putstr("usage: ./fdf target_file\n");
		return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_limap	parsed;

	ft_error(argc);
	if (ft_read(argv[1], &parsed))
	{
		ft_putstr("ERROR FILE\n");
		return (1);
	}
	if (!(fdf_iso(&parsed)))
		return (1);
	return (0);
}
