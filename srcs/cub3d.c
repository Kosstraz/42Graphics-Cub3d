/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:44:50 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/28 16:47:59 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline static void	put_all_images_to_window(t_core *core)
{
	core->minimap.position.x
		= core->mlx.width - core->map.buflens_max * DEFUNIT - 10;
	core->minimap.position.y = 10;
	cub_put_image_to_window(&core->imgs.cast, 0, 0, core);
	cub_put_image_to_window(
		&core->imgs.minimap,
		core->minimap.position.x,
		core->minimap.position.y,
		core);
}

void	game(t_core *core)
{
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
	player_check_movements(core);
	recv_any_element(core);
	player_check_orientationraycast(core);
	if (!core->mouse_visible)
		mlx_mouse_move(core->mlx.context, core->mlx.window, core->mlx.half_width, core->mlx.half_height);
	// draw ray casting
	// draw entity
	calcul_casts(core);
	//draw_cast(core);
	draw_minimap(core);
	show_fps(core);
	put_all_images_to_window(core);
	recv_any_element(core);
	gettimeofday(&end, NULL);
	core->delta_time = end.tv_sec - start.tv_sec;
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
	mlx_loop(core->mlx.context);
	free_core(core);
}
