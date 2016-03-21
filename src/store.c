/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:40:24 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/21 17:02:42 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	store_dot(t_dot *dot, int fd)
{
	char		*line;
	int			x = 0;
	static int	y = 1;

	line = NULL;
	if ((get_next_line(fd, &line)) < 0)
	{
		perror("fdf : ");
		exit(EXIT_FAILURE);
	}
	while (line != NULL && ++x)
	{
		ft_putendl(line);
		if (*line != '-' && *line != '+' && *line != ' ' && !ft_isdigit(*line))
		{
			ft_putstr_fd("fdf : file not well formatted\n", 2);
			exit(EXIT_FAILURE);
		}
		dot->x = x;
		dot->y = y;
		dot->z = atoi(line);
		line = ft_strchr(++line, ' ');
		++dot;
	}
	free(line);
	//dot = NULL;
	y++;
	return (0);
}

int			store_map(t_fdf *fdf, char *file)
{
	int		i;
	int		fd;

	i = 0;
	fd = open_file(file);
	while (i < fdf->height)
	{
		store_dot(fdf->map[i], fd);
		i++;
	}
	fdf->map[fdf->height] = NULL;
	close(fd);
	return (0);
}
