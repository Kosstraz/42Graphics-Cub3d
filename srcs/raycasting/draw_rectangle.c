/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:05:35 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/29 13:46:36 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rectangle(long distance, int x, t_core *core)
{
	int	i;
	int	j;
	int	nb_pixel;

	i = 0;
	
	while (i < 20)
	{
		j = 0;
		while ( j < 10)
		{
			draw_pixel(x - 10 + i, j + (core->imgs.cast->height / 2.f) - core->player[LOCAL].offset + nb_pixel, distance, &core->layer[CAST_LAYER]);
			j++;
		}
		
		i++;
	}
	
}

void	draw_rectangle2(int x, int y, long color, t_core *core)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			if (i >= 0 && i <= core->layer[CAST_LAYER].height && j >= 0 && j <= core->layer[CAST_LAYER].width)
				draw_pixel(x - 10 + j, y + i - 10, color, &core->layer[CAST_LAYER]);
			j++;
		}
		i++;
	}
	
}

unsigned int	get_color(float x, float y, mlx_texture_t *texture, int side)
{
	int	yt;
	int	xt;

	yt = (int) (y * 24.f) * 32;
	xt = (int) (x * 8.f);
	return ((((unsigned int *)(texture->pixels)))[yt + xt + side * 8]);
}

void	draw_col2(int x, int side, float len[2], t_core *core)
{
	int		i;
	int		nb;
	int		y;
	unsigned int	color;
	
	i = 0;
	nb = (int)(core->imgs.cast->height / len[0]);
	y = (int) ((core->imgs.cast->height / 2.f) - core->player[LOCAL].offset - core->player[LOCAL].bubbles + core->player[DISTANT].bubbles) - nb / 2 + (int) (core->imgs.cast->height / 6.f / len[0]);
	while (i < nb)
	{
		color = get_color(len[1], (float) i / nb, core->texturej, side);
		draw_pixel(x, y, color, &core->layer[CAST_LAYER]);
		y++;
		i++;
	}
}

void	draw_rectangle3(int pos[3], float length[2], int side, t_core *core)
{
	float	dl;
	int		i;
	int		nb;
	
	nb = abs(pos[0] - pos[1]);
	dl = (length[0] - length[1]) / (float) nb;
	i = 0;
	while (i < nb)
	{
		if (core->cast.casts[pos[1]] >= length[1])
		{
			draw_col2(pos[1], side, (float []){length[1], (float) i / nb}, core);
			core->cast.casts[pos[1]] = length[1];
		}
		length[1] = length[1] + dl;
		pos[1]++;
		i++;
	}
}
