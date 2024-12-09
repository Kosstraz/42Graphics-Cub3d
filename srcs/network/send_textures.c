/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:38:33 by ymanchon          #+#    #+#             */
/*   Updated: 2024/12/09 15:42:32 by ymanchon         ###   ########.fr       */
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
		send(core->network.tcp.com, &core->xpms[i]->color_count, sizeof(int32_t), 0);
		send(core->network.tcp.com, &core->xpms[i]->cpp, sizeof(int32_t), 0);
		send(core->network.tcp.com, &core->xpms[i]->mode, sizeof(char), 0);
		send(core->network.tcp.com, &core->xpms[i]->texture.bytes_per_pixel, sizeof(uint8_t), 0);
		send(core->network.tcp.com, &core->xpms[i]->texture.height, sizeof(uint32_t), 0);
		send(core->network.tcp.com, &core->xpms[i]->texture.width, sizeof(uint32_t), 0);
		j = 0U;
		while (j < core->xpms[i]->texture.width * core->xpms[i]->texture.height)
			send(core->network.tcp.com, &((unsigned int *)core->xpms[i]->texture.pixels)[j++], sizeof(uint32_t), 0);
		++i;
	}
}

void	recv_textures(t_core *core)
{
	uint32_t	i;
	uint32_t	j;

	i = 0U;
	core->xpms = (xpm_t **)malloc(sizeof(xpm_t*) * 4);
	while (i < 4U)
	{
		core->xpms[i] = (xpm_t *)malloc(sizeof(xpm_t));
		recv(core->network.tcp.com, &core->xpms[i]->color_count, sizeof(int32_t), 0);
		recv(core->network.tcp.com, &core->xpms[i]->cpp, sizeof(int32_t), 0);
		recv(core->network.tcp.com, &core->xpms[i]->mode, sizeof(char), 0);
		recv(core->network.tcp.com, &core->xpms[i]->texture.bytes_per_pixel, sizeof(uint8_t), 0);
		recv(core->network.tcp.com, &core->xpms[i]->texture.height, sizeof(uint32_t), 0);
		recv(core->network.tcp.com, &core->xpms[i]->texture.width, sizeof(uint32_t), 0);
		core->xpms[i]->texture.pixels = (uint8_t *)malloc(sizeof(uint8_t) * core->xpms[i]->texture.width * core->xpms[i]->texture.height * core->xpms[i]->texture.bytes_per_pixel);
		j = 0U;
		while (j < core->xpms[i]->texture.width * core->xpms[i]->texture.height)
			recv(core->network.tcp.com, &((unsigned int *)core->xpms[i]->texture.pixels)[j++], sizeof(uint32_t), 0);
		++i;
	}
}
