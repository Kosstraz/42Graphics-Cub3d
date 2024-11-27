/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:58:34 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/27 15:53:59 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline void	init_layer(mlx_image_t *img, t_layer *layer)
{
	int			precalcul;
	uint32_t	y;
	uint32_t	x;

	y = 0;
	if (layer->pixels)
		ft_dfree((void **)layer->pixels);
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

// 1 --> same
// 0 --> not same
inline char	cmppixel(
	uint32_t x,
	uint32_t y,
	t_color_type color,
	t_layer *layer)
{
	if (y < layer->height && x < layer->width)
		return (*(layer->pixels)[y][x] == color);
}

inline void	draw_pixel(uint32_t x,
	uint32_t y,
	t_color_type color,
	t_layer *layer)
{
	if (y < layer->height && x < layer->width)
		*(layer->pixels)[y][x] = color;
}
