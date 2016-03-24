/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:35:59 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/24 17:24:36 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_map_size(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (fdf->map[i])
	{
		if (fdf->map[i]->x > fdf->col)
			fdf->col = fdf->map[i]->x;
		if (fdf->map[i]->y > fdf->lines)
			fdf->lines = fdf->map[i]->y;
		i++;
	}
	fdf->col++;
	fdf->lines++;
	fdf->zoom = fdf->col > fdf->lines ? 1200 / fdf->col : 800 / fdf->lines;
	return (0);
}

int		init_line_struct(t_l *line)
{
	line->x = 0;
	line->y = 0;
	line->xd = 0;
	line->yd = 0;
	line->color = 0;
	return (0);
}

int		init_window(t_fdf *fdf, char *file)
{
	if (!(fdf->mlx = mlx_init()))
	{
		ft_putstr_fd("fdf", 2);
		exit(EXIT_FAILURE);
	}
	if (!(fdf->win = mlx_new_window(fdf->mlx, 1600, 1200, file)))
	{
		ft_putstr_fd("fdf", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int		init_fdf_struct(t_fdf *fdf)
{
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->map = NULL;
	fdf->nb_dots = 0;
	fdf->col = 0;
	fdf->lines = 0;
	fdf->x_pos = 200;
	fdf->y_pos = 200;
	fdf->height = -3;
	fdf->zoom = 0;
	return (0);
}
