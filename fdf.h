/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 17:56:28 by fkoehler          #+#    #+#             */
/*   Updated: 2016/01/09 17:32:42 by fkoehler         ###   ########.fr       */
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

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	t_dot		**map;
}				t_win;

int		check_map(char *file);
t_dot	**read_map(int fd, int nblines);
t_dot	*store_struct(char *line, int len_save, int i);
int		init_window(t_win *win);

#endif
