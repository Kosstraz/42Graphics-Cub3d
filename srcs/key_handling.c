/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:00:48 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/25 20:04:04 by ymanchon         ###   ########.fr       */
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
		if (core->map.buf[(int)roundf(core->player[0].position.y)][(int)roundf(core->player[0].position.x - DEFPLAYERSPEED)] == CUB3D_VOID)
			core->player[0].position.x -= DEFPLAYERSPEED;
		ft_printf("MOVEMENTS\n");
		//send_element(&core->player[0], sizeof(t_player), POLL_PLAYER, core);
	}
	else if (keyd.key == MLX_KEY_D)
	{
		if (core->map.buf[(int)roundf(core->player[0].position.y)][(int)roundf(core->player[0].position.x + DEFPLAYERSPEED)] == CUB3D_VOID)
			core->player[0].position.x += DEFPLAYERSPEED;
		ft_printf("MOVEMENTS\n");
		//send_element(&core->player[0], sizeof(t_player), POLL_PLAYER, core);
	}
	if (keyd.key == MLX_KEY_W)
	{
		if (core->map.buf[(int)roundf(core->player[0].position.y - DEFPLAYERSPEED)][(int)roundf(core->player[0].position.x)] == CUB3D_VOID)
			core->player[0].position.y -= DEFPLAYERSPEED;
		ft_printf("MOVEMENTS\n");
		//send_element(&core->player[0], sizeof(t_player), POLL_PLAYER, core);
	}
	else if (keyd.key == MLX_KEY_S)
	{
		if (core->map.buf[(int)roundf(core->player[0].position.y + DEFPLAYERSPEED)][(int)roundf(core->player[0].position.x)] == CUB3D_VOID)
			core->player[0].position.y += DEFPLAYERSPEED;
		ft_printf("MOVEMENTS\n");
		//send_element(&core->player[0], sizeof(t_player), POLL_PLAYER, core);
	}
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
