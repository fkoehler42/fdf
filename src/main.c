/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:48:48 by fkoehler          #+#    #+#             */
<<<<<<< HEAD:src/main.c
/*   Updated: 2016/03/21 13:14:12 by fkoehler         ###   ########.fr       */
=======
/*   Updated: 2016/01/08 21:02:39 by fkoehler         ###   ########.fr       */
>>>>>>> parent of 43fc92d... segfault:main.c
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	int		fd;
	int		nblines;
	t_dot	**map;
	void	*mlx;

	if (ac != 2)
		return (1);
	if ((nblines = check_map(av[1])) <= 0)
		return (1);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (1);
	if (!(map = read_map(fd, nblines)))
		return (1);
<<<<<<< HEAD:src/main.c
=======
	mlx = mlx_init();
	mlx_expose_hook(win, op(mlx), NULL);
	init_window(av[1], map, nblines, mlx);
>>>>>>> parent of 43fc92d... segfault:main.c
	return (0);
}

