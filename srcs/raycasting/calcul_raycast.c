/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:46:55 by mkhoury           #+#    #+#             */
/*   Updated: 2024/12/10 17:37:27 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	same_cast(t_casting cast, t_player player)
{
	if (cast.last_pose.x != player.position.x ||\
		cast.last_pose.y != player.position.y ||\
		cast.last_pose.z != player.position.z ||\
		cast.last_view.dx != player.view.dx ||\
		cast.last_view.dy != player.view.dy ||\
		cast.last_view.dz != player.view.dz ||\
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
	t_uint	i;
	t_pos	start;
	float	max;
	float	min;

	if (core->cast.last_width != core->mlx->width || core->cast.di == -1)
	{
		core->cast.last_width = core->mlx->width;
		core->cast.di = (float) FOV / (float) core->cast.last_width;
	}
	i = 0U;
	min = 43.0f;
	max = 0.0f;
	clear_img(core);
	start.x = core->player[LOCAL].position.x * DEFUNIT;
	start.y = core->player[LOCAL].position.y * DEFUNIT;
	const float	y1 = (float)(core->imgs.cast->height / 2.0f) - core->player[LOCAL].offset - core->player[LOCAL].bubbles;
	while (i < core->imgs.cast->width)
	{
		core->cast.angle[i] = core->player[LOCAL].view.angle - (float) core->cast.hfov + core->cast.di * (float) i;
		if (core->cast.angle[i] < 0)
			core->cast.angle[i] = 360.0f + core->cast.angle[i];
		if (core->cast.angle[i] > 360.0f)
			core->cast.angle[i] -= 360.0f;
		core->cast.casts[i] = ray_cast(core, core->cast.angle[i], i);
		if (min > core->cast.casts[i])
			min = core->cast.casts[i];
		if (max < core->cast.casts[i])
			max = core->cast.casts[i];
		orientation_minimap(i, start, core);
		draw_col(i, y1, core->cast.casts[i], core);
		++i;
		
	}
	core->cast.max = max;
	core->cast.min = min;
	save_cast(&core->cast, core->player[LOCAL], core->mlx->width);
}
