/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:58:34 by ymanchon          #+#    #+#             */
/*   Updated: 2025/02/12 15:42:03 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline void	free_layer(t_layer *layer)
{
	int	y;

	if (layer->pixels)
	{
		y = 0;
		while (layer->pixels[y])
			free(layer->pixels[y++]);
		free(layer->pixels);
	}
}

inline void	init_layer(mlx_image_t *img, t_layer *layer, t_core *core)
{
	int			precalcul;
	uint32_t	y;
	uint32_t	x;

	y = 0;
	free_layer(layer);
	layer->pixels = (uint32_t ***)ft_malloc(sizeof(uint32_t **)
			* (img->height + 1), core);
	while (y < img->height)
	{
		layer->pixels[y]
			= (uint32_t **)ft_malloc(sizeof(uint32_t *) * img->width, core);
		x = 0;
		precalcul = y * img->width;
		while (x < img->width)
		{
			layer->pixels[y][x]
				= (uint32_t *)&img->pixels[(precalcul + x) * sizeof(int32_t)];
			++x;
		}
		++y;
	}
	layer->pixels[y] = NULL;
	layer->height = img->height;
	layer->width = img->width;
}

// 1	--> same
// 0	--> not same
// -1	--> out of bounds
inline char	cmppixel(
	uint32_t x,
	uint32_t y,
	t_color_type color,
	t_layer *layer)
{
	return (*(layer->pixels[y][x]) == color);
}

// y >= 0U && 
// x >= 0U && 
inline int	draw_pixel(uint32_t x,
	uint32_t y,
	t_color_type color,
	t_layer *layer)
{
	if (y < layer->height && x < layer->width)
	{
		*(layer->pixels[y][x]) = color;
		return (true);
	}
	return (false);
}

void	fill_layer(t_layer *layer, t_color_type color)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < layer->height)
	{
		x = 0;
		while (x < layer->width)
		{
			draw_pixel(x, y, color, layer);
			++x;
		}
		++y;
	}
}
