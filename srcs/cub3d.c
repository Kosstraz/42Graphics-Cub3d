/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:44:50 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/18 22:41:14 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	show_fps(t_core *core)
{
	char		*fps;

	mlx_delete_image(core->mlx, core->fpsimg);
	fps = ft_itoa((int)(1.0 / core->mlx->delta_time));
	core->fpsimg = mlx_put_string(core->mlx, fps, 0, 0);
	free(fps);
	mlx_image_to_window(core->mlx, core->fpsimg, 0, 0);
}

void	game(t_core *core)
{
	if (!core->mouse_visible)
		mlx_set_mouse_pos(core->mlx, core->half_width, core->half_height);
	show_fps(core);
}

void	cub3d(t_core *core)
{
	if (!core->map.generated)
		parse_map(core);
	init_mlx_env(core);
	setup_mlx_hooks(core);
	mlx_loop(core->mlx);
	free_core(core);
}
