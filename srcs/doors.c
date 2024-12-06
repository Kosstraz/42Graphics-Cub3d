/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:46:15 by ymanchon          #+#    #+#             */
/*   Updated: 2024/12/06 18:25:14 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_doors_key(mlx_key_data_t keyd, t_core *core)
{
	t_door_info	dinfo;

	if (keyd.key == MLX_KEY_E)
	{
		dinfo.which_door = core->utils.door_focus;
		if (core->utils.door_text[TO_OPEN]->enabled)
		{
			core->utils.door_text[TO_OPEN]->enabled = FALSE;
			core->utils.door_text[TO_CLOSE]->enabled = TRUE;
			core->map.doors[core->utils.door_focus].is_open = TRUE;
			dinfo.is_open = TRUE;
			send_element(&dinfo, sizeof(t_door_info), POLL_DOOR, core);
		}
		else if (core->utils.door_text[TO_CLOSE]->enabled)
		{
			core->utils.door_text[TO_OPEN]->enabled = TRUE;
			core->utils.door_text[TO_CLOSE]->enabled = FALSE;
			core->map.doors[core->utils.door_focus].is_open = FALSE;
			dinfo.is_open = FALSE;
			send_element(&dinfo, sizeof(t_door_info), POLL_DOOR, core);
		}
	}
}

static float	vector_norm(float x, float y)
{
	return (sqrtf(x * x + y * y));
}

static void	which_text_show(BOOL door, t_pos wallp, t_core *core)
{
	size_t	i;

	if (door)
	{
		i = 0U;
		while (i < core->map.nbOfDoors)
		{
			if (core->map.doors[i].pos.x == (int)(wallp.x + 0.5f)
				&& core->map.doors[i].pos.y == (int)(wallp.y + 0.5f))
			{
				if (core->map.doors[i].is_open)
					core->utils.door_text[TO_CLOSE]->enabled = TRUE;
				else
					core->utils.door_text[TO_OPEN]->enabled = TRUE;
				core->utils.door_focus = i;
			}
			i++;
		}
	}
	else
	{
		core->utils.door_text[TO_OPEN]->enabled = FALSE;
		core->utils.door_text[TO_CLOSE]->enabled = FALSE;
	}
}

BOOL	doors_check_state(int x, int y, t_core *core)
{
	size_t	i;

	i = 0U;
	while (i < core->map.nbOfDoors)
	{
		if (core->map.doors[i].pos.x == x
			&& core->map.doors[i].pos.y == y
			&& core->map.doors[i].is_open)
				return (FALSE);
		++i;
	}
	return (TRUE);
}

int	door_handling(t_ivector vec, t_core *core)
{
	uint32_t	i;
	t_pos		wallp;
	float		dist;
	BOOL		door;

	i = 0;
	door = FALSE;
	dist = fabsf(vector_norm(vec.x + 0.5f, vec.y + 0.5f) - vector_norm(core->player[LOCAL].position.x, core->player[LOCAL].position.y));
	if (core->map.buf[(int)(vec.y + 0.5f)][(int)(vec.x + 0.5f)] == 'P'
		&& dist <= 1.6f)
		door = TRUE;
	/*while (i < 1920U)
	{
		wallp.x = core->cast.wall[i].x;
		wallp.y = core->cast.wall[i].y;
		dist = fabsf(vector_norm(wallp.x + 0.5f, wallp.y + 0.5f) - vector_norm(core->player[LOCAL].position.x, core->player[LOCAL].position.y));
		if (core->map.buf[(int)(wallp.y + 0.5f)][(int)(wallp.x + 0.5f)] == 'P'
			&& dist <= 1.6f)
		{
			door = TRUE;
			break ;
		}
		i++;
	}*/
	wallp.x = vec.x;
	wallp.y = vec.y;
	wallp.z = 0;
	which_text_show(door, wallp, core);
	if (core->map.nbOfDoors == 0)
		return (FALSE);
	return (core->map.doors[core->utils.door_focus].is_open);
}

/*void	door_handling(t_core *core)
{
	uint32_t	i;
	t_pos		wallp;
	float		dist;
	BOOL		door;

	i = 0;
	door = FALSE;
	while (i < 1920U)
	{
		wallp.x = core->cast.wall[i].x;
		wallp.y = core->cast.wall[i].y;
		dist = fabsf(vector_norm(wallp.x + 0.5f, wallp.y + 0.5f) - vector_norm(core->player[LOCAL].position.x, core->player[LOCAL].position.y));
		if (core->map.buf[(int)(wallp.y + 0.5f)][(int)(wallp.x + 0.5f)] == 'P'
			&& dist <= 1.6f)
		{
			door = TRUE;
			break ;
		}
		i++;
	}
	which_text_show(door, wallp, core);
}*/
