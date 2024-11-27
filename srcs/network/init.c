/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:13:37 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/26 20:58:43 by ymanchon         ###   ########.fr       */
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
