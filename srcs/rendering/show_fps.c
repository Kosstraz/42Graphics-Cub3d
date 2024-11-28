/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_fps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:44:32 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/28 16:28:14 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	show_fps(t_core *core)
{
	//char		*fps;
	//
	//if (core->fps_cooldown == 0)
	//{
	//	mlx_delete_image(core->mlx, core->imgs.fps);
	//	fps = ft_itoa((int)(1.0f / (float)core->mlx->delta_time));
	//	core->imgs.fps = mlx_put_string(core->mlx, fps, 0, 0);
	//	core->fps_cooldown = (int)(float)round(1000 * core->mlx->delta_time);
	//	free(fps);
	//	core->fps_cooldown = 1000 * core->mlx->delta_time;
	//}
	//else
	//	--core->fps_cooldown;
}
