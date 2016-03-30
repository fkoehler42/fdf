/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:48:48 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/30 18:22:32 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		return (1);
	init_fdf_struct(&fdf);
	if (!(fdf.nb_dots = parse_file(av[1])))
	{
		ft_putstr_fd("fdf: ", 2);
		ft_putstr_fd(av[1], 2);
		ft_putstr_fd(" is not a valid file\n", 2);
		return (1);
	}
	store_map(&fdf, av[1]);
	get_map_size(&fdf);
	init_window(&fdf, av[1]);
	draw_map(&fdf);
	mlx_hook(fdf.win, 2, 1L << 0, &key_press, &fdf);
	mlx_mouse_hook(fdf.win, &mouse_press, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
