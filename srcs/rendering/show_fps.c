/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_fps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:44:32 by ymanchon          #+#    #+#             */
/*   Updated: 2025/01/27 19:14:45 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	show_fps(t_core *core)
{
	char		*fps;

	if (core->fps_cooldown == 0)
	{
		mlx_delete_image(core->mlx, core->imgs.fps);
		fps = ft_itoa((int)(1.0f / (float)core->mlx->delta_time));
		core->imgs.fps = mlx_put_string(core->mlx, fps, 0, 0);
		mlx_image_to_window(core->mlx, core->imgs.fps, 0, 0);
		core->fps_cooldown = (int)(float)round(1000 * core->mlx->delta_time);
		free(fps);
	}
	else
		--core->fps_cooldown;
}
