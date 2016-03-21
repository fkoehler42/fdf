/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 17:56:28 by fkoehler          #+#    #+#             */
<<<<<<< HEAD:src/fdf.h
/*   Updated: 2016/03/21 13:14:07 by fkoehler         ###   ########.fr       */
=======
/*   Updated: 2016/01/08 21:02:44 by fkoehler         ###   ########.fr       */
>>>>>>> parent of 43fc92d... segfault:fdf.h
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <get_next_line.h>
# include <stdio.h>
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>

typedef	struct	s_dot
{
	int			x;
	int			y;
	int			z;
}				t_dot;

<<<<<<< HEAD:src/fdf.h
typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	t_dot		**map;
}				t_fdf;
=======
>>>>>>> parent of 43fc92d... segfault:fdf.h

int		check_map(char *file);
t_dot	**read_map(int fd, int nblines);
t_dot	*store_struct(char *line, int len_save, int i);
<<<<<<< HEAD:src/fdf.h
int		init_window(t_fdf *fdf);
=======
void	*init_window(char *title, t_dot **map, int nblines);
>>>>>>> parent of 43fc92d... segfault:fdf.h

#endif
