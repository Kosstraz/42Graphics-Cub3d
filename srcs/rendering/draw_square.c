/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:32:18 by mkhoury           #+#    #+#             */
/*   Updated: 2024/11/27 15:39:31 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(mlx_image_t *image, t_pos a, t_color_type color)
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
			mlx_put_pixel(image, x, y, color);
			//draw_pixel()
			++x;
			++j;
		}
		++y;
		++i;
	}
}
