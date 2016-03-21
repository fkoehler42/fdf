/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 13:09:18 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/21 15:53:29 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		parse_file(t_fdf *fdf, char *file)
{
	int		fd;
	int		width;
	char	*line;

	width  = 0;
	line = NULL;
	fd = open_file(file);
	while ((get_next_line(fd, &line)) == 1)
	{
		if ((width = ft_countwords(line, ' ')) > fdf->width)
			fdf->width = width;
		fdf->height++;
		free(line);
	}
	close_file(fd);
	return (0);
}
