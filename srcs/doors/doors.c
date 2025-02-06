/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:46:15 by ymanchon          #+#    #+#             */
/*   Updated: 2025/02/05 14:49:24 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_doors_key(mlx_key_data_t keyd, t_core *core)
{
	t_door_info	dinfo;

	if (keyd.key == MLX_KEY_E && core->utils.door_focus != -1)
	{
		recv_any_element(core);
		dinfo.which_door = core->utils.door_focus;
		if (core->utils.door_text[TO_CLOSE]->enabled)
		{
			play_sound(&core->audio[rand_btw(DOOR1, DOOR3)]);
			core->utils.door_text[TO_OPEN]->enabled = FALSE;
			core->utils.door_text[TO_CLOSE]->enabled = TRUE;
			core->map.doors[core->utils.door_focus].is_open = FALSE;
			dinfo.is_open = TRUE;
			send_element(&dinfo, sizeof(t_door_info), POLL_DOOR, core);
		}
		else if (core->utils.door_text[TO_OPEN]->enabled)
		{
			play_sound(&core->audio[rand_btw(DOOR1, DOOR3)]);
			core->utils.door_text[TO_OPEN]->enabled = TRUE;
			core->utils.door_text[TO_CLOSE]->enabled = FALSE;
			core->map.doors[core->utils.door_focus].is_open = TRUE;
			dinfo.is_open = FALSE;
			send_element(&dinfo, sizeof(t_door_info), POLL_DOOR, core);
		}
	}
}

float	vector_norm(float x, float y)
{
	return (sqrtf(x * x + y * y));
}

// return (index + 1) if door is opened
// return -(index + 1) if door is closed
// else : return (0)
int	doors_check_state(int x, int y, t_core *core)
{
	size_t	i;

	i = 0U;
	while (i < core->map.nb_of_doors)
	{
		if (core->map.doors[i].pos.x == x
			&& core->map.doors[i].pos.y == y)
		{
			if (core->map.doors[i].is_open)
				return (i + 1);
			else
				return (-(i + 1));
		}
		++i;
	}
	return (0);
}

static void	door_handling(t_ivector pos, t_core *core)
{
	bool	is_opened;

	is_opened = doors_check_state(pos.x, pos.y, core);
	if (is_opened > 0)
	{
		core->utils.door_text[TO_OPEN]->enabled = FALSE;
		core->utils.door_text[TO_CLOSE]->enabled = TRUE;
		core->utils.door_focus = is_opened - 1;
	}
	else if (is_opened < 0)
	{
		core->utils.door_text[TO_OPEN]->enabled = TRUE;
		core->utils.door_text[TO_CLOSE]->enabled = FALSE;
		core->utils.door_focus = -is_opened - 1;
	}
	else
		core->utils.door_focus = -1;
}

void	door_raycast(t_core *core)
{
	t_fvector	unit;
	t_fvector	vector_dir;
	t_ivector	step;
	t_fvector	side;
	t_fvector	ray_start;
	t_ivector	map_check;
	int			side_int;

	ray_start.x = core->player[LOCAL].position.x;
	ray_start.y = core->player[LOCAL].position.y;
	map_check.x = (int) ray_start.x;
	map_check.y	= (int) ray_start.y;
	vector_dir.x = cosf(deg2rad(core->player[LOCAL].view.angle));
	vector_dir.y = sinf(deg2rad(core->player[LOCAL].view.angle));
	unit.x = sqrtf(1.f + (vector_dir.y / vector_dir.x) * (vector_dir.y / vector_dir.x));
	unit.y = sqrtf(1.f + (vector_dir.x / vector_dir.y) * (vector_dir.x / vector_dir.y));
	if (vector_dir.x < 0)
	{
		step.x = -1;
		side.x = (ray_start.x - (float) map_check.x) * unit.x;
	}
	else
	{
		step.x = 1;
		side.x = ((float) (map_check.x + 1) - ray_start.x) * unit.x;
	}
	if (vector_dir.y < 0)
	{
		step.y = -1;
		side.y = (ray_start.y - (float) map_check.y) * unit.y;
	}
	else
	{
		step.y = 1;
		side.y = ((float) (map_check.y + 1) - ray_start.y) * unit.y;
	}
	if (side.x < side.y)
	{
		map_check.x += step.x;
		side.x += unit.x;
		side_int = 0;
	}	
	else
	{
		map_check.y += step.y;
		side.y += unit.y;
		side_int = 1;
	}
	if (core->map.buf[map_check.y] != NULL && core->map.buflens[map_check.y] > (size_t)map_check.x)
	{
		if (core->map.buf[map_check.y][map_check.x] == 'P')
			door_handling(map_check, core);
		else
		{
			core->utils.door_text[TO_OPEN]->enabled = FALSE;
			core->utils.door_text[TO_CLOSE]->enabled = FALSE;
			return ;
		}
	}
}
