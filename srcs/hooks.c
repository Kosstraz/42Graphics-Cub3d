/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:00:44 by ymanchon          #+#    #+#             */
/*   Updated: 2024/12/09 18:08:00 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub3d_key_hook(mlx_key_data_t keyd, t_core *core)
{
	if (keyd.action == MLX_PRESS)
	{
		handle_player_key_press(keyd, core);
		handle_esc_key(keyd, core);
		handle_pressing_alt_key(keyd, core);
	}
	else if (keyd.action == MLX_REPEAT)
	{
	}
	else if (keyd.action == MLX_RELEASE)
	{
		handle_player_key_release(keyd, core);
		handle_releasing_alt_key(keyd, core);
		handle_crouchplayer_key(keyd, core);
		handle_doors_key(keyd, core);
	}
}

void	cub3d_mouse_hook(mouse_key_t button,
						action_t action,
						modifier_key_t mods,
						t_core *core)
{
	(void)button;
	(void)action;
	(void)mods;
	(void)core;
}

void	cub3d_close_hook(t_core *core)
{
	exit_cub3d(0, core);
}

void	cub3d_cursor_hook(double xpos, double ypos, t_core *core)
{
	float	tmp;

	if (!core->mouse_visible)
	{
		tmp = core->player[LOCAL].offset - (core->half_height - ypos) * 15.0f * core->mlx->delta_time;
		if (tmp >= -300.0f && tmp <= 300.0f)
			core->player[LOCAL].offset = tmp;
		core->player[LOCAL].view.dz = core->half_height - tmp;
		core->player[LOCAL].view.angle -= (core->half_width - xpos) * 2.0f * core->mlx->delta_time;
		if (core->player[LOCAL].view.angle >= 360.f)
			core->player[LOCAL].view.angle = 0.f;
		if (core->player[LOCAL].view.angle < 0)
			core->player[LOCAL].view.angle = 360.f + core->player[LOCAL].view.angle;
		send_element(&core->player[LOCAL], sizeof(t_player), POLL_PLAYER, core);
	}
}

void	cub3d_scroll_hook(double xdelta, double ydelta, t_core *core)
{
	(void)xdelta;
	(void)ydelta;
	(void)core;
}
