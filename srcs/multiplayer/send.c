/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:50:18 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/25 19:57:02 by ymanchon         ###   ########.fr       */
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
	send(core->multi.network.com, &core->player[0], sizeof(t_player), 0);
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
	recv(core->multi.network.com, &core->player[1], sizeof(t_player), 0);
}

inline void	send_element(void *what, size_t size, char poll_id, t_core *core)
{
	if (core->multi.is_active)
	{
		send(core->multi.network.com, &poll_id, 1, 0);
		send(core->multi.network.com, what, size, 0);
	}
}

void	recv_any_element(t_core *core)
{
	char			poll_id;
	struct pollfd	pollfd;

	if (core->multi.is_active)
	{
		pollfd.events = POLLIN;
		pollfd.fd = core->multi.network.com;
		pollfd.revents = 0;
		poll(&pollfd, 1, 0);
		if (pollfd.revents & POLLIN)
		{
			recv(core->multi.network.com, &poll_id, 1, 0);
			if (poll_id == POLL_PLAYER)
				recv(core->multi.network.com, &core->player[1], sizeof(t_player), 0);
		}
	}
}
