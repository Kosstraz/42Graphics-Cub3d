/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:46:55 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/29 15:18:32 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	same_cast(t_casting cast, t_player player)
{
	if (cast.last_pose.x != player.position.x || \
		cast.last_pose.y != player.position.y || \
		cast.last_pose.z != player.position.z || \
		cast.last_view.dx != player.view.dx || \
		cast.last_view.dy != player.view.dy || \
		cast.last_view.dz != player.view.dz || \
		cast.last_view.angle != player.view.angle)
		return (false);
	return (true);
}

void	save_cast(t_casting *cast, t_player player, int width)
{
	cast->last_pose.x = player.position.x;
	cast->last_pose.y = player.position.y;
	cast->last_pose.z = player.position.z;
	cast->last_view.dx = player.view.dx;
	cast->last_view.dy = player.view.dy;
	cast->last_view.dz = player.view.dz;
	cast->last_view.angle = player.view.angle;
	cast->last_width = width;
}

void	calcul_casts(t_core *core)
{
	t_uint		i;
	t_pos		start;
	float		y1;

	y1 = (float)(core->imgs.cast->height / 2.0f) \
	- core->player[LOCAL].offset - core->player[LOCAL].bubbles;
	core->cast.last_width = core->mlx->width;
	core->cast.di = (float) FOV / (float) core->cast.last_width;
	i = 0U;
	start.x = core->player[LOCAL].position.x * DEFUNIT;
	start.y = core->player[LOCAL].position.y * DEFUNIT;
	while (i < core->imgs.cast->width)
	{
		core->cast.angle[i] = core->player[LOCAL].view.angle \
		- (float) core->cast.hfov + core->cast.di * (float) i;
		if (core->cast.angle[i] < 0)
			core->cast.angle[i] = 360.0f + core->cast.angle[i];
		if (core->cast.angle[i] > 360.0f)
			core->cast.angle[i] -= 360.0f;
		core->cast.casts[i] = ray_cast(core, core->cast.angle[i], i);
		orientation_minimap(i, start, core);
		draw_col(i, y1, core->cast.casts[i], core);
		++i;
	}
}
