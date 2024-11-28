/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:00:48 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/28 16:48:59 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline void	handle_esc_key(int keyd, t_core *core)
{
	if (keyd == XK_Escape)
	{
		free_core(core);
		exit(0);
	}
}

inline void	handle_pressing_alt_key(int keyd, t_core *core)
{
	if (keyd == XK_Alt_L)
	{
		core->mouse_visible = TRUE;
		mlx_mouse_show(core->mlx.context, core->mlx.window);
	}
}

inline void	handle_releasing_alt_key(int keyd, t_core *core)
{
	if (keyd == XK_Alt_L)
	{
		core->mouse_visible = FALSE;
		mlx_mouse_hide(core->mlx.context, core->mlx.window);
	}
}

// normalisation vectorielle necessaire
inline void	handle_player_key_press(int keyd, t_core *core)
{
	if (keyd == XK_a)
		core->input_action.key_a = TRUE;
	else if (keyd == XK_d)
		core->input_action.key_d = TRUE;
	if (keyd == XK_w)
		core->input_action.key_w = TRUE;
	else if (keyd == XK_s)
		core->input_action.key_s = TRUE;
	if (keyd == XK_Right)
		core->input_action.key_right = TRUE;
	else if (keyd == XK_Left)
		core->input_action.key_left = TRUE;	
}

inline void	handle_player_key_release(int keyd, t_core *core)
{
	if (keyd == XK_a)
		core->input_action.key_a = FALSE;
	else if (keyd == XK_d)
		core->input_action.key_d = FALSE;
	if (keyd == XK_w)
		core->input_action.key_w = FALSE;
	else if (keyd == XK_s)
		core->input_action.key_s = FALSE;
	if (keyd == XK_Right)
		core->input_action.key_right = FALSE;
	else if (keyd == XK_Left)
		core->input_action.key_left = FALSE;	
}

inline void	handle_crouchplayer_key(int keyd, t_core *core)
{
	if (keyd == XK_c)
	{
		if (core->player[LOCAL].crouched == FALSE)
			core->player[LOCAL].crouched = TRUE;
		else
			core->player[LOCAL].crouched = FALSE;
	}
}
