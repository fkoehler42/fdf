/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 18:01:40 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/30 12:24:31 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <get_next_line.h>
# include <stdio.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>

# define DEBUG printf("fichier %s, ligne %d\n", __FILE__, __LINE__)

typedef	struct	s_dot
{
	int			x;
	int			y;
	int			z;
}				t_dot;

typedef struct	s_l
{
	int			x;
	int			y;
	int			xd;
	int			yd;
	int			color;
}				t_l;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	t_dot		**map;
	int			nb_dots;
	int			col;
	int			lines;
	int			x_pos;
	int			y_pos;
	int			height;
	int			zoom;
	int			color1;
	int			color2;
	int			color3;
}				t_fdf;

int				open_file(char *file);
int				close_file(int fd);

int				init_fdf_struct(t_fdf *fdf);
int				reset_fdf_struct(t_fdf *fdf);
int				init_line_struct(t_l *line);
int				init_window(t_fdf *fdf, char *file);
int				get_map_size(t_fdf *fdf);

int				parse_file(char *file);
int				parse_dots(char **tab);
int				store_map(t_fdf *fdf, char *file);

int				draw_map(t_fdf *fdf);
int				draw_buttons(t_fdf *fdf);
int				free_map(t_dot **map);
int				free_tab(char **tab);
int				key_press(int keycode, t_fdf *fdf);
int				mouse_press(int button, int x, int y, t_fdf *fdf);
int				change_colorset(t_fdf *fdf, int colorset);
int				multicolor_display(t_fdf *fdf);

#endif

