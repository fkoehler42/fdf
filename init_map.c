/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 20:09:57 by fkoehler          #+#    #+#             */
/*   Updated: 2016/01/09 17:32:37 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		init_window(t_win *win)
{
	int		i;
	int		j;

	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, 1000, 1000, "test");
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			mlx_pixel_put(win->mlx, win->win, win->map[i][j].x + 10, win->map[i][j].y + 10, 0x00FFFFFF);
			mlx_pixel_put(win->mlx, win->win, win->map[i][j].x + 11, win->map[i][j].y + 10, 0x00FFFFFF);
			mlx_pixel_put(win->mlx, win->win, win->map[i][j].x + 10, win->map[i][j].y + 11, 0x00FFFFFF);
			mlx_pixel_put(win->mlx, win->win, win->map[i][j].x + 11, win->map[i][j].y + 11, 0x00FFFFFF);
			j++;
		}
		i++;
	}
	return (0);
}
