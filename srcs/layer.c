/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:58:34 by ymanchon          #+#    #+#             */
/*   Updated: 2024/12/03 17:16:20 by mkhoury          ###   ########.fr       */
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

inline void	init_layer(mlx_image_t *img, t_layer *layer)
{
	int			precalcul;
	uint32_t	y;
	uint32_t	x;

	y = 0;
	free_layer(layer);
	layer->pixels
		= (uint32_t ***)malloc(sizeof(uint32_t **) * (img->height + 1));
	while (y < img->height)
	{
		layer->pixels[y]
			= (uint32_t **)malloc(sizeof(uint32_t *) * img->width);
		x = 0;
		precalcul = y * img->width;
		while (x < img->width)
		{
			layer->pixels[y][x] = (uint32_t *)&img->pixels[(precalcul + x) * BPP];
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
	//if ((y >= 0 && y < layer->height) && (x >= 0 && x < layer->width))
	return (*(layer->pixels[y][x]) == color);
}

inline int	draw_pixel(uint32_t x,
	uint32_t y,
	t_color_type color,
	t_layer *layer)
{
	if ((y >= 0 && y < layer->height) && (x >= 0 && x < layer->width))
	{
		*(layer->pixels[y][x]) = (uint32_t)color;
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
