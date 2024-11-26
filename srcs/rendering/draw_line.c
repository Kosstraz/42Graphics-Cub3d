/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:23:25 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/26 15:42:04 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_put_line(mlx_image_t *image, t_pos a, t_pos b, t_color_type color)
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
		if (pixelX < image->width && pixelY < image->height)
		{
			mlx_put_pixel(image, pixelX, pixelY, color);
			pixelX += deltaX;
			pixelY += deltaY;
			--pixels;
		}
	}
}
