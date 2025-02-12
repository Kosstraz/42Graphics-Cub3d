/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:50:18 by ymanchon          #+#    #+#             */
/*   Updated: 2025/02/12 15:41:51 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	send_map(t_core *core)
{
	uint32_t	i;
	size_t		y;

	y = 0;
	ft_send(core->map.cf_colors, sizeof(t_color) * 2, core);
	ft_send(&core->map.bufmax, sizeof(size_t), core);
	ft_send(&core->map.buflens_size, sizeof(size_t), core);
	while (y < core->map.bufmax)
	{
		ft_send(&core->map.buflens[y], sizeof(size_t), core);
		ft_send(core->map.buf[y],
			core->map.buflens[y] + 1, core);
		y++;
	}
	ft_send(&core->map.buflens_max, sizeof(size_t), core);
	ft_send(&core->player[LOCAL], sizeof(t_player), core);
	ft_send(&core->player[DISTANT], sizeof(t_player), core);
	ft_send(&core->map.nb_of_doors, sizeof(size_t), core);
	i = 0U;
	while (i < core->map.nb_of_doors)
		ft_send(&core->map.doors[i++], sizeof(t_door), core);
	send_textures(core);
}

static void	recv_map_first_part(t_core *core)
{
	size_t		y;

	y = 0;
	ft_recv(&core->map.bufmax, sizeof(size_t), core);
	ft_recv(&core->map.buflens_size, sizeof(size_t), core);
	core->map.buf = (char **)ft_realloc(core->map.buf,
			sizeof(char *) * DEFMAPBUF,
			sizeof(char *) * (core->map.bufmax + 1));
	core->map.buflens = (size_t *)ft_malloc(sizeof(size_t)
			* core->map.buflens_size, core);
	while (y < core->map.bufmax)
	{
		ft_recv(&core->map.buflens[y], sizeof(size_t), core);
		core->map.buf[y] = (char *)ft_malloc(sizeof(char)
				* (core->map.buflens[y] + 2), core);
		ft_recv(core->map.buf[y], core->map.buflens[y] + 1, core);
		core->map.buf[y][core->map.buflens[y] + 1] = '\0';
		y++;
	}
	core->map.bufsize = y;
	core->map.buf[y] = NULL;
}

void	recv_map(t_core *core)
{
	uint32_t	i;

	ft_recv(core->map.cf_colors, sizeof(t_color) * 2, core);
	recv_map_first_part(core);
	ft_recv(&core->map.buflens_max, sizeof(size_t), core);
	ft_recv(&core->player[DISTANT], sizeof(t_player), core);
	ft_recv(&core->player[LOCAL], sizeof(t_player), core);
	ft_recv(&core->map.nb_of_doors, sizeof(size_t), core);
	core->map.doors = (t_door *)ft_malloc(sizeof(t_door)
			* core->map.nb_of_doors, core);
	i = 0U;
	while (i < core->map.nb_of_doors)
		ft_recv(&core->map.doors[i++], sizeof(t_door), core);
	recv_textures(core);
}

// ! ligne 92 a enlever et tester sur le multi
inline static void	handle_poll_door(t_core *core)
{
	t_door_info	dinfo;

	ft_recv(&dinfo, sizeof(t_door_info), core);
	core->map.doors[dinfo.which_door].is_open = !dinfo.is_open;
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

void	poll_hup(t_core *core);
void	handle_poll_cf_col(t_core *core);

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
			ft_recv(&poll_id, 1, core);
			if (poll_id == POLL_PLAYER)
				ft_recv(&core->player[1], sizeof(t_player), core);
			else if (poll_id == POLL_DOOR)
				handle_poll_door(core);
		}
		if (pollfd.revents & (POLLHUP | POLLERR | POLLNVAL))
			poll_hup(core);
	}
}
