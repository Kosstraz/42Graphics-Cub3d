/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_fps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:44:32 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/21 15:00:22 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	show_fps(t_core *core)
{
	char		*fps;

	mlx_delete_image(core->mlx, core->imgs.fps);
	fps = ft_itoa((int)(1.0 / core->mlx->delta_time));
	core->imgs.fps = mlx_put_string(core->mlx, fps, 0, 0);
	free(fps);
}
