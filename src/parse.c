/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 13:09:18 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/24 18:21:04 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		parse_dots(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] &&
			(tab[i][j] == ' ' || tab[i][j] == '-' || tab[i][j] == '+'))
			j++;
		if (tab[i][j] && !ft_isdigit(tab[i][j]))
		{
			ft_putstr_fd("fdf: ", 2);
			ft_putstr_fd(tab[i], 2);
			ft_putstr_fd(": invalid value\n", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (0);
}

int		parse_file(char *file)
{
	int		fd;
	int		nb_dots;
	int		nb_col;
	char	*line;

	nb_dots = 0;
	line = NULL;
	fd = open_file(file);
	get_next_line(fd, &line);
	nb_col = ft_countwords(line, ' ');
	nb_dots = nb_col;
	free(line);
	while ((get_next_line(fd, &line)) == 1)
	{
		if (ft_countwords(line, ' ') != nb_col)
		{
			ft_putstr_fd("fdf: line lenght error on file ", 2);
			ft_putendl_fd(file, 2);
			exit(EXIT_FAILURE);
		}
		nb_dots += nb_col;
		free(line);
	}
	close_file(fd);
	return (nb_dots);
}
