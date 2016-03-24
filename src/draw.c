/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:38:52 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/24 18:21:34 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	draw_line(t_fdf *fdf, t_l *l)
{
	int		x;
	int		y;
	int		i;
	double	factor;

	i = 0;
	x = 0;
	y = 0;
	factor = 0.0;
	if (l->xd == 0)
	{
		while (i != l->yd)
		{
			mlx_pixel_put(fdf->mlx, fdf->win, l->x, l->y + i, l->color);
			i < l->yd ? i++ : i--;
		}
	}
	else if (l->yd == 0)
	{
		while (i != l->xd)
		{
			mlx_pixel_put(fdf->mlx, fdf->win, l->x + i, l->y, l->color);
			i < l->xd ? i++ : i--;
		}
	}
	else
	{
		while (factor <= 1)
		{
			x = l->x + (l->xd * factor);
			y = l->y + (l->yd * factor);
			mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0xFFFF00);
			factor += 1 / (sqrt((l->xd * l->xd) + (l->yd * l->yd)));
		}
	}
	return (0);
}

static int	set_line_struct(t_fdf *fdf, t_l *l, t_dot* dot1, t_dot *dot2)
{
	l->x = (dot1->x * fdf->zoom) + (dot1->z * fdf->height) + fdf->x_pos;
	l->y = (dot1->y * fdf->zoom) + (dot1->z * fdf->height) + fdf->y_pos;
	l->xd = ((dot2->x * fdf->zoom) + (dot2->z * fdf->height) + fdf->x_pos) - l->x;
	l->yd = ((dot2->y * fdf->zoom) + (dot2->z * fdf->height) + fdf->y_pos) - l->y;
	l->color = dot1->z == 0 ? 0xFF0000 : 0x00FF00;
	return (0);
}

int			draw_map(t_fdf *fdf)
{
	int		i;
	t_l		l;

	i = 0;
	init_line_struct(&l);
	while (fdf->map[i + 1])
	{
		if (fdf->map[i + 1]->y == fdf->map[i]->y)
		{
			set_line_struct(fdf, &l, fdf->map[i], fdf->map[i + 1]);
			draw_line(fdf, &l);
		}
		if ((i + fdf->col) < fdf->nb_dots)
		{
			set_line_struct(fdf, &l, fdf->map[i], fdf->map[i + fdf->col]);
			draw_line(fdf, &l);
		}
		i++;
	}
	return (0);
}
