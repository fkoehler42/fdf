/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:48:48 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/21 13:14:12 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	int		fd;
	int		nblines;
	t_win	*win;

	win = NULL;
	if (ac != 2)
		return (1);
	if ((nblines = check_map(av[1])) <= 0)
		return (1);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (1);
	if (!(win->map = read_map(fd, nblines)))
		return (1);
	return (0);
}

