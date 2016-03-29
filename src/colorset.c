/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 19:55:36 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/29 14:41:11 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	draw_colorset_buttons(t_fdf *fdf, int x, int y)
{
	int		x_save;
	int		y_save;
	int		color;

	x_save = x;
	y_save = y;
	if (x == 20)
		color = 0xFFFFFF;
	else if (x == 90)
		color = 0x00FF00;
	else if (x == 160)
		color = 0x0000FF;
	else
		color = 0x660099;
	while (y < (y_save + 30))
	{
		x = x_save;
		while (x < (x_save + 60))
		{
			mlx_pixel_put(fdf->mlx, fdf->win, x, y, color);
			x++;
		}
		y++;
	}
	return (0);
}

int			draw_buttons(t_fdf *fdf)
{
	int	x;
	int	y;

	x = 20;
	y = 20;
	while (x <= 230)
	{
		draw_colorset_buttons(fdf, x, y);
		x += 70;
	}
	return (0);
}

int			change_colorset(t_fdf *fdf, int colorset)
{
	if (colorset == 1)
	{
		fdf->color1 = 0x00FF00;
		fdf->color2 = 0xFF0000;
		fdf->color3 = 0xFFFF00;
	}
	else if (colorset == 2)
	{
		fdf->color1 = 0x0000FF;
		fdf->color2 = 0xFF0000;
		fdf->color3 = 0xFFFFFF;
	}
	else if (colorset == 3)
	{
		fdf->color1 = 0x660099;
		fdf->color2 = 0x336699;
		fdf->color3 = 0x000000;
	}
	return (0);
}

int		mouse_press(int x, int y, t_fdf *fdf)
{
	if (x)
}
