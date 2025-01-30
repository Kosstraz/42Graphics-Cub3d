/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:23:25 by ymanchon          #+#    #+#             */
/*   Updated: 2025/01/27 19:03:16 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_put_line(t_layer *layer, t_pos a, t_pos b, t_color_type color)
{
	t_fvector	delta;
	t_fvector	pixel;
	int			pixels;

	delta.x = b.x - a.x;
	delta.y = b.y - a.y;
	pixels = (int)sqrtf((delta.x * delta.x) + (delta.y * delta.y));
	delta.x /= pixels;
	delta.y /= pixels;
	pixel.x = a.x;
	pixel.y = a.y;
	while (pixels)
	{
		draw_pixel(pixel.x, pixel.y, color, layer);
		pixel.x += delta.x;
		pixel.y += delta.y;
		--pixels;
	}
}
