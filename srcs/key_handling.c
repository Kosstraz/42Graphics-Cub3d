/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:00:48 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/27 15:05:39 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline void	handle_esc_key(mlx_key_data_t keyd, t_core *core)
{
	if (keyd.key == MLX_KEY_ESCAPE)
		mlx_close_window(core->mlx);
}

inline void	handle_pressing_alt_key(mlx_key_data_t keyd, t_core *core)
{
	if (keyd.key == MLX_KEY_LEFT_ALT)
	{
		core->mouse_visible = TRUE;
		mlx_set_cursor_mode(core->mlx, MLX_MOUSE_NORMAL);
	}
}

inline void	handle_releasing_alt_key(mlx_key_data_t keyd, t_core *core)
{
	if (keyd.key == MLX_KEY_LEFT_ALT)
	{
		core->mouse_visible = FALSE;
		mlx_set_cursor_mode(core->mlx, MLX_MOUSE_HIDDEN);
	}
}

// normalisation vectorielle necessaire
inline void	handle_player_key_press(mlx_key_data_t keyd, t_core *core)
{
	if (keyd.key == MLX_KEY_A)
		core->input_action.key_a = TRUE;
	else if (keyd.key == MLX_KEY_D)
		core->input_action.key_d = TRUE;
	if (keyd.key == MLX_KEY_W)
		core->input_action.key_w = TRUE;
	else if (keyd.key == MLX_KEY_S)
		core->input_action.key_s = TRUE;
}

inline void	handle_player_key_release(mlx_key_data_t keyd, t_core *core)
{
	if (keyd.key == MLX_KEY_A)
		core->input_action.key_a = FALSE;
	else if (keyd.key == MLX_KEY_D)
		core->input_action.key_d = FALSE;
	if (keyd.key == MLX_KEY_W)
		core->input_action.key_w = FALSE;
	else if (keyd.key == MLX_KEY_S)
		core->input_action.key_s = FALSE;
}

inline void	handle_crouchplayer_key(mlx_key_data_t keyd, t_core *core)
{
	if (keyd.key == MLX_KEY_C)
	{
		if (core->player[0].crouched == FALSE)
			core->player[0].crouched = TRUE;
		else
			core->player[0].crouched = FALSE;
	}
}
