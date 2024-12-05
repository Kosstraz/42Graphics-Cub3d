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

long	get_pixel(int x, int y, t_core *core, float length)
{
	long	base;
	t_pos	wall;
	float	angle;
	int		side;

	wall.x = core->cast.wall[x].x;
	wall.y = core->cast.wall[x].y;
	wall.z = core->cast.wall[x].z;
	angle = core->cast.angle[x];
	if (core->cast.side[x] == 0 && ((angle <= 90 && angle >= 0) || (angle <=360 && angle >= 270)))
	{
		return (core->xpms[EA])
	}
		side = EA;
	else if (core->cast.side[x] == 0 && (angle < 270 && angle > 90))
		side = WE;
	else if (core->cast.side[x] == 1 && (angle <= 180 && angle >= 0))
		side = NO;
	else
		side = SO;
	
	// if (core->cast.side[x] == 0 && ((angle <= 90 && angle >= 0) || (angle <=360 && angle >= 270)))
	// 	base = 0xffff0000 - 0x00010000 * (long)(length / 10.f * 256.f);
	// else if (core->cast.side[x] == 0 && (angle < 270 && angle > 90))
	// 	base = 0xff00ff00 - 0x00000100 * (long)(length / 10.f * 256.f);
	// else if (core->cast.side[x] == 1 && (angle <= 180 && angle >= 0))
	// 	base = 0xff0000ff - 0x00010001 * (long)(length / 10.f * 256.f);
	// else
	// 	base = 0xffffffff - 0x00010101 * (long)(length / 10.f * 256.f);
	//base = (long) core->xpms[side].
	//printf("angle is : %f side is : %i color is %ld\n",angle, core->cast.side[x], base);
	return (base);
}

void	draw_col(int x, float length, t_core *core)
{
	int		i;
	float	y;
	float	nb_pixels;
	long	col;
	long	degrade;

	nb_pixels = core->half_height * 2.f / (length);
	if (length > 10.f)
		return ;
	i = 0;
	while (i < (int) nb_pixels)
	{
		col = get_pixel(x, i, core, length);// - 0x00010101 * (long)(length / 10.f * 256.f);
		y = (float) (core->imgs.cast->height / 2.f) - core->player[LOCAL].offset + ((float) i - nb_pixels / 2.f);
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
