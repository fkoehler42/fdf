/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_store.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 18:06:13 by fkoehler          #+#    #+#             */
/*   Updated: 2016/01/08 21:02:35 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_map(char *map)
{
	int		fd;
	int		i;
	int		nblines;
	char	*line;

	nblines = 0;
	if ((fd = open(map, O_RDONLY)) == -1)
		return (-1);
	while ((get_next_line(fd, &line)) == 1)
	{
		i = 0;
		while (line[i])
		{
			if (!(ft_isdigit(line[i])) && line[i] != ' ' &&
					line[i] != '-' && line[i] != '+')
			{
				close(fd);
				return (0);
			}
			i++;
		}
		free(line);
		nblines++;
	}
	if (close(fd) == -1)
		return (-1);
	return (nblines);
}

t_dot	*store_struct(char *line, int len_save, int i)
{
	int			j;
	int			len;
	char		**chararray;
	t_dot		*map;

	j = 0;
	len = ft_countwords(line, ' ');
	if (len != len_save)
		return (0);
	if (!(map = (t_dot *)malloc(sizeof(t_dot) * len)))
		return (0);
	chararray = ft_strsplit(line, ' ');
	while (j < len)
	{
		ft_putnbr(map[j].x = j);
		ft_putchar(',');
		ft_putnbr(map[j].y = i);
		ft_putchar(',');
		ft_putnbr(map[j].z = ft_atoi(chararray[j]));
		ft_putchar(' ');
		j++;
	}
	ft_putchar('\n');
	free(chararray);
	return (map);
}

t_dot	**read_map(int fd, int nblines)
{
	char	*line;
	int		i;
	int		len_save;
	t_dot	**map;

	if (!(map = (t_dot **)malloc(sizeof(t_dot *) * (nblines + 1))))
		return (NULL);
	if ((get_next_line(fd, &line)) == 1)
	{
		len_save = ft_countwords(line, ' ');
		if (!(map[0] = store_struct(line, len_save, 0)))
			return (NULL);
	}
	i = 1;
	while ((get_next_line(fd, &line)) == 1)
	{
		if (!(map[i] = store_struct(line, len_save, i)))
			return (NULL);
		i++;
	}
	map[i] = NULL;
	if (close(fd) == -1)
		return (NULL);
	return (map);
}
