/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:46:15 by ymanchon          #+#    #+#             */
/*   Updated: 2025/02/11 17:19:13 by ymanchon         ###   ########.fr       */
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

void	door_handling(t_ivector pos, t_core *core)
{
	int	is_opened;

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
