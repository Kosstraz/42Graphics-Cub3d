/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:24:27 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/26 20:41:42 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_tcp_connection(t_core *core)
{
	if (core->network.tcp.fd != -1)
		close(core->network.tcp.fd);
	if (core->network.tcp.com != -1)
	{
		close(core->network.tcp.com);
		ft_printf("TCP connection closed!\n");
	}
	core->network.tcp.fd = -1;
	core->network.tcp.com = -1;
}

void	close_udp_connection(t_core *core)
{
	if (core->network.udp.fd != -1)
	{
		close(core->network.udp.fd);
		ft_printf("UDP connection closed!\n");
	}
	core->network.udp.fd = -1;
}

inline void	close_all_connections(t_core *core)
{
	close_tcp_connection(core);
	close_udp_connection(core);
}
