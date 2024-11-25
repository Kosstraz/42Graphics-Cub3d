/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_orientation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:17:39 by mkhoury           #+#    #+#             */
/*   Updated: 2024/11/25 20:39:33 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	orientation_minimap(t_core *core)
{
	t_pos	end;
	t_pos	start;
	double	dx;
	double	dy;

	int		i;
	float	di;
	float	angle;
	float	length;
	i = 0;
	di = 3;		
	start.x = core->player.position.x * DEFUNIT;
	start.y = core->player.position.y * DEFUNIT;
	while (i < 20)
	{
		angle = core->player.view.angle - 30 + di * i;
		length = ray_cast(core, angle);
		dx = cos(deg2rad(angle)) * 20;
		dy = sin(deg2rad(angle)) * 20;
		end.x = start.x + dx;
		end.y = start.y + dy;
		mlx_put_line(core->imgs.minimap, start, end, Red);
		di += 1/6;
		i++;
	}

}
