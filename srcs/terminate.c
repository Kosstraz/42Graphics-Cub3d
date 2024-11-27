/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:00:47 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/27 18:59:15 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_strerror(char	*error_desc, t_core *core)
{
	free_core_map(core);
	ft_printf("%s%s", PARSING_ERROR_T, error_desc);
	exit(1);
}

void	exit_cub3d(int errcode, t_core *core)
{
	free_core(core);
	exit(errcode);
}

void	free_core_map(t_core *core)
{
	if (core)
	{
		free_layer(&core->layer[MINIMAP_LAYER]);
		free_layer(&core->layer[CAST_LAYER]);
		if (core->network.is_active)
			close_connection(core);
		ft_dfree((void **)core->map.buf);
		ft_va_free(5,
			core->map.filepath.north,
			core->map.filepath.south,
			core->map.filepath.east,
			core->map.filepath.west,
			core->map.buflens);
	}
}

void	free_core(t_core *core)
{
	if (core->network.is_active)
		close_connection(core);
	free_core_map(core);
	mlx_delete_image(core->mlx, core->imgs.minimap);
	mlx_delete_image(core->mlx, core->imgs.fps);
	mlx_terminate(core->mlx);
}
