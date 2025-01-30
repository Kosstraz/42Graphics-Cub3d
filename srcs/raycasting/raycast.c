/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:19:35 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/29 17:00:01 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_t2(t_raycast *cast)
{
	if (cast->vector_dir.y < 0)
	{
		cast->step.y = -1;
		cast->side.y = (cast->ray_start.y - \
		(float) cast->map_check.y) * cast->unit.y;
	}
	else
	{
		cast->step.y = 1;
		cast->side.y = ((float)(cast->map_check.y + 1) \
		- cast->ray_start.y) * cast->unit.y;
	}
}

void	ini_t(t_raycast *cast, t_core *core, float angle)
{
	ft_memset(&cast->vector_dir, 0, sizeof(t_fvector));
	ft_memset(&cast->map_check, 0, sizeof(t_ivector));
	cast->ray_start.x = core->player[LOCAL].position.x;
	cast->ray_start.y = core->player[LOCAL].position.y;
	cast->map_check.x = (int) cast->ray_start.x;
	cast->map_check.y = (int) cast->ray_start.y;
	cast->vector_dir.x = cosf(deg2rad(angle));
	cast->vector_dir.y = sinf(deg2rad(angle));
	cast->unit.x = sqrtf(1.f + (cast->vector_dir.y / \
	cast->vector_dir.x) * (cast->vector_dir.y / cast->vector_dir.x));
	cast->unit.y = sqrtf(1.f + (cast->vector_dir.x / \
	cast->vector_dir.y) * (cast->vector_dir.x / cast->vector_dir.y));
	if (cast->vector_dir.x < 0)
	{
		cast->step.x = -1;
		cast->side.x = (cast->ray_start.x - (float) \
		cast->map_check.x) * cast->unit.x;
	}
	else
	{
		cast->step.x = 1;
		cast->side.x = ((float)(cast->map_check.x + 1) \
		- cast->ray_start.x) * cast->unit.x;
	}
	init_t2(cast);
}

void	while_boucle(t_raycast *cast, t_core *core)
{
	while (1)
	{
		if (cast->side.x < cast->side.y)
		{
			cast->map_check.x += cast->step.x;
			cast->distance = cast->side.x;
			cast->side.x += cast->unit.x;
			cast->side_int = 0;
		}	
		else
		{
			cast->map_check.y += cast->step.y;
			cast->distance = cast->side.y;
			cast->side.y += cast->unit.y;
			cast->side_int = 1;
		}
		if (checker_end_while(core, cast) == true)
			break ;
	}
}

float	ray_cast(t_core *core, float angle, int i)
{
	t_raycast	cast;

	ini_t(&cast, core, angle);
	while_boucle(&cast, core);
	if (cast.side_int == 0)
		cast.walldist = cast.side.x - cast.side.y;
	else
		cast.walldist = cast.side.y - cast.side.x;
	core->cast.height[i] = core->mlx->height / cast.walldist;
	core->cast.wallDist[i] = cosf(deg2rad(angle - \
	core->player->view.angle)) * (cast.distance);
	if (cast.side_int == 0)
		cast.WallX = sin(deg2rad(angle)) * cast.distance + cast.ray_start.y;
	else
		cast.WallX = cos(deg2rad(angle)) * cast.distance + cast.ray_start.x;
	cast.WallX -= (int) cast.WallX;
	core->cast.wallx[i] = cast.WallX;
	core->cast.wall[i].x = cast.map_check.x;
	core->cast.wall[i].y = cast.map_check.y;
	core->cast.wall[i].z = 1.f;
	if (cast.side_int == 1)
		core->cast.side[i] = 1;
	else
		core->cast.side[i] = 0;
	return (cast.distance);
}
