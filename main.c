/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:48:48 by fkoehler          #+#    #+#             */
/*   Updated: 2016/01/08 12:22:31 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	int		fd;
	int		nblines;
	int		**intarray;
//	int	i = 0;
//	int j;

	if (ac != 2)
		return (1);
	if ((nblines = check_map(av[1])) <= 0)
		return (1);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (1);
	if (!(intarray = read_map(fd, nblines)))
		return (1);
//	while (i < nblines)
//	{
//		j = 0;
//		while (intarray[i][j])
//		{
//			ft_putnbr(intarray[i][j]);
//			ft_putchar(' ');
//			j++;
//		}
//		ft_putchar('\n');
//		i++;
//	}
	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "Fenetre du turfu");
	mlx_loop(mlx);
	return (0);
}

