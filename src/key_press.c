/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 19:43:46 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/29 16:06:06 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_press(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
	{
		free_map(fdf->map);
		exit(EXIT_SUCCESS);
	}
	mlx_clear_window(fdf->mlx, fdf->win);
	if (keycode == 78 && fdf->zoom >= 3 )
		fdf->zoom = fdf->zoom / 1.5;
	else if (keycode == 69)
		fdf->zoom = fdf->zoom * 1.5;
	else if (keycode == 123)
		fdf->x_pos -= 50;
	else if (keycode == 124)
		fdf->x_pos += 50;
	else if (keycode == 125)
		fdf->y_pos += 50;
	else if (keycode == 126)
		fdf->y_pos -= 50;
	else if (keycode == 67)
		fdf->height *= 1.5;
	else if (keycode == 75 && fdf->height <= -3)
		fdf->height /= 1.5;
	else if (keycode == 49)
		reset_fdf_struct(fdf);
	draw_map(fdf);
	printf("keycode : %d\n", keycode);
	return (0);
}
