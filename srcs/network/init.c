/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:13:37 by ymanchon          #+#    #+#             */
/*   Updated: 2025/02/07 13:42:07 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_network(t_core *core)
{
	core->network.is_host = FALSE;
	core->network.tcp.fd = -1;
	core->network.tcp.com = -1;
	ft_memset(
		&core->network.tcp.sock,
		0,
		sizeof(struct sockaddr_in));
}

void	poll_hup(t_core *core)
{
	exit_strerror("\e[31mDéconnexion détectée!\e[0m\n", core);
}
