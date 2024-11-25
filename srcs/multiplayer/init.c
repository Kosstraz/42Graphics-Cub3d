/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:13:37 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/25 18:23:18 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_network(t_core *core)
{
	core->multi.is_host = FALSE;
	core->multi.network.fd = -1;
	core->multi.network.com = -1;
	ft_memset(
		&core->multi.network.sock,
		0,
		sizeof(struct sockaddr_in));
}
