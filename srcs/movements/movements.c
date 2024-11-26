/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:42:44 by mkhoury           #+#    #+#             */
/*   Updated: 2024/11/26 19:16:04 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline void	player_check_movements(t_core *core)
{
	if (core->input_action.key_a == TRUE)
	{
		//if (core->map.buf[(int)roundf(core->player[LOCAL].position.y)][(int)roundf(core->player[0].position.x - DEFPLAYERSPEED)] == CUB3D_VOID)
			core->player[LOCAL].position.x -= DEFPLAYERSPEED * core->mlx->delta_time;
		udp_send(&core->player[LOCAL], sizeof(t_player), core, POLL_PLAYER);
	}
	else if (core->input_action.key_d == TRUE)
	{
		//if (core->map.buf[(int)roundf(core->player[0].position.y)][(int)roundf(core->player[0].position.x + DEFPLAYERSPEED)] == CUB3D_VOID)
			core->player[0].position.x += DEFPLAYERSPEED * core->mlx->delta_time;
		udp_send(&core->player[LOCAL], sizeof(t_player), core, POLL_PLAYER);
	}
	if (core->input_action.key_w == TRUE)
	{
		//if (core->map.buf[(int)roundf(core->player[0].position.y - DEFPLAYERSPEED)][(int)roundf(core->player[0].position.x)] == CUB3D_VOID)
			core->player[0].position.y -= DEFPLAYERSPEED * core->mlx->delta_time;
		udp_send(&core->player[LOCAL], sizeof(t_player), core, POLL_PLAYER);
	}
	else if (core->input_action.key_s == TRUE)
	{
		//if (core->map.buf[(int)roundf(core->player[0].position.y + DEFPLAYERSPEED)][(int)roundf(core->player[0].position.x)] == CUB3D_VOID)
			core->player[0].position.y += DEFPLAYERSPEED * core->mlx->delta_time;
		udp_send(&core->player[LOCAL], sizeof(t_player), core, POLL_PLAYER);
	}
}
