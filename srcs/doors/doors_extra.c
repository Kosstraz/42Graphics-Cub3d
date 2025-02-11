/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:17:00 by ymanchon          #+#    #+#             */
/*   Updated: 2025/02/11 17:17:42 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_door2(t_raycast *cast)
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

void	ini_door(t_raycast *cast, t_core *core, float angle)
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
	init_door2(cast);
}

void	door_raycast(t_core *core)
{
	t_raycast	cast;

	ini_door(&cast, core, core->player[LOCAL].view.angle);
	if (cast.side.x < cast.side.y)
	{
		cast.map_check.x += cast.step.x;
	}	
	else
	{
		cast.map_check.y += cast.step.y;
	}
	if (core->map.buf[cast.map_check.y] != NULL \
	&& core->map.buflens[cast.map_check.y] \
	> (size_t)(cast.map_check.x))
	{
		if (core->map.buf[cast.map_check.y][cast.map_check.x] == 'P')
			door_handling(cast.map_check, core);
		else
		{
			core->utils.door_text[TO_OPEN]->enabled = FALSE;
			core->utils.door_text[TO_CLOSE]->enabled = FALSE;
			return ;
		}
	}
}
