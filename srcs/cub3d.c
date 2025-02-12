/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:44:50 by ymanchon          #+#    #+#             */
/*   Updated: 2025/02/12 15:38:01 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline void	*ft_malloc(unsigned long size, t_core *core)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
		exit_strerror("malloc failed.\n", core);
	return (mem);
}

inline static void	render(t_core *core)
{
	draw_minimap(core);
	calcul_casts(core);
	if (core->network.is_active)
	{
		draw_player(&core->player[DISTANT], Green, core);
		draw_joueur(core);
	}
	draw_player(&core->player[LOCAL], Blue, core);
}

void	game(t_core *core)
{
	door_raycast(core);
	player_check_movements(core);
	recv_any_element(core);
	player_check_orientationraycast(core);
	if (!core->mouse_visible)
		mlx_set_mouse_pos(core->mlx, core->half_width, core->half_height);
	recv_any_element(core);
	render(core);
	show_fps(core);
	if (ACTIVE_AUDIO && core->audio[AMBIENT].len == 0)
		play_sound(&core->audio[AMBIENT]);
	recv_any_element(core);
}

void	cub3d(t_core *core)
{
	if (!core->network.is_active || core->network.is_host)
	{
		if (!core->map.generated)
			parse_map(core);
		if (core->network.is_host)
			send_map(core);
	}
	else if (core->network.is_active)
		recv_map(core);
	init_mlx_env(core);
	setup_mlx_hooks(core);
	mlx_loop(core->mlx);
	free_core(core);
}
