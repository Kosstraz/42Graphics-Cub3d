/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:44:50 by ymanchon          #+#    #+#             */
/*   Updated: 2024/12/03 17:28:06 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline static void	put_images_to_window(t_core *core)
{
	mlx_image_to_window(core->mlx, core->imgs.cast, 0, 0);
	//mlx_image_to_window(core->mlx, core->imgs.fps, 0, 0);
	core->minimap.position.x = core->mlx->width - core->map.buflens_max * DEFUNIT - 10;
	core->minimap.position.y = 10;
	mlx_image_to_window(
		core->mlx,
		core->imgs.minimap,
		core->minimap.position.x,
		core->minimap.position.y);
}



void	game(t_core *core)
{
	long int	start;

	start = get_time2();
	player_check_movements(core);
	recv_any_element(core);
	player_check_orientationraycast(core);
	if (!core->mouse_visible)
		mlx_set_mouse_pos(core->mlx, core->half_width, core->half_height);
	// draw ray casting
	// draw entity
	calcul_casts(core);
	//printf("time for calcul: %ld\n", get_time() -  start);
	clear_img(core);
	draw_cast(core);
	//printf("time for draw cast: %ld\n", get_time() -  start);
	draw_minimap(core);
	//printf("time for minimap: %ld\n", get_time() -  start);
	show_fps(core);
	//printf("time for fps: %ld\n", get_time() -  start);
	put_images_to_window(core);
	//printf("time for putimgs : %ld\n", get_time() -  start);
	recv_any_element(core);
	printf("end game loop: %ld\n", get_time2() -  start);
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
