/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:51:16 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/29 16:20:49 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_press(int button, int x, int y, t_fdf *fdf)
{
	if (button == 1 && y > 19 && y < 51)
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		if (x > 19 && x < 60)
			change_colorset(fdf, 0);
		else if (x > 69 && x < 110)
			change_colorset(fdf, 1);
		else if (x > 119 && x < 160)
			change_colorset(fdf, 2);
		else if (x > 169 && x < 210)
			change_colorset(fdf, 3);
		draw_map(fdf);
	}
	return (0);
}
