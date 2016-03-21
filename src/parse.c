/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 13:09:18 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/21 13:22:25 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		parse_map(char *file)
{
	int		fd;
	int		nb_lines;
	char	*line;

	line = NULL;
	nb_lines = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
	{
		perror("fdf :");
		exit(EXIT_FAILURE);
	}
	while ((get_next_line(fd, &line)) == 1)
		nb_lines++;

}
