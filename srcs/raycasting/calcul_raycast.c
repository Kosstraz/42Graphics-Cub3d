/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:46:55 by mkhoury           #+#    #+#             */
/*   Updated: 2024/11/27 14:59:57 by mkhoury          ###   ########.fr       */
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
	int		i;

	// if (same_cast(core->cast, core->player) == true && core->cast.last_width == core->mlx->width)
	// 	return ;
	if (core->cast.last_width != core->mlx->width || core->cast.di == -1)
	{
		core->cast.last_width = core->mlx->width;
		core->cast.di = (float) FOV / (float) core->cast.last_width;
	}
	i = 0;
	while (i < core->mlx->width)
	{
		core->cast.angle[i] = core->player.view.angle - (float) core->cast.hfov + core->cast.di * (float) i;
		core->cast.casts[i] = ray_cast(core, core->cast.angle[i]);
		i++;
	}
	save_cast(&core->cast, core->player, core->mlx->width);
}
