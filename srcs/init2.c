/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:38:00 by bama              #+#    #+#             */
/*   Updated: 2025/02/12 15:38:56 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline void	init_mlx_env2(t_core *core)
{
	core->utils.door_text[TO_OPEN]->enabled = FALSE;
	core->utils.door_text[TO_CLOSE]->enabled = FALSE;
	core->imgs.minimap = mlx_new_image(core->mlx,
			core->minimap.size.x,
			core->minimap.size.y);
	core->imgs.cast = mlx_new_image(core->mlx,
			core->mlx->width, core->mlx->height);
	mlx_image_to_window(core->mlx, core->imgs.minimap,
		core->minimap.position.x, core->minimap.position.y);
	mlx_image_to_window(core->mlx, core->imgs.cast, 0, 0);
	init_layer(core->imgs.minimap, &core->layer[MINIMAP_LAYER], core);
	init_layer(core->imgs.cast, &core->layer[CAST_LAYER], core);
	if (ACTIVE_AUDIO)
		init_audio_system(core);
	play_sound(&core->audio[AMBIENT]);
	core->tex_debug = 1000;
}

	//play_sound(&core->audio[PRANK]);
	//play_sound(&core->audio[FREAKY]);
