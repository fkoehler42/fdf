/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 19:43:46 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/30 18:22:25 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	edit_height(int keycode, t_fdf *fdf)
{
	if (keycode == 67)
	{
		if (fdf->height < -0.5)
			fdf->height *= 1.5;
		else if (fdf->height > 0.5)
			fdf->height /= 1.5;
		else
			fdf->height -= 0.2;
	}
	else if (keycode == 75)
	{
		if (fdf->height < -0.5)
			fdf->height /= 1.5;
		else if (fdf->height > 0.5)
			fdf->height *= 1.5;
		else
			fdf->height += 0.2;
	}
	return (0);
}

int			key_press(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
	{
		free_map(fdf->map);
		exit(EXIT_SUCCESS);
	}
	mlx_clear_window(fdf->mlx, fdf->win);
	if (keycode == 78 && fdf->zoom >= 3)
		fdf->zoom = fdf->zoom / 1.5;
	else if (keycode == 69)
		fdf->zoom = fdf->zoom * 1.5;
	else if (keycode == 123)
		fdf->x_pos -= 10;
	else if (keycode == 124)
		fdf->x_pos += 10;
	else if (keycode == 125)
		fdf->y_pos += 10;
	else if (keycode == 126)
		fdf->y_pos -= 10;
	else if (keycode == 67 || keycode == 75)
		edit_height(keycode, fdf);
	else if (keycode == 49)
		reset_fdf_struct(fdf);
	draw_map(fdf);
	return (0);
}
