/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:35:59 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/21 17:08:18 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		init_map_struct(t_fdf *fdf)
{
	int		i;

	i = 0;
	if (!(fdf->map = (t_dot **)malloc(sizeof(t_dot *) * (fdf->height + 1))))
	{
		perror("fdf : ");
		exit(EXIT_FAILURE);
	}
	while (fdf->map[i])
	{
		if (!(fdf->map[i] = (t_dot *)malloc(sizeof(t_dot) * (fdf->width + 1))))
		{
			perror("fdf : ");
			exit(EXIT_FAILURE);
		}
		i++;
		fdf->map[fdf->width] = NULL;
	}
	return (0);
}

int		init_fdf_struct(t_fdf *fdf)
{
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->map = NULL;
	fdf->height = 0;
	fdf->width = 0;
	return (0);
}
