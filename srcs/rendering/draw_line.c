/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:23:25 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/27 15:24:45 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_put_line(t_layer *layer, t_pos a, t_pos b, t_color_type color)
{
	double	deltaX = b.x - a.x;
	double	deltaY = b.y - a.y;

	int		pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	double	pixelX = a.x;
	double	pixelY = a.y;
	while (pixels)
	{
		draw_pixel(pixelX, pixelY, color, layer);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}
