/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_orientation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:17:39 by mkhoury           #+#    #+#             */
/*   Updated: 2024/11/27 15:00:08 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	orientation_minimap(t_core *core)
{
	t_pos	end;
	t_pos	start;
	float	dx;
	float	dy;

	int		i;
	float	di;
	float	angle;
	float	length;
	i = 0;
	
	start.x = core->player.position.x * DEFUNIT;
	start.y = core->player.position.y * DEFUNIT;
	while (i < core->mlx->width)
	{
		dx = cosf(deg2rad(core->cast.angle[i])) * core->cast.casts[i];
		dy = sinf(deg2rad(core->cast.angle[i])) * core->cast.casts[i];
		end.x = start.x + dx;
		end.y = start.y + dy;
		mlx_put_line(core->imgs.minimap, start, end, Red);
		i++;
	}
}
