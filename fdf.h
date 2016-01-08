/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 17:56:28 by fkoehler          #+#    #+#             */
/*   Updated: 2016/01/08 21:02:44 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>

typedef	struct	s_dot
{
	int			x;
	int			y;
	int			z;
}				t_dot;


int		check_map(char *file);
t_dot	**read_map(int fd, int nblines);
t_dot	*store_struct(char *line, int len_save, int i);
void	*init_window(char *title, t_dot **map, int nblines);

#endif
