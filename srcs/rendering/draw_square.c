/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:32:18 by mkhoury           #+#    #+#             */
/*   Updated: 2024/12/10 18:42:01 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(t_layer *layer, t_player *player, t_color_type color, t_core *core)
{
	int			i;
	int			j;
	float		x;
	float		y;	
	const float	diam = DEFHALFUNIT - 1;
	const float angle = player->view.angle;
	const float	sinAngle = sinf(deg2rad(angle));
	const float	cosAngle = cosf(deg2rad(angle));

	i = -diam;
	x = player->position.x * DEFUNIT;
	y = player->position.y * DEFUNIT;
	while (i < diam)
	{
		j = -diam;
		while (j < diam)
		{
			x = i * cosAngle - j * sinAngle + (player->position.x * DEFUNIT);
			y = i * sinAngle + j * cosAngle + (player->position.y * DEFUNIT);
			draw_pixel(x, y, color, layer);
			++j;
		}
		++i;
	}
}
