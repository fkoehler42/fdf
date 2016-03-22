/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 18:01:40 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/22 13:22:45 by fkoehler         ###   ########.fr       */
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

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	t_dot		**map;
	int			nb_dots;
	int			x_max;
	int			y_max;
}				t_fdf;

int				open_file(char *file);
int				close_file(int fd);

int				init_fdf_struct(t_fdf *fdf);
int				init_window(t_fdf *fdf, char *file);
int				get_map_size(t_fdf *fdf);

int				parse_file(char *file);
int				parse_dots(char **tab);
int				store_map(t_fdf *fdf, char *file);

int				draw_dots(t_fdf *fdf);

#endif

