/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_resize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:00:43 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/25 15:01:12 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub3d_resize_hook(int width, int height, t_core *core)
{
	core->half_width = width / 2.f;
	core->half_height = height / 2.f;
	mlx_delete_image(core->mlx, core->imgs.minimap);
	core->minimap.size.x = core->map.buflens_max * DEFUNIT;
	core->minimap.size.y = core->map.bufmax * DEFUNIT;
	core->imgs.minimap = mlx_new_image(core->mlx,
			core->minimap.size.x,
			core->minimap.size.y);
}
