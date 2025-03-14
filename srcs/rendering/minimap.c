/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:43:52 by ymanchon          #+#    #+#             */
/*   Updated: 2024/12/07 17:12:25 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline static void	draw_ascii_on_minimap(
	t_color_type coltype,
	size_t xoffset,
	size_t yoffset,
	t_core *core)
{
	size_t	i;
	size_t	j;
	size_t	y;

	i = 0;
	while (i < DEFUNIT)
	{
		j = 0;
		y = i + yoffset;
		while (j < DEFUNIT)
		{
			draw_pixel(j + xoffset, y, coltype, &core->layer[MINIMAP_LAYER]);
			++j;
		}
		++i;
	}
}

inline static void	draw_ascii_branch(size_t x, size_t y, t_core *core)
{
	if (x < core->map.buflens[y])
	{
		if (core->map.buf[y][x] == CUB3D_WALL)
			draw_ascii_on_minimap(Wall, x * DEFUNIT, y * DEFUNIT, core);
		else if (core->map.buf[y][x] == ' ')
			draw_ascii_on_minimap(Transparent, x * DEFUNIT, y * DEFUNIT, core);
		else if (core->map.buf[y][x] == 'P' && doors_check_state(x, y, core) < 0)
			draw_ascii_on_minimap(Door, x * DEFUNIT, y * DEFUNIT, core);
		else
			draw_ascii_on_minimap(Void, x * DEFUNIT, y * DEFUNIT, core);
	}
	else
		draw_ascii_on_minimap(Transparent, x * DEFUNIT, y * DEFUNIT, core);
}

inline static void	draw_player(
	t_player *player, t_color_type color, t_core *core)
{
	t_pos	mult;
	t_pos	top;
	t_pos	left;
	t_pos	right;

	mult.x = player->position.x * DEFUNIT;
	mult.y = player->position.y * DEFUNIT;
	top.x = mult.x + DEFHALFUNIT;
	top.y = mult.y;
	left.x = mult.x;
	left.y = mult.y + DEFUNIT - 1;
	right.x = mult.x + DEFUNIT;
	right.y = mult.y + DEFUNIT - 1;
	draw_square(&core->layer[MINIMAP_LAYER], mult, color);
}

void	draw_minimap(t_core *core)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < core->map.bufmax)
	{
		x = 0;
		while (x < core->map.buflens_max)
			draw_ascii_branch(x++, y, core);
		++y;
	}

	orientation_minimap(core);	
	if (core->network.is_active)
		draw_player(&core->player[DISTANT], Green, core);
	draw_player(&core->player[LOCAL], Blue, core);
}
