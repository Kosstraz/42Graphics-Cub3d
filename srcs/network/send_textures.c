/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:38:33 by ymanchon          #+#    #+#             */
/*   Updated: 2025/02/10 18:40:51 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	send_textures(t_core *core)
{
	uint32_t	i;
	uint32_t	j;

	i = 0U;
	while (i < 4U)
	{
		ft_send(&core->xpms[i]->color_count, sizeof(int32_t), core);
		ft_send(&core->xpms[i]->cpp, sizeof(int32_t), core);
		ft_send(&core->xpms[i]->mode, sizeof(char), core);
		ft_send(&core->xpms[i]->texture.bytes_per_pixel, sizeof(uint8_t),
			core);
		ft_send(&core->xpms[i]->texture.height, sizeof(uint32_t), core);
		ft_send(&core->xpms[i]->texture.width, sizeof(uint32_t), core);
		j = 0U;
		while (j < core->xpms[i]->texture.width * core->xpms[i]->texture.height)
			ft_send(&((unsigned int *)core->xpms[i]->texture.pixels)[j++],
				sizeof(uint32_t), core);
		++i;
	}
}

static void	recv_textures2(int i, t_core *core)
{
	core->xpms[i] = (xpm_t *)malloc(sizeof(xpm_t));
	ft_recv(&core->xpms[i]->color_count,
		sizeof(int32_t), core);
	ft_recv(&core->xpms[i]->cpp, sizeof(int32_t), core);
	ft_recv(&core->xpms[i]->mode, sizeof(char), core);
	ft_recv(&core->xpms[i]->texture.bytes_per_pixel,
		sizeof(uint8_t), core);
	ft_recv(&core->xpms[i]->texture.height,
		sizeof(uint32_t), core);
	ft_recv(&core->xpms[i]->texture.width,
		sizeof(uint32_t), core);
}

//core->xpms = (xpm_t **)malloc(sizeof(xpm_t *) * 4);
void	recv_textures(t_core *core)
{
	uint32_t	i;
	uint32_t	j;

	i = 0U;
	while (i < 4U)
	{
		recv_textures2(i, core);
		core->xpms[i]->texture.pixels = (uint8_t *)malloc(sizeof(uint8_t)
				* core->xpms[i]->texture.width * core->xpms[i]->texture.height
				* core->xpms[i]->texture.bytes_per_pixel);
		j = 0U;
		while (j < core->xpms[i]->texture.width * core->xpms[i]->texture.height)
			ft_recv(&((unsigned int *)core->xpms[i]
					->texture.pixels)[j++], sizeof(uint32_t), core);
		++i;
	}
}
