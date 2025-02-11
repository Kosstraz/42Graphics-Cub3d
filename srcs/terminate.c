/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:00:47 by ymanchon          #+#    #+#             */
/*   Updated: 2025/02/11 15:36:13 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_strerror(char	*error_desc, t_core *core)
{
	if (core)
	{
		free_core_map(core);
		if (core->mapfile_fd > 2)
			finish_gnl(core->mapfile_fd);
	}
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
	unsigned long	i;

	i = 0;
	if (core)
	{
		mlx_delete_xpm42(core->xpms[SO]);
		mlx_delete_xpm42(core->xpms[NO]);
		mlx_delete_xpm42(core->xpms[EA]);
		mlx_delete_xpm42(core->xpms[WE]);
		mlx_delete_texture(core->texturej);
		free_layer(&core->layer[MINIMAP_LAYER]);
		free_layer(&core->layer[CAST_LAYER]);
		if (core->network.is_active)
			close_connection(core);
		while (i < core->map.bufsize)
			free(core->map.buf[i++]);
		ft_va_free(8,
			core->map.filepath.north, core->map.buf, core->xpms,
			core->map.filepath.south, core->map.filepath.east,
			core->map.filepath.west, core->map.buflens, core->map.doors);
	}
}

void	free_core(t_core *core)
{
	if (core->network.is_active)
		close_connection(core);
	destroy_audio_system(core);
	free_core_map(core);
	mlx_delete_image(core->mlx, core->imgs.minimap);
	mlx_delete_image(core->mlx, core->imgs.fps);
	mlx_terminate(core->mlx);
}
