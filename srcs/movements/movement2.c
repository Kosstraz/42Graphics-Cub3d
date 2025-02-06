/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:16:27 by ymanchon          #+#    #+#             */
/*   Updated: 2025/02/05 14:39:08 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_player *player, float angle, t_core *core);

void	sprint(t_core *core)
{
	if (core->input_action.key_shift == TRUE)
	{
		core->player[LOCAL].bubbles_speed = BUBBLES_SPEED * 2.5f;
		core->player[LOCAL].speed = DEFPLAYERSPEED * 2.0f;
	}
	else
	{
		core->player[LOCAL].bubbles_speed = BUBBLES_SPEED;
		core->player[LOCAL].speed = DEFPLAYERSPEED;
	}
}

static void	crouch_player(t_core *core)
{
	if (core->input_action.key_up)
	{
		core->player[LOCAL].offset -= 700.f * core->mlx->delta_time;
		send_element(&core->player[LOCAL], sizeof(t_player), POLL_PLAYER, core);
	}
	else if (core->input_action.key_down)
	{
		core->player[LOCAL].offset += 700.f * core->mlx->delta_time;
		send_element(&core->player[LOCAL], sizeof(t_player), POLL_PLAYER, core);
	}
}

inline static void	player_check_movements2(t_core *core)
{
	if (core->input_action.key_a == TRUE)
	{
		move_player(core->player, core->player->view.angle - 90.f, core);
		bubbles_sin(BUBBLES_MIN, BUBBLES_MAX, core);
		send_element(&core->player[LOCAL], sizeof(t_player), POLL_PLAYER, core);
	}
	else if (core->input_action.key_d == TRUE)
	{
		move_player(core->player, core->player->view.angle + 90.f, core);
		bubbles_sin(BUBBLES_MIN, BUBBLES_MAX, core);
		send_element(&core->player[LOCAL], sizeof(t_player), POLL_PLAYER, core);
	}
}

inline void	player_check_movements(t_core *core)
{
	crouch_player(core);
	player_check_movements2(core);
	if (core->input_action.key_w == TRUE)
	{
		sprint(core);
		move_player(core->player, core->player->view.angle, core);
		bubbles_sin(BUBBLES_MIN, BUBBLES_MAX, core);
		send_element(&core->player[LOCAL], sizeof(t_player), POLL_PLAYER, core);
	}
	else if (core->input_action.key_s == TRUE)
	{
		move_player(core->player, 180.f + core->player->view.angle, core);
		bubbles_sin(BUBBLES_MIN, BUBBLES_MAX, core);
		send_element(&core->player[LOCAL], sizeof(t_player), POLL_PLAYER, core);
	}
	if (!core->input_action.key_a && !core->input_action.key_d
		&& !core->input_action.key_s && !core->input_action.key_w)
		bubbles_sin(BUBBLES_MID, BUBBLES_MID, core);
}
