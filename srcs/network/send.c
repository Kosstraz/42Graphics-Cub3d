/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:50:18 by ymanchon          #+#    #+#             */
/*   Updated: 2024/12/06 18:34:07 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	send_map(t_core *core)
{
	size_t	y;

	y = 0;
	send(core->network.tcp.com, &core->map.bufmax, sizeof(size_t), 0);
	send(core->network.tcp.com, &core->map.buflens_size, sizeof(size_t), 0);
	while (y < core->map.bufmax)
	{
		send(core->network.tcp.com, &core->map.buflens[y], sizeof(size_t), 0);
		send(core->network.tcp.com, core->map.buf[y], core->map.buflens[y] + 1, 0);
		y++;
	}
	send(core->network.tcp.com, &core->map.buflens_max, sizeof(size_t), 0);
	send(core->network.tcp.com, &core->player[0], sizeof(t_player), 0);
	send(core->network.tcp.com, &core->player[1], sizeof(t_player), 0);
	send(core->network.tcp.com, &core->map.nbOfDoors, sizeof(size_t), 0);
	for (uint32_t i = 0U ; i < core->map.nbOfDoors ; i++)
		send(core->network.tcp.com, &core->map.doors[i], sizeof(t_door), 0);
}

void	recv_map(t_core *core)
{
	size_t	y;

	y = 0;
	recv(core->network.tcp.com, &core->map.bufmax, sizeof(size_t), 0);
	recv(core->network.tcp.com, &core->map.buflens_size, sizeof(size_t), 0);
	core->map.buf = (char **)malloc(sizeof(char *) * (core->map.bufmax + 1));
	core->map.buflens = (size_t *)malloc(sizeof(size_t) * core->map.buflens_size);
	while (y < core->map.bufmax)
	{
		recv(core->network.tcp.com, &core->map.buflens[y], sizeof(size_t), 0);
		core->map.buf[y] = (char *)malloc(sizeof(char) * (core->map.buflens[y] + 2));
		recv(core->network.tcp.com, core->map.buf[y], core->map.buflens[y] + 1, 0);
		core->map.buf[y][core->map.buflens[y] + 1] = '\0';
		y++;
	}
	core->map.buf[y] = NULL;
	recv(core->network.tcp.com, &core->map.buflens_max, sizeof(size_t), 0);
	recv(core->network.tcp.com, &core->player[1], sizeof(t_player), 0);
	recv(core->network.tcp.com, &core->player[0], sizeof(t_player), 0);
	recv(core->network.tcp.com, &core->map.nbOfDoors, sizeof(size_t), 0);
	core->map.doors = (t_door *)malloc(sizeof(t_door) * core->map.nbOfDoors);
	for (uint32_t i = 0U ; i < core->map.nbOfDoors ; i++)
		recv(core->network.tcp.com, &core->map.doors[i], sizeof(t_door), 0);
}

inline void	send_element(void *what, size_t size, char poll_id, t_core *core)
{
	if (core->network.is_active)
	{
		send(core->network.tcp.com, &poll_id, 1, 0);
		send(core->network.tcp.com, what, size, 0);
	}
}

inline static void	handle_poll_door(t_core *core)
{
	t_door_info	dinfo;
	recv(core->network.tcp.com, &dinfo, sizeof(t_door_info), 0);
	core->map.doors[dinfo.which_door].is_open = dinfo.is_open;
	if (core->utils.door_focus == dinfo.which_door)
	{
		core->utils.door_text[TO_OPEN]->enabled = FALSE;
		core->utils.door_text[TO_CLOSE]->enabled = FALSE;
		if (core->map.doors[dinfo.which_door].is_open)
			core->utils.door_text[TO_OPEN]->enabled = TRUE;
		else
			core->utils.door_text[TO_CLOSE]->enabled = TRUE;
	}
}

void	recv_any_element(t_core *core)
{
	char			poll_id;
	struct pollfd	pollfd;

	if (core->network.is_active)
	{
		pollfd.events = POLLIN;
		pollfd.fd = core->network.tcp.com;
		pollfd.revents = 0;
		poll(&pollfd, 1, 0);
		if (pollfd.revents & POLLIN)
		{
			recv(core->network.tcp.com, &poll_id, 1, 0);
			if (poll_id == POLL_PLAYER)
				recv(core->network.tcp.com, &core->player[1], sizeof(t_player), 0);
			else if (poll_id == POLL_DOOR)
				handle_poll_door(core);
		}
	}
}
