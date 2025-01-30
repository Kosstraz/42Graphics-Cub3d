/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:46:11 by bama              #+#    #+#             */
/*   Updated: 2025/01/27 18:46:31 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline void	send_element(void *what, size_t size, char poll_id, t_core *core)
{
	if (core->network.is_active)
	{
		send(core->network.tcp.com, &poll_id, 1, 0);
		send(core->network.tcp.com, what, size, 0);
	}
}
