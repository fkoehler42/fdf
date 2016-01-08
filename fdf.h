/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 17:56:28 by fkoehler          #+#    #+#             */
/*   Updated: 2016/01/08 12:04:53 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>

typedef	struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;


int		check_map(char *file);
int		**read_map(int fd, int nblines);
int		*store_int(char *line, int len_save);

#endif
