/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_resize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:00:43 by ymanchon          #+#    #+#             */
/*   Updated: 2024/12/03 18:02:51 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub3d_resize_hook(int width, int height, t_core *core)
{
	core->half_width = width / 2.f;
	core->half_height = height / 2.f;
	core->minimap.size.x = core->map.buflens_max * DEFUNIT;
	core->minimap.size.y = core->map.bufmax * DEFUNIT;
	core->minimap.position.x = core->mlx->width - core->map.buflens_max * DEFUNIT - 10;
	core->minimap.position.y = 10;
	mlx_resize_image(
		core->imgs.cast,
		core->mlx->width,
		core->mlx->height);
	mlx_resize_image(
		core->imgs.minimap,
		core->minimap.size.x,
		core->minimap.size.y);
	mlx_delete_image(core->mlx, core->imgs.minimap);
	core->imgs.minimap = mlx_new_image(core->mlx, core->minimap.size.x, core->minimap.size.y);
	mlx_image_to_window(
		core->mlx,
		core->imgs.minimap,
		core->minimap.position.x,
		core->minimap.position.y);
	init_layer(core->imgs.minimap, &core->layer[MINIMAP_LAYER]);
	init_layer(core->imgs.cast, &core->layer[CAST_LAYER]);
}
