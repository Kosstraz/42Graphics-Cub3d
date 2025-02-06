/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:49:38 by mkhoury           #+#    #+#             */
/*   Updated: 2025/02/06 15:58:51 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	checker_end_while(t_core *core, t_raycast *cast)
{
	if (core->map.buf[cast->map_check.y] != NULL && \
	core->map.buflens[cast->map_check.y] > (size_t)cast->map_check.x)
	{
		if (core->map.buf[cast->map_check.y][cast->map_check.x] == '1')
			return (true);
		else if (core->map.buf[cast->map_check.y][cast->map_check.x] == 'P')
			if (doors_check_state(cast->map_check.x, \
			cast->map_check.y, core) < 0)
				return (true);
	}
	return (false);
}
