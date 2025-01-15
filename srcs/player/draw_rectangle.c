/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:45:22 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/15 16:51:45 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rectanglej(t_screenp p[2], long color, t_core *core)
{
	int	i;
	int	x;
	int	y;
	int	j;

	i = 0;
	y = p[1].y;
	while (i < (p[1].y - p[0].y))
	{
		j = 0;
		x = 0;
		while (j < (p[1].x - p[0].x))
		{
			draw_pixel(x, y, color, &core->layer[CAST_LAYER]);
			x++;
			j++;
		}	
		y++;
		i++;
	}
	
}
