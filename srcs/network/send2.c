/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:46:11 by bama              #+#    #+#             */
/*   Updated: 2025/02/07 13:35:52 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_poll_cf_col(t_core *core)
{
	t_color	col;

	recv(core->network.tcp.com, &col, sizeof(t_color), 0);
	core->map.cf_colors[C] = col;
	recv(core->network.tcp.com, &col, sizeof(t_color), 0);
	core->map.cf_colors[F] = col;
}

inline void	send_element(void *what, size_t size, char poll_id, t_core *core)
{
	if (core->network.is_active)
	{
		send(core->network.tcp.com, &poll_id, 1, 0);
		send(core->network.tcp.com, what, size, 0);
	}
}
