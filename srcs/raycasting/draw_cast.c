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
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < core->imgs.cast->height)
	{
		j = 0;
		while (j < core->imgs.cast->width)
		{
			draw_pixel(j, i, 0x00000000, &core->layer[CAST_LAYER]);
			j++;
		}
		i++;
	}
}

long	degrade(long color, float len)
{
	float	r;
	float	g;
	float	b;

	color = color % 0x01000000;
	r = ((color / 0x00010000) % 256);// - (int)(len / 10.f * 256.f);// * (int) (len / 10.f * 256.f);
	g = ((color / 0x00000100) % 256);// - (int)(len / 10.f * 256.f);// * (int) (len / 10.f * 256.f);
	b = ((color) % 256);// - (int)(len / 10.f * 256.f);// * (int) (len / 10.f * 256.f);
	r = len * r / 10;
	g = len * g / 10;
	b = len * b / 10;
	if (r < 0)
		r = 0;
	if (b < 0)
		b = 0;
	if (g == 0)
		g = 0;
	return ((0xff000000 + r * 0x00010000 + g * 0x00000100 + b * 0x00000001));//ase % 0xff000000 / 256) * (long)(length / 10.f * 256.f)
}

inline long	torch(int x, int y, float length, long basecolor, t_core *core)
{
	float	val;
	float	j;
	size_t	i;
	size_t	g;

	g = 1;
	i = 101.0f;
	y -= core->half_height;
	val = sqrtf(x * x + y * y);
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

long	get_pixel(int x, float y, t_core *core)
{
	t_pos	wall;
	float	angle;
	int		side;
	int		x_texture;
	int		y_texture;

	wall = core->cast.wall[x];
	angle = core->cast.angle[x];
	if (core->cast.side[x] == 0 && ((angle <= 90 && angle >= 0) || (angle <= 360 && angle >= 270)))
	{
		x_texture = (int) (core->cast.wallx[x] * TEXSIZE_ONE);
		y_texture = (int) (y * TEXSIZE_ONE);
		if (x_texture >= TEXSIZE)
			x_texture = TEXSIZE_ONE;
		if (x_texture < 0)
			x_texture = 0;
		if (y < 0)
			y = 0;
		side = EA;
	}
	else if (core->cast.side[x] == 0 && (angle < 270 && angle > 90))
	{
		side = WE;
		x_texture = (int) (core->cast.wallx[x] * TEXSIZE_ONE);
		y_texture = (int) (y * TEXSIZE_ONE);
		if (x_texture >= TEXSIZE)
			x_texture = TEXSIZE_ONE;
		if (x_texture < 0)
			x_texture = 0;
	}
	else if (core->cast.side[x] == 1 && (angle <= 180 && angle >= 0))
	{
		x_texture = (int) (core->cast.wallx[x] * TEXSIZE_ONE);
		y_texture = (int) (y * TEXSIZE_ONE);
		side = NO;
		if (x_texture >= TEXSIZE)
			x_texture = TEXSIZE_ONE;
		if (x_texture < 0)
			x_texture = 0;
	}
	else
	{
		side = SO;
		x_texture = (int) (core->cast.wallx[x] * TEXSIZE_ONE);
		y_texture = (int) (y * TEXSIZE_ONE);
		if (x_texture >= TEXSIZE)
			x_texture = TEXSIZE_ONE;
		if (x_texture < 0)
			x_texture = 0;
	}
	return (((unsigned int *)(core->xpms[side]->texture.pixels))[(y_texture * TEXSIZE) + x_texture]);
}

void	draw_col(int x, const float y1, float length, t_core *core)
{
	int				i;
	float			y;
	float			nb_pixels;
	long			col;
	const int		torchx = x - core->half_width;
	const float		torchlength = length * 50.0;
	float			half_nb_pixels;

	nb_pixels = core->half_height / (core->cast.wallDist[x] / 3.0f);
	half_nb_pixels = nb_pixels / 2.0f;
	i = 0;
	while (i < (int) nb_pixels)
	{
		y = y1 + ((float)i - half_nb_pixels);
		if (y < 0 || y > core->imgs.cast->height)
		{
			++i;
			continue ;
		}
		col = get_pixel(x, (float) i / nb_pixels, core);
		if (core->player[LOCAL].torch_activated)
			col = increase_lighting(torch(torchx, y, torchlength, col, core), -length * 13);
		else
			col = increase_lighting(col, -length * 15);
		draw_pixel(x, (int)y, col, &core->layer[CAST_LAYER]);
		++i;
	}
}

void	draw_cast(t_core *core)
{
	uint32_t	i;
	const float	y1 = (float)(core->imgs.cast->height / 2.0f) - core->player[LOCAL].offset - core->player[LOCAL].bubbles;

	i = 0;
	clear_img(core);
	while (i < core->imgs.cast->width)
	{
		draw_col(i, y1, core->cast.casts[i], core);
		++i;
	}
}
