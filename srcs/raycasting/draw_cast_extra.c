/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cast_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:04:13 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/30 14:10:03 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_col_init(t_col *init, t_core *core, int x, float floaa[2])
{
	init->nb_pixels = core->half_height / (core->cast.wallDist[x] / 3.0f);
	init->torchx = x - core->half_width;
	init->i = 0;
	init->torchlength = floaa[0] * 50.0;
	init->half_nb_pixels = init->nb_pixels / 2.0f;
	if (floaa[1] - init->half_nb_pixels < 0)
		init->i = (int)(init->half_nb_pixels - floaa[1]);
	init->y = (int)(floaa[1] - init->half_nb_pixels) + init->i;
}

int	get_side(int x, float y, t_core *core)
{
	(void)y;
	if (core->cast.side[x] == 0 && ((core->cast.angle[x] <= \
	90 && core->cast.angle[x] >= 0) || (core->cast.angle[x] \
	<= 360 && core->cast.angle[x] >= 270)))
		return (EA);
	else if (core->cast.side[x] == 0 && (core->cast.angle[x] \
	< 270 && core->cast.angle[x] > 90))
		return (WE);
	else if (core->cast.side[x] == 1 && (core->cast.angle[x] \
	<= 180 && core->cast.angle[x] >= 0))
		return (NO);
	else
		return (SO);
}

long	get_pixel(int x, float y, t_core *core)
{
	int		side;
	int		x_texture;
	int		y_texture;

	side = get_side(x, y, core);
	x_texture = (int)(core->cast.wallx[x] * TEXSIZE_ONE);
	y_texture = (int)(y * TEXSIZE_ONE);
	if (x_texture >= TEXSIZE)
		x_texture = TEXSIZE_ONE;
	if (x_texture < 0)
		x_texture = 0;
	return (((unsigned int *)(core->xpms[side]->texture.pixels)) \
	[(y_texture * TEXSIZE) + x_texture]);
}
