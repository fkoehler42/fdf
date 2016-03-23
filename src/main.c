/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:48:48 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/23 21:07:53 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <ft_printf.h>

void	put_map(t_dot **map)
{
	int	i = 0;

	while (map[i])
	{
		ft_printf("%d,%d,%d ", map[i]->x, map[i]->y, map[i]->z);
		i++;
	}
}

int		main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		return (1);
	init_fdf_struct(&fdf);
	fdf.nb_dots = parse_file(av[1]);
	store_map(&fdf, av[1]);
	get_map_size(&fdf);
	//put_map(fdf.map);
	init_window(&fdf, av[1]);
	draw_map(&fdf);
	mlx_loop(fdf.mlx);
	return (0);
}

