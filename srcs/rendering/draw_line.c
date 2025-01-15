/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:23:25 by ymanchon          #+#    #+#             */
/*   Updated: 2025/01/15 18:19:22 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_put_line(t_layer *layer, t_pos a, t_pos b, t_color_type color)
{
	float	deltaX = b.x - a.x;
	float	deltaY = b.y - a.y;

	int		pixels = (int)sqrtf((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	float	pixelX = a.x;
	float	pixelY = a.y;
	while (pixels)
	{
		draw_pixel((int) pixelX, (int) pixelY, color, layer);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}

void	mlx_put_line2(t_layer *layer, t_posi a, t_posi b, t_color_type color)
{
	int	deltaX = b.x - a.x;
	int	deltaY = b.y - a.y;

	int		pixels = (int) sqrt((deltaX * deltaX) + (deltaY * deltaY));
	if (pixels == 0)
		return ;
	deltaX /= pixels;
	deltaY /= pixels;
	int	pixelX = a.x;
	int	pixelY = a.y;
	while (pixels)
	{
		draw_pixel(pixelX, pixelY, color, layer);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}
