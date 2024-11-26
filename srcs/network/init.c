/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:13:37 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/26 19:20:51 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_network(t_core *core)
{
	ft_memset(
		&core->network,
		0,
		sizeof(t_network));
	core->network.hostaddr = NULL;
	core->network.is_active = FALSE;
	core->network.is_host = FALSE;
	core->network.udp.fd = -1;
	core->network.tcp.fd = -1;
	core->network.tcp.com = -1;
}
