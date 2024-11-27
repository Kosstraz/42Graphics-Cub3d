	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:52:09 by mkhoury           #+#    #+#             */
/*   Updated: 2024/11/27 15:49:52 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_img(t_core *core)
{
	int	i;
	int	j;

	i = 0;
	while (i < core->mlx->height)
	{
		j = 0;
		while (j < core->mlx->width)
		{
			//mlx_put_pixel(core->imgs.cast, j, i, 0x00111111);
			draw_pixel(j, i, 0x00111111, &core->layer[CAST_LAYER]);
			j++;
		}
		i++;
	}
}

void	draw_col(int x, float length, t_core *core)
{
	int	i;
	float	y;
	float	nb_pixels;
	long	col;
	long	dark;

	nb_pixels = 1000 / (length / 2);
	col = 0x11ff0000 - 0x11111111 * (long)(length / 5);
	//printf("%f %i\n", nb_pixels, (int) nb_pixels);
	i = 0;
	while (i < (int)nb_pixels)
	{
		y = 400.f + ((float) i - nb_pixels / 2.f);
		draw_pixel(x, (int)y, col, &core->layer[CAST_LAYER]);
		i++;
	}
}

void	draw_cast(t_core *core)
{
	int	i;

	i = 0;
	clear_img(core);
	while (i < core->mlx->width)
	{
		draw_col(i, core->cast.casts[i], core);
		i++;
	}
}
