/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:00:48 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/22 19:00:20 by mkhoury          ###   ########.fr       */
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
inline void	handle_player_key(mlx_key_data_t keyd, t_core *core)
{
	if (keyd.key == MLX_KEY_A)
	{
		handle_movement(&core->map, &core->player, DEFPLAYERMOVEMENTS * 10, 0);
	}
	else if (keyd.key == MLX_KEY_D)
	{
		handle_movement(&core->map, &core->player, -DEFPLAYERMOVEMENTS * 10, 0);
	}
	if (keyd.key == MLX_KEY_W)
	{
		handle_movement(&core->map, &core->player, 0, DEFPLAYERMOVEMENTS * 10);
	}
	else if (keyd.key == MLX_KEY_S)
	{
		handle_movement(&core->map, &core->player, 0, -DEFPLAYERMOVEMENTS * 10);
	}
}

inline void	handle_crouchplayer_key(mlx_key_data_t keyd, t_core *core)
{
	if (keyd.key == MLX_KEY_C)
	{
		if (core->player.crouched == FALSE)
			core->player.crouched = TRUE;
		else
			core->player.crouched = FALSE;
	}
}
