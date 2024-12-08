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

long	get_pixel(int x, float y, t_core *core, float length)
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
	// if (core->cast.side[x] == 0 && ((angle <= 90 && angle >= 0) || (angle <=360 && angle >= 270)))
	// {
	// 	y = y * core->xpms[EA]->texture.height;
	// 	side = EA;
	// 	//printf("x %f y %f\n",x_texture, y);
	// 	return (core->xpms[EA]->texture.pixels[(int) (y) + (int) core->cast.wallx[x]]);
	// }
	// else if (core->cast.side[x] == 0 && (angle < 270 && angle > 90))
	// {
	// //	x_texture = (sinf(deg2rad(core->cast.angle[x])) + core->player[LOCAL].position.y - (int)(core->player[LOCAL].position.y)) * core->xpms[WE]->texture.width;
	// 	y = y * core->xpms[WE]->texture.height;
	// 	side = WE;
	// 	//printf("x %f y %f\n",x_texture, y);
	// 	return (core->xpms[WE]->texture.pixels[(int) (y) + (int) x_texture]);
	// }
	// else if (core->cast.side[x] == 1 && (angle <= 180 && angle >= 0))
	// {
	// //	x_texture = (cos(deg2rad(core->cast.angle[x])) + core->player[LOCAL].position.x - (int)(core->player[LOCAL].position.x)) * core->xpms[NO]->texture.width;
	// 	y = y * core->xpms[NO]->texture.height;
	// 	side = NO;
	// 	//printf("x %f y %f\n",x_texture, y);
	// 	return (core->xpms[NO]->texture.pixels[(int) (y) + (int) x_texture]);
	// }
	// else
	// {
	// //	x_texture = (cos(deg2rad(core->cast.angle[x])) + core->player[LOCAL].position.x - (int)(core->player[LOCAL].position.x)) * core->xpms[SO]->texture.width;
	// 	y = y * core->xpms[SO]->texture.height;
	// 	side = SO;
	// 	//printf("x %f y %f\n",x_texture, y);
	// 	return (core->xpms[SO]->texture.pixels[(int) (y) + (int) x_texture]);
	// }
	//core->xpms[EA]->texture.
	// if ((int)(core->cast.wallx[x] * 256.f) == 0)
	// 	return (0xffffffff);
	// if (core->cast.side[x] == 0 && ((angle <= 90 && angle >= 0) || (angle <=360 && angle >= 270)))
	// 	base = 0xffff0000 - 0x00010000 * (long) (core->cast.wallx[x] * 256.f);//(long)(length / 10.f * 256.f);
	// else if (core->cast.side[x] == 0 && (angle < 270 && angle > 90))
	// 	base = 0xff00ff00 - 0x00000100 * (core->cast.wallx[x] * 256.f);//(long)(length / 10.f * 256.f);
	// else if (core->cast.side[x] == 1 && (angle <= 180 && angle >= 0))
	// 	base = 0xff0000ff - 0x00000001 * (long) (core->cast.wallx[x] * 256.f);//(long)(length / 10.f * 256.f);
	// else
	// 	base = 0xffffffff - 0x00010101 * (long) (core->cast.wallx[x] * 256.f);//(long)(length / 10.f * 256.f);
	// //base = (long) core->xpms[side].
	// //printf("angle is : %f side is : %i color is %ld\n",angle, core->cast.side[x], base);

	if (core->cast.side[x] == 0 && ((angle <= 90 && angle >= 0) || (angle <=360 && angle >= 270)))
	{
		//(sinf(deg2rad(core->cast.angle[x])) + core->player[LOCAL].position.y - (int)(core->player[LOCAL].position.y)) * core->xpms[EA]->texture.width;
		x_texture = (int) (core->cast.wallx[x] * 63.f);
		y_texture = (int) (y * 63.f);
		if (x_texture >= 64)
			x_texture = 63;
		if (x_texture < 0)
			x_texture = 0;
		//if (y_texture >= 64)
		//	y_texture = 63;
		if (y < 0)
			y = 0;
		side = EA;
		//printf("x %f y %f\n",x_texture, y);
		//return (core->xpms[EA]->texture.pixels[y_texture + x_texture]);
		//return (((unsigned int*)&core->xpms[side]->texture.pixels)[y_texture * 64 + x_texture]);
	}
	else if (core->cast.side[x] == 0 && (angle < 270 && angle > 90))
	{
	//	x_texture = (sinf(deg2rad(core->cast.angle[x])) + core->player[LOCAL].position.y - (int)(core->player[LOCAL].position.y)) * core->xpms[WE]->texture.width;
		//y = y * core->xpms[WE]->texture.height;
		side = WE;
		x_texture = (int) (core->cast.wallx[x] * 63.f);
		y_texture = (int) (y * 63.f);
		if (x_texture >= 64)
			x_texture = 63;
		if (x_texture < 0)
			x_texture = 0;
		//if (y_texture >= 64)
		//	y_texture = 63;
		//printf("x %f y %f\n",x_texture, y);
		//return (core->xpms[WE]->texture.pixels[y_texture + x_texture]);
		//return (((unsigned int*)&core->xpms[side]->texture.pixels)[y_texture * 64 + x_texture]);
	}
	else if (core->cast.side[x] == 1 && (angle <= 180 && angle >= 0))
	{
	//	x_texture = (cos(deg2rad(core->cast.angle[x])) + core->player[LOCAL].position.x - (int)(core->player[LOCAL].position.x)) * core->xpms[NO]->texture.width;
		//y = y * core->xpms[NO]->texture.height;
		x_texture = (int) (core->cast.wallx[x] * 63.f);
		y_texture = (int) (y * 63.f);
		side = NO;
		if (x_texture >= 64)
			x_texture = 63;
		if (x_texture < 0)
			x_texture = 0;

		//if (y_texture >= 64)
		//	y_texture = 63;
		//printf("x %f y %f\n",x_texture, y);
		//return (core->xpms[NO]->texture.pixels[y_texture + x_texture]);
		//return (((unsigned int*)&core->xpms[side]->texture.pixels)[y_texture * 64 + x_texture]);
	}
	else
	{
	//	x_texture = (cos(deg2rad(core->cast.angle[x])) + core->player[LOCAL].position.x - (int)(core->player[LOCAL].position.x)) * core->xpms[SO]->texture.width;
		// y = y * core->xpms[SO]->texture.height;
		side = SO;
		x_texture = (int) (core->cast.wallx[x] * 63.f);
		y_texture = (int) (y * 63.f);
		if (x_texture >= 64)
			x_texture = 63;
		if (x_texture < 0)
			x_texture = 0;
		//if (y_texture >= 64)
		//	y_texture = 63;
		//printf("x %f y %f\n",x_texture, y);
		
	}
	// //printf("x : %i y: %i side %i\n", core->cast.wallx[x], x_texture, y_texture, side);
	// //if (x == 1 && y >= 0.9f)
	// //	printf("%x\n", core->xpms[side]->texture.pixels[y_texture * 64 + x_texture]);
	// return (((unsigned int*)&core->xpms[side]->texture.pixels)[y_texture * 64 + x_texture]);
	//if (y_texture == 63)
	//	return (0xff000000);
	// if (x_texture > 40)
	// 	y_texture++; 
	return (((unsigned int *)(core->xpms[side]->texture.pixels))[(y_texture * 64) + x_texture]);//(((unsigned int*)core->xpms)[side]->texture.pixels)[(y_texture * 64) + x_texture]);
	return (base );//+ degrade(base, length));
}

void	draw_col(int x, float length, t_core *core)
{
	int		i;
	float	y;
	float	nb_pixels;
	long	col;
	//long	degrade;

	//nb_pixels = core->half_height * 2.f / (length) ;//+ core->cast.wallDist[x];
	nb_pixels = core->half_height / (core->cast.wallDist[x] / 3.f);
	//if (length > 10.f)
	//	return ;
	i = 0;
	while (i < (int) nb_pixels)
	{
		col = 0xff000000 + get_pixel(x, (float) i / nb_pixels, core, length);// - 0x00010101 * (long)(length / 10.f * 256.f);
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
