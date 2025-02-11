/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:46:11 by bama              #+#    #+#             */
/*   Updated: 2025/02/11 16:28:13 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_poll_cf_col(t_core *core)
{
	t_color	col;

	ft_recv(&col, sizeof(t_color), core);
	core->map.cf_colors[C] = col;
	ft_recv(&col, sizeof(t_color), core);
	core->map.cf_colors[F] = col;
}

inline void	send_element(void *what, size_t size, char poll_id, t_core *core)
{
	if (core->network.is_active)
	{
		ft_send(&poll_id, sizeof(poll_id), core);
		ft_send(what, size, core);
	}
}
