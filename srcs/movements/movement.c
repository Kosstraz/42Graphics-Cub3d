/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:42:44 by mkhoury           #+#    #+#             */
/*   Updated: 2024/12/03 14:12:55 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_player *player, float angle)
{
	float	cosx;
	float	siny;
	
	cosx = cosf(deg2rad(angle));
	siny = sinf(deg2rad(angle));
	player->position.x += cosx * DEFPLAYERSPEED / 50.f;
	player->position.y += siny * DEFPLAYERSPEED / 50.f;
}

inline void	player_check_movements(t_core *core)
{
	if (core->input_action.key_a == TRUE)
	{
		//if (core->map.buf[(int)roundf(core->player[LOCAL].position.y)][(int)roundf(core->player[0].position.x - DEFPLAYERSPEED)] == CUB3D_VOID)
		move_player(core->player, core->player->view.angle - 90.f);
			//core->player[LOCAL].position.x -= DEFPLAYERSPEED * core->mlx->delta_time;
		send_element(&core->player[LOCAL], sizeof(t_player), POLL_PLAYER, core);
	}
	else if (core->input_action.key_d == TRUE)
	{
		//if (core->map.buf[(int)roundf(core->player[0].position.y)][(int)roundf(core->player[0].position.x + DEFPLAYERSPEED)] == CUB3D_VOID)
			move_player(core->player, core->player->view.angle + 90.f);
			//core->player[0].position.x += DEFPLAYERSPEED * core->mlx->delta_time;
		send_element(&core->player[LOCAL], sizeof(t_player), POLL_PLAYER, core);
	}
	if (core->input_action.key_w == TRUE)
	{
		//if (core->map.buf[(int)roundf(core->player[0].position.y - DEFPLAYERSPEED)][(int)roundf(core->player[0].position.x)] == CUB3D_VOID)
			move_player(core->player, core->player->view.angle);
			//core->player[0].position.y -= DEFPLAYERSPEED * core->mlx->delta_time;
		send_element(&core->player[LOCAL], sizeof(t_player), POLL_PLAYER, core);
	}
	else if (core->input_action.key_s == TRUE)
	{
		//if (core->map.buf[(int)roundf(core->player[0].position.y + DEFPLAYERSPEED)][(int)roundf(core->player[0].position.x)] == CUB3D_VOID)
			move_player(core->player, 180.f + core->player->view.angle);
			//core->player[0].position.y += DEFPLAYERSPEED * core->mlx->delta_time;
		send_element(&core->player[LOCAL], sizeof(t_player), POLL_PLAYER, core);
	}
}

inline void	player_check_orientationraycast(t_core *core)
{
	if (core->input_action.key_right == TRUE)
	{
		core->player[LOCAL].view.angle += 90 * core->mlx->delta_time;
		if (core->player[LOCAL].view.angle >= 360)
			core->player[LOCAL].view.angle = 0;
	}
	else if (core->input_action.key_left == TRUE)
	{
		core->player[LOCAL].view.angle -= 90 * core->mlx->delta_time;
		if (core->player[LOCAL].view.angle <= 0)
			core->player[LOCAL].view.angle = 360;
	}
}
