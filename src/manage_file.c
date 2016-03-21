/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:44:43 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/21 20:26:54 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		open_file(char *file)
{
	int	fd;

	fd = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
	{
		perror("fdf");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int		close_file(int fd)
{
	if ((close(fd)) < 0)
	{
		perror("fdf");
		exit(EXIT_FAILURE);
	}
	return (0);
}
