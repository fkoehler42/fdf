/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:38:52 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/23 21:11:41 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	draw_line(t_fdf *fdf, t_line *line)
{
	int		x;
	int		y;
	int		i;
	float	factor;

	i = 0;
	factor = 0.0;
	if (line->xdiff == 0)
	{
		while (i != line->ydiff)
		{
			mlx_pixel_put(fdf->mlx, fdf->win, line->x, line->y + i, line->color);
			i < line->ydiff ? i++ : i--;
		}
	}
	else if (line->ydiff == 0)
	{
		while (i != line->xdiff)
		{
			mlx_pixel_put(fdf->mlx, fdf->win, line->x + i, line->y, line->color);
			i < line->xdiff ? i++ : i--;
		}
	}
	else
	{
		while (factor <= 1)
		{
			x = line->x + (line->xdiff * factor);
			y = line->y + (line->ydiff * factor);
			mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0x00FF00);
			factor += 1 / (sqrt((line->xdiff * line->xdiff) + (line->ydiff * line->ydiff)));
		}
	}
	return (0);
}

int			draw_map(t_fdf *fdf)
{
	int		i;
	int		coeff;
	t_line	line;

	i = 0;
	coeff = fdf->x_max > fdf->y_max ? 1200 / fdf->x_max : 800 / fdf->y_max;
	while (fdf->map[i + 1])
	{
		line.color = fdf->map[i]->z == 0 ? 0xFF0000 : 0x00FF00;
		if (fdf->map[i + 1]->y == fdf->map[i]->y)
		{
			line.x = fdf->map[i]->x * coeff + 200 + fdf->map[i]->z * -3;
			line.y = fdf->map[i]->y * coeff + 200 + fdf->map[i]->z * -3;
			line.xdiff = (fdf->map[i + 1]->x * coeff + 200 + fdf->map[i + 1]->z * -3) - line.x;
			line.ydiff = (fdf->map[i + 1]->y * coeff + 200 + fdf->map[i + 1]->z * -3) - line.y;
			draw_line(fdf, &line);
		}
		if (fdf->map[i + fdf->x_max])
		{
			line.x = fdf->map[i]->x * coeff + 200 + fdf->map[i]->z * -3;
			line.y = fdf->map[i]->y * coeff + 200 + fdf->map[i]->z * -3;
			line.xdiff = (fdf->map[i + fdf->x_max]->x * coeff + 200 + fdf->map[i + fdf->x_max]->z * -3) - line.x;
			line.ydiff = (fdf->map[i + fdf->x_max]->y * coeff + 200 + fdf->map[i + fdf->x_max]->z * -3) - line.y;
			draw_line(fdf, &line);
		}
		i++;
	}
	return (0);
}
