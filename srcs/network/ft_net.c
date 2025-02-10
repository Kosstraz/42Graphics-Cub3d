/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_net.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:34:05 by ymanchon          #+#    #+#             */
/*   Updated: 2025/02/10 16:41:16 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_send(const void *__buf, size_t __n, t_core *core)
{
	if (send(core->network.tcp.com, __buf, __n, 0) <= 0)
		exit_strerror("Connexion perdue.\n", core);
}

void	ft_recv(void *__buf, size_t __n, t_core *core)
{
	if (recv(core->network.tcp.com, __buf, __n, 0) <= 0)
		exit_strerror("Connexion perdue.\n", core);
}
