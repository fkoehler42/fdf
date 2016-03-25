/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 19:55:36 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/25 20:20:29 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		change_colorset(t_fdf *fdf, int colorset)
{
	if (colorset == 1)
	{
		fdf->color1 = 0x00FF00;
		fdf->color2 = 0xFF0000;
		fdf->color3 = 0xFFFF00;
	}
	else if (colorset == 2)
	{
		fdf->color1 = 0x0000FF;
		fdf->color2 = 0xFF0000;
		fdf->color3 = 0xFFFFFF;
	}
	else if (colorset == 3)
	{
		fdf->color1 = 0x660099;
		fdf->color2 = 0x336699;
		fdf->color3 = 0x000000;
	}
	return (0);
}
