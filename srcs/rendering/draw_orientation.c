/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_orientation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:17:39 by mkhoury           #+#    #+#             */
/*   Updated: 2024/12/05 11:56:35 by mkhoury          ###   ########.fr       */
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

	//float	di;
	//float	angle;
	//float	length;

	ft_memset(&start, 0, sizeof(t_pos));
	ft_memset(&end, 0, sizeof(t_pos));
	i = 0;
	start.x = core->player[LOCAL].position.x * DEFUNIT;
	start.y = core->player[LOCAL].position.y * DEFUNIT;
	while (i < core->mlx->width)
	{
		dx = cosf(deg2rad(core->cast.angle[i])) * core->cast.casts[i];
		dy = sinf(deg2rad(core->cast.angle[i])) * core->cast.casts[i];
		end.x = start.x + dx * 8;
		end.y = start.y + dy  * 8;
		mlx_put_line(&core->layer[MINIMAP_LAYER], start, end, increase_lighting(Void, -0x02));
		i++;
	}
}
