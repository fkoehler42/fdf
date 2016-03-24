/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:40:24 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/24 21:56:54 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	store_dot(t_dot **map, char *line, int i, int j)
{
	int			x;
	char		**tab;
	char		**tab_save;

	x = 0;
	if (!(tab = ft_strsplit(line, ' ')))
	{
		perror("fdf");
		exit(EXIT_FAILURE);
	}
	tab_save = tab;
	parse_dots(tab);
	while (*tab)
	{
		while (**tab && **tab == ' ')
			++*tab;
		if (!**tab && ++tab)
			continue;
		if (!(map[i] = (t_dot *)malloc(sizeof(t_dot))))
		{
			perror("fdf");
			exit(EXIT_FAILURE);
		}
		map[i]->x = x;
		map[i]->y = j;
		map[i]->z = ft_atoi(*tab);
		++tab;
		i++;
		x++;
	}
	free_tab(tab_save);
	return (i);
}

int			store_map(t_fdf *fdf, char *file)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	i = 0;
	j = 0;
	line = NULL;
	fd = open_file(file);
	if (!(fdf->map = (t_dot **)malloc(sizeof(t_dot *) * (fdf->nb_dots + 1))))
	{
		perror("fdf");
		exit(EXIT_FAILURE);
	}
	while (get_next_line(fd, &line) > 0)
	{
		i = store_dot(fdf->map, line, i, j);
		j++;
		free(line);
	}
	fdf->map[fdf->nb_dots] = NULL;
	close_file(fd);
	return (0);
}
