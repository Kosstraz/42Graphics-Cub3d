/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:44:50 by ymanchon          #+#    #+#             */
/*   Updated: 2024/12/07 16:48:09 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game(t_core *core)
{
	door_raycast(core);
	player_check_movements(core);
	recv_any_element(core);
	player_check_orientationraycast(core);
	if (!core->mouse_visible)
		mlx_set_mouse_pos(core->mlx, core->half_width, core->half_height);
	// draw ray casting
	// draw entity
	calcul_casts(core);
	clear_img(core);
	draw_cast(core);
	if (core->network.is_active == true)
		draw_joueur(core);
	draw_minimap(core);
	show_fps(core);
	recv_any_element(core);
}

void	cub3d(t_core *core)
{
	if (!core->network.is_active || core->network.is_host)
	{
		if (ft_strncmp_rev(core->map.file, ".cub", 3)
			|| (!ft_strncmp_rev(core->map.file, ".cub", 3)
				&& ft_strlen(core->map.file) == 4))
			exit_strerror(BAD_EXTENSION_FILE_T, core);
		else if (!core->map.generated)
			parse_map(core);
		if (core->network.is_host)
			send_map(core);
	}
	else if (core->network.is_active)
		recv_map(core);
	init_mlx_env(core);
	//printf("%i %i apres init \n", core->mlx->width, core->mlx->height);
	setup_mlx_hooks(core);
	//printf("%i %i hooks \n", core->mlx->width, core->mlx->height);
	mlx_loop(core->mlx);
	free_core(core);
}
