/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:32:18 by mkhoury           #+#    #+#             */
/*   Updated: 2025/02/05 14:39:50 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// sc_angle.x --> sin
// sc_angle.y --> cos
void	draw_square(
	t_layer *layer,
	t_player *player,
	t_color_type color)
{
	t_cmpt		cmpt;
	t_fvector	pos;
	const float	diam = DEFHALFUNIT - 1;
	const float	angle = player->view.angle;
	t_fvector	sc_angle;

	sc_angle.x = sinf(deg2rad(angle));
	sc_angle.y = cosf(deg2rad(angle));
	cmpt.i = -diam;
	pos.x = player->position.x * DEFUNIT;
	pos.y = player->position.y * DEFUNIT;
	while (cmpt.i < diam)
	{
		cmpt.j = -diam;
		while (cmpt.j < diam)
		{
			pos.x = cmpt.i * sc_angle.y - cmpt.j * sc_angle.x
				+ (player->position.x * DEFUNIT);
			pos.y = cmpt.i * sc_angle.x + cmpt.j * sc_angle.y
				+ (player->position.y * DEFUNIT);
			draw_pixel(pos.x, pos.y, color, layer);
			++cmpt.j;
		}
		++cmpt.i;
	}
}
