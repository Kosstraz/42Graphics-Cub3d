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
			draw_pixel(j, i, 0x00111111, &core->layer[CAST_LAYER]);
			j++;
		}
		i++;
	}
}

// void	draw_col(int x, float length, t_core *core)
// {
// 	int		i;
// 	float	y;
// 	float	nb_pixels;
// 	long	col;

// 	nb_pixels = core->half_height * 2.f / (length);
// 	if (length > 10.f)
// 		return ;
// 	else
// 		col = 0xff000000 - 0x00010101 * (long)(length / 10.f * 256.f);
// 	i = 0;
// 	while (i < (int) nb_pixels)
// 	{
// 		y = (float) (core->imgs.cast->height / 2.f) - core->player[LOCAL].offset + ((float) i - nb_pixels / 2.f);
// 		draw_pixel(x, (int)y, col, &core->layer[CAST_LAYER]);
// 		++i;
// 	}
// }

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
	if (g = 0)
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

long	get_pixel(int x, float y, int torchx, int torchy, float torchlength, t_core *core, float length)
{
	long	base;
	t_pos	wall;
	float	angle;
	int		side;
	int	x_texture;
	int		y_texture;

	(void)y;
	wall.x = core->cast.wall[x].x;
	wall.y = core->cast.wall[x].y;
	wall.z = core->cast.wall[x].z;
	angle = core->cast.angle[x];
	if (core->cast.side[x] == 0 && ((angle <= 90 && angle >= 0) || (angle <=360 && angle >= 270)))
	{
		x_texture = (int) (core->cast.wallx[x] * 63.f);
		y_texture = (int) (y * 63.f);
		if (x_texture >= 64)
			x_texture = 63;
		if (x_texture < 0)
			x_texture = 0;
		if (y < 0)
			y = 0;
		side = EA;
	}
	else if (core->cast.side[x] == 0 && (angle < 270 && angle > 90))
	{
		side = WE;
		x_texture = (int) (core->cast.wallx[x] * 63.f);
		y_texture = (int) (y * 63.f);
		if (x_texture >= 64)
			x_texture = 63;
		if (x_texture < 0)
			x_texture = 0;
	}
	else if (core->cast.side[x] == 1 && (angle <= 180 && angle >= 0))
	{
		x_texture = (int) (core->cast.wallx[x] * 63.f);
		y_texture = (int) (y * 63.f);
		side = NO;
		if (x_texture >= 64)
			x_texture = 63;
		if (x_texture < 0)
			x_texture = 0;
	}
	else
	{
		side = SO;
		x_texture = (int) (core->cast.wallx[x] * 63.f);
		y_texture = (int) (y * 63.f);
		if (x_texture >= 64)
			x_texture = 63;
		if (x_texture < 0)
			x_texture = 0;
		
	}
	long	color = ((unsigned int *)(core->xpms[side]->texture.pixels))[(y_texture * 64) + x_texture];
	color = decrease_lighting(color, (int)(length / 10.f * 255.f));
	if (core->player[LOCAL].torch_activated)
		return (torch(torchx, torchy, torchlength, color, core));
	else
		return (color);
}

void	draw_col(int x, float length, t_core *core)
{
	int		i;
	float	y;
	float	nb_pixels;
	int		torchx;
	float	torchlength;
	long	col;
	//long	degrade;

	//nb_pixels = core->half_height * 2.f / (length) ;//+ core->cast.wallDist[x];
	nb_pixels = core->half_height / (core->cast.wallDist[x] / 3.f);
	//if (length > 10.f)
	//	return ;
	torchlength = length * 50.0f;
	torchx = x - core->half_width;
	i = 0;
	while (i < (int) nb_pixels)
	{
		y = (float) (core->imgs.cast->height / 2.f) - core->player[LOCAL].offset - core->player[LOCAL].bubbles + ((float) i - nb_pixels / 2.f);
		col = 0xff000000 + get_pixel(x, (float) i / nb_pixels, torchx, y, torchlength, core, length);// - 0x00010101 * (long)(length / 10.f * 256.f);
		draw_pixel(x, (int)y, col, &core->layer[CAST_LAYER]);
		++i;
	}
}

void	draw_cast(t_core *core)
{
	uint32_t	i;

	i = 0;
	while (i < core->imgs.cast->width)
	{
		draw_col(i, core->cast.casts[i], core);
		i++;
	}
}
