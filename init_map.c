/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 20:09:57 by fkoehler          #+#    #+#             */
/*   Updated: 2016/01/08 21:02:31 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*init_window(char *title, t_dot **map, int nblines, void *mlx)
{
	int		i;
	int		j;
	void	*win;

	i = 0;
	j = 10;
	win = mlx_new_window(mlx, 1000, 1000, title);
	while (i < nblines)
	{
		while (j < 10)
		{
			mlx_pixel_put(mlx, win, map[i][j].x + 10, map[i][j].y + 10, 0x00FFFFFF);
			mlx_pixel_put(mlx, win, map[i][j].x + 11, map[i][j].y + 10, 0x00FFFFFF);
			mlx_pixel_put(mlx, win, map[i][j].x + 10, map[i][j].y + 11, 0x00FFFFFF);
			mlx_pixel_put(mlx, win, map[i][j].x + 11, map[i][j].y + 11, 0x00FFFFFF);
			j++;
		}
		i++;
	}

	mlx_loop(mlx);
	return (win);
}
