/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:36:30 by bama              #+#    #+#             */
/*   Updated: 2025/02/11 16:39:04 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_player_key_release1(mlx_key_data_t keyd, t_core *core)
{
	if (keyd.key == MLX_KEY_A)
		core->input_action.key_a = FALSE;
	else if (keyd.key == MLX_KEY_D)
		core->input_action.key_d = FALSE;
	if (keyd.key == MLX_KEY_W)
		core->input_action.key_w = FALSE;
	else if (keyd.key == MLX_KEY_S)
		core->input_action.key_s = FALSE;
	if (keyd.key == MLX_KEY_RIGHT)
		core->input_action.key_right = FALSE;
	else if (keyd.key == MLX_KEY_LEFT)
		core->input_action.key_left = FALSE;
	if (keyd.key == MLX_KEY_UP)
		core->input_action.key_up = FALSE;
	else if (keyd.key == MLX_KEY_DOWN)
		core->input_action.key_down = FALSE;
}

inline void	handle_player_key_release(mlx_key_data_t keyd, t_core *core)
{
	handle_player_key_release1(keyd, core);
	if (keyd.key == MLX_KEY_LEFT_SHIFT)
		core->input_action.key_shift = FALSE;
	if (keyd.key == MLX_KEY_F && core->player[LOCAL].torch_activated)
	{
		play_sound(&core->audio[TORCHOFF]);
		core->player[LOCAL].torch_activated = FALSE;
	}
	else if (keyd.key == MLX_KEY_F && !core->player[LOCAL].torch_activated)
	{
		play_sound(&core->audio[TORCHON]);
		core->player[LOCAL].torch_activated = TRUE;
	}
}
