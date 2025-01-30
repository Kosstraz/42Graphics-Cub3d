/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:42:44 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/27 18:58:25 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_player_utils(t_player *player, t_pos *tmp)
{
	if (tmp->x < player->position.x)
		tmp->x -= .06f;
	else if (tmp->x > player->position.x)
		tmp->x += .06f;
	if (tmp->y < player->position.y)
		tmp->y -= .07f;
	else if (tmp->y > player->position.y)
		tmp->y += .07f;
}

static void	collision(t_pos tmp, t_pos next, t_player *player, t_core *core)
{
	if (tmp.y >= 0 && tmp.y < (int)core->map.bufmax
		&& ((core->map.buf[(int)tmp.y][(int)player->position.x]
			!= CUB3D_WALL && core->map.buf[(int)tmp.y][(int)player->position.x]
		!= CUB3D_DOOR)
			|| doors_check_state((int)player->position.x,
				(int)tmp.y, core) > 0))
		player->position.y = next.y;
	if (tmp.x >= 0 && tmp.x < (int)core->map.buflens[(int)tmp.y]
		&& ((core->map.buf[(int)player->position.y][(int)tmp.x]
			!= CUB3D_WALL && core->map.buf[(int)player->position.y][(int)tmp.x]
		!= CUB3D_DOOR)
			|| doors_check_state((int)tmp.x,
				(int)player->position.y, core) > 0))
		player->position.x = next.x;
}

void	move_player(t_player *player, float angle, t_core *core)
{
	float	cosx;
	float	siny;
	t_pos	next;
	t_pos	tmp;

	cosx = cosf(deg2rad(angle));
	siny = sinf(deg2rad(angle));
	next.x = player->position.x + cosx * player->speed / 50.f;
	next.y = player->position.y + siny * player->speed / 50.f;
	tmp = next;
	move_player_utils(player, &tmp);
	tmp.x = (int)tmp.x;
	tmp.y = (int)tmp.y;
	collision(tmp, next, player, core);
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
