/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:35:59 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/23 18:56:16 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_map_size(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (fdf->map[i])
	{
		if (fdf->map[i]->x > fdf->x_max)
			fdf->x_max = fdf->map[i]->x;
		if (fdf->map[i]->y > fdf->y_max)
			fdf->y_max = fdf->map[i]->y;
		i++;
	}
	fdf->x_max++;
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
	fdf->x_max = 0;
	fdf->y_max = 0;
	return (0);
}
