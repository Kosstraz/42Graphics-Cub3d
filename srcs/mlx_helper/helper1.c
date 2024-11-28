/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:09:50 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/28 17:05:47 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_mlx_init(t_core *core)
{
	core->mlx.context = mlx_init();
	if (core->network.is_host)
		core->mlx.window = mlx_new_window(
				core->mlx.context,
				DEFWIDTH,
				DEFHEIGHT,
				GAME_TITLE_S);
	else
		core->mlx.window = mlx_new_window(
				core->mlx.context,
				DEFWIDTH,
				DEFHEIGHT,
				GAME_TITLE);
	mlx_mouse_hide(core->mlx.context, core->mlx.window);
	mlx_mouse_move(
		core->mlx.context,
		core->mlx.window,
		core->mlx.half_width,
		core->mlx.half_height);
}

void	cub_new_image(t_image *img, int sizeX, int sizeY, t_core *core)
{
	img->width = sizeX;
	img->height = sizeY;
	img->context = mlx_new_image(core->mlx.context, sizeX, sizeY);
	img->pixels = mlx_get_data_addr(
		img->context,
		&img->info.bpp,
		&img->info.size_line,
		&img->info.endian);
}

inline int	cub_put_image_to_window(
	t_image *img,
	int atX,
	int atY,
	t_core *core)
{
	img->position.x = atX;
	img->position.y = atY;
	return (mlx_put_image_to_window(
			core->mlx.context,
			core->mlx.window,
			img->context,
			atX,
			atY));
}

