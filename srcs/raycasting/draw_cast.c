/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:52:09 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/30 14:31:59 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline long	torch(int xy[], float length, long basecolor, t_core *core)
{
	float	val;
	float	j;
	size_t	i;
	size_t	g;

	g = 1;
	i = 101.0f;
	xy[1] -= core->half_height;
	val = sqrtf(xy[0] * xy[0] + xy[1] * xy[1]);
	if (val <= 100.0f + length)
		return (increase_lighting(basecolor, 100));
	else if (val <= 200.0f + length)
	{
		while (i <= 200)
		{
			j = (float)i + length;
			if (val > j - 1.0f && val <= j)
				return (increase_lighting(basecolor, 100 - g));
			++g;
			++i;
		}
	}
	return (basecolor);
}

void	draw_cf(
	int x,
	t_core *core)
{
	t_uint			y;
	t_uint			col;
	const uint32_t	chalfh = (core->imgs.cast->height / 2.0f);

	y = 0;
	while (y < core->imgs.cast->height)
	{
		if (y <= chalfh - core->player[LOCAL].offset)
			col = coltoui(core->map.cf_colors[C]);
		else if (y > chalfh - core->player[LOCAL].offset)
			col = coltoui(core->map.cf_colors[F]);
		*(core->layer[CAST_LAYER].pixels[y][x]) = col;
		++y;
	}
}

void	draw_col(int x, const float y1, float length, t_core *core)
{
	t_col	col;

	draw_col_init(&col, core, x, (float []){length, y1});
	draw_cf(x, core);
	while (col.i < (int)col.nb_pixels && col.y < core->layer[CAST_LAYER].height)
	{
		col.col = get_pixel(x, (float) col.i / col.nb_pixels, core);
		if (core->player[LOCAL].torch_activated)
			col.col = increase_lighting(torch((int []) \
			{col.torchx, col.y}, col.torchlength, col.col, core), -length * 15);
		else
			col.col = increase_lighting(col.col, -length * 17);
		*(core->layer[CAST_LAYER].pixels[col.y][x]) = col.col;
		++col.i;
		col.y++;
	}
}

void	draw_cast(t_core *core)
{
	uint32_t	i;
	float		y1;

	y1 = (float)(core->imgs.cast->height / 2.0f) \
	- core->player[LOCAL].offset - core->player[LOCAL].bubbles;
	i = 0;
	while (i < core->imgs.cast->width)
	{
		draw_col(i, y1, core->cast.casts[i], core);
		++i;
	}
}
