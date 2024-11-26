/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:50:18 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/26 20:52:28 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	send_map(t_core *core)
{
	size_t	y;

	y = 0;
	ft_printf("SEND MAP");
	tcp_send(&core->map.bufmax, sizeof(size_t), core);
	tcp_send(&core->map.buflens_size, sizeof(size_t), core);
	while (y < core->map.bufmax)
	{
		tcp_send(&core->map.buflens[y], sizeof(size_t), core);
		tcp_send(core->map.buf[y], core->map.buflens[y] + 1, core);
		y++;
	}
	tcp_send(&core->map.buflens_max, sizeof(size_t), core);
	tcp_send(&core->player[LOCAL], sizeof(t_player), core);
	tcp_send(&core->player[DISTANT], sizeof(t_player), core);
	ft_printf("--> finished\n");
}

void	recv_map(t_core *core)
{
	size_t	y;

	y = 0;
	tcp_recv(&core->map.bufmax, sizeof(size_t), core);
	tcp_recv(&core->map.buflens_size, sizeof(size_t), core);
	core->map.buf = (char **)malloc(sizeof(char *) * (core->map.bufmax + 1));
	core->map.buflens = (size_t *)malloc(sizeof(size_t) * core->map.buflens_size);
	while (y < core->map.bufmax)
	{
		tcp_recv(&core->map.buflens[y], sizeof(size_t), core);
		core->map.buf[y] = (char *)malloc(sizeof(char) * (core->map.buflens[y] + 2));
		tcp_recv(core->map.buf[y], core->map.buflens[y] + 1, core);
		core->map.buf[y][core->map.buflens[y] + 1] = '\0';
		y++;
	}
	core->map.buf[y] = NULL;
	tcp_recv(&core->map.buflens_max, sizeof(size_t), core);
	tcp_recv(&core->player[DISTANT], sizeof(t_player), core);
	tcp_recv(&core->player[LOCAL], sizeof(t_player), core);
}

inline void	tcp_send(void *what, size_t size, t_core *core)
{
	struct pollfd	pollfd;

	if (core->network.is_active)
	{
		pollfd.events = POLLOUT;
		pollfd.fd = core->network.tcp.fd;
		pollfd.revents = 0;
		poll(&pollfd, 1, 0);
		if (pollfd.revents & POLLOUT)
			send(core->network.tcp.com, what, size, 0);
	}
}

void	tcp_recv(void *what, size_t size, t_core *core)
{
	struct pollfd	pollfd;

	if (core->network.is_active)
	{
		pollfd.events = POLLIN;
		pollfd.fd = core->network.tcp.com;
		pollfd.revents = 0;
		poll(&pollfd, 1, 0);
		if (pollfd.revents & POLLIN)
			recv(core->network.tcp.com, what, size, 0);
	}
}

inline void	udp_send(void *what, size_t size, t_core *core, char id)
{
	struct pollfd	pollfd;

	if (core->network.is_active)
	{
		pollfd.events = POLLOUT;
		pollfd.fd = core->network.udp.fd;
		pollfd.revents = 0;
		poll(&pollfd, 1, 0);
		if (pollfd.revents & POLLOUT)
		{
			sendto(core->network.udp.fd, &id, 1, 0, (struct sockaddr *)&core->network.udp.com, core->network.udp.len);
			sendto(core->network.udp.fd, what, size, 0, (struct sockaddr *)&core->network.udp.com, core->network.udp.len);
		}
	}
}

void	udp_recvs(t_core *core)
{
	char			id;
	struct pollfd	pollfd;

	if (core->network.is_active)
	{
		pollfd.events = POLLIN;
		pollfd.fd = core->network.udp.fd;
		pollfd.revents = 0;
		poll(&pollfd, 1, 0);
		if (pollfd.revents & POLLIN)
		{
			recvfrom(core->network.udp.fd, &id, 1, 0, (struct sockaddr *)&core->network.udp.com, &core->network.udp.len);
			if (id == POLL_PLAYER)
				recvfrom(core->network.udp.fd, &core->player[DISTANT], sizeof(t_player), 0, (struct sockaddr *)&core->network.udp.com, &core->network.udp.len);
			else if (id == POLL_SYNC_TO_SERVER)
				recvfrom(core->network.udp.fd, NULL, 4, 0, (struct sockaddr *)&core->network.udp.com, &core->network.udp.len);
		}
	}
}
