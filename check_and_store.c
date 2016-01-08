/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_store.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 18:06:13 by fkoehler          #+#    #+#             */
/*   Updated: 2016/01/08 12:22:22 by fkoehler         ###   ########.fr       */
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

int		*store_int(char *line, int len_save)
{
	int			i;
	int			len;
	int			*intarray;
	char		**chararray;

	i = 0;
	len = ft_countwords(line, ' ');
	if (len != len_save)
		return (0);
	if (!(intarray = (int *)malloc(sizeof(int) * len)))
		return (0);
	chararray = ft_strsplit(line, ' ');
	while (i < len)
	{
		intarray[i] = ft_atoi(chararray[i]);
		i++;
	}
	free(chararray);
	return (intarray);
}

int		**read_map(int fd, int nblines)
{
	char	*line;
	int		i;
	int		len_save;
	int		**intarray;
	
	i = 0;
	if (!(intarray = (int **)malloc(sizeof(int *) * nblines)))
		return (NULL);
	if ((get_next_line(fd, &line)) == 1)
	{
		len_save = ft_countwords(line, ' ');
		if ((intarray[i] = store_int(line, len_save)) == 0)
			return (NULL);
		i++;
	}
	while ((get_next_line(fd, &line)) == 1)
	{
		if ((intarray[i] = store_int(line, len_save)) == 0)
			return (NULL);
		i++;
	}
	if (close(fd) == -1)
		return (NULL);
	return (intarray);
}
