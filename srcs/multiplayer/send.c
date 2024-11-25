/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:50:18 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/25 19:16:30 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	send_map(t_core *core)
{
	size_t	y;

	y = 0;
	send(core->multi.network.com, &core->map.bufmax, sizeof(size_t), 0);
	send(core->multi.network.com, &core->map.buflens_size, sizeof(size_t), 0);
	while (y < core->map.bufmax)
	{
		send(core->multi.network.com, &core->map.buflens[y], sizeof(size_t), 0);
		send(core->multi.network.com, core->map.buf[y], core->map.buflens[y] + 1, 0);
		y++;
	}
	send(core->multi.network.com, &core->map.buflens_max, sizeof(size_t), 0);
	send(core->multi.network.com, &core->player, sizeof(t_player), 0);
}

void	recv_map(t_core *core)
{
	size_t	y;

	y = 0;
	recv(core->multi.network.com, &core->map.bufmax, sizeof(size_t), 0);
	recv(core->multi.network.com, &core->map.buflens_size, sizeof(size_t), 0);
	core->map.buf = (char **)malloc(sizeof(char *) * (core->map.bufmax + 1));
	core->map.buflens = (size_t *)malloc(sizeof(size_t) * core->map.buflens_size);
	while (y < core->map.bufmax)
	{
		recv(core->multi.network.com, &core->map.buflens[y], sizeof(size_t), 0);
		core->map.buf[y] = (char *)malloc(sizeof(char) * (core->map.buflens[y] + 2));
		recv(core->multi.network.com, core->map.buf[y], core->map.buflens[y] + 1, 0);
		core->map.buf[y][core->map.buflens[y] + 1] = '\0';
		y++;
	}
	core->map.buf[y] = NULL;
	recv(core->multi.network.com, &core->map.buflens_max, sizeof(size_t), 0);
	recv(core->multi.network.com, &core->player, sizeof(t_player), 0);
}

void	send_core(t_core *core)
{

}

void	recv_core(t_core *core)
{

}
