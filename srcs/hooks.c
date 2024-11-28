/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:00:44 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/28 16:24:51 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub3d_key_hook(int keyd, t_core *core)
{
	if (keyd == 02) // press
	{
		handle_player_key_press(keyd, core);
		handle_esc_key(keyd, core);
		handle_pressing_alt_key(keyd, core);
	}
	else if (keyd == 03) //release
	{
		handle_player_key_release(keyd, core);
		handle_releasing_alt_key(keyd, core);
		handle_crouchplayer_key(keyd, core);
	}
}

void	cub3d_mouse_hook(int mouseX, int mouseY, t_core *core)
{
	(void)mouseX;
	(void)mouseY;
	(void)core;
}

void	cub3d_close_hook(t_core *core)
{
	exit_cub3d(0, core);
}
