/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:32:18 by mkhoury           #+#    #+#             */
/*   Updated: 2024/11/27 17:56:07 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(t_layer *layer, t_pos a, t_color_type color)
{
	int		i;
	int		j;
	double	x;
	double	y;

	i = 0;
	y = a.y - 1;
	while (i < 3)
	{
		x = a.x - 1;
		j = 0;
		while (j < 3)
		{
			draw_pixel(x, y, color, layer);
			++x;
			++j;
		}
		++y;
		++i;
	}
}
