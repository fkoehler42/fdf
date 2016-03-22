/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:38:52 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/22 17:36:57 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
static int	draw_lines(t_fdf *fdf, int coeff, int i, int x, int y)
{
	int	x_next;
	int	y_next;

	x_next = fdf->map[i + 1]->x * coeff + 200;
	y_next = (fdf->map[i]->y + 1) * coeff + 200;
	while (x < x_next || y < y_next)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0xFF0000);
		if (x < x_next)
			x++;
		if (y < y_next)
			y++;
	}
	return (0);
}

int		draw_map(t_fdf *fdf)
{
	int	i;
	int	x;
	int	y;
	int	coeff;

	i = 0;
	coeff = 1200 / fdf->x_max;
	while (fdf->map[i + 1])
	{
		x = fdf->map[i]->x * coeff + 200;
		y = fdf->map[i]->y * coeff + 200;
		draw_lines(fdf, coeff, i, x, y);
		i++;
	}
	return (0);
}
