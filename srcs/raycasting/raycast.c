/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:19:35 by mkhoury           #+#    #+#             */
/*   Updated: 2024/11/25 15:04:50 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// float	get_x_wall(t_core *core)
// {
// 	float	m;
// 	int		x;
// 	int		sign_x;

// 	if (core->player.view.dx = 0)
// 		return ();
// 	else if (core->player.view.dx > 0)
// 		sign_x = 1;
// 	else
// 		sign_x = -1;
// 	m = core->player.view.dy / core->player.view.dx * sign_x;
// 	if (core->player.view.dy > 0)
// 		x = (int) core->player.position.x;
// 	else if (core->player.view.dy == 0)
		

// }

void	cast_ray(t_core *core, int i)
{
	int		h_w;
	int		mx, my;
	float	ra;
	float	ry;
	float	rx;
	float	py,px;
	float	x0, y0;
	py = core->player.position.y;
	px = core->player.position.x;
	ra = core->player.view.angle;
	
	// horizontal
	float	aTan;

	aTan = -1 / tan(ra);
	h_w = 0;
	if (ra > PI)
	{
		ry = (((int) py >> 6) << 6) - 0.0001;
		rx = (py - ry) * aTan + px;
		y0 = -64;
		x0 = - y0 * aTan;
	}
	else if (ra < PI && ra != 0)
	{
		ry = (((int) py >> 6) << 6) + 64;
		rx = (py - ry) * aTan + px;
		y0 = 64;
		x0 = - y0 * aTan;
	}
	else
	{
		rx = px;
		ry = py;
		h_w = 10;
	}
	
	while (h_w < 10)
	{
		if (core->map.buf[(int) ry][(int) rx] == '1')
			break ;
		else
		{
			h_w++;
			ry += y0;
			rx += x0;
		}
	}
	
}

void	raycast(t_core *core)
{
	int	i;

	i = - NB_RAYS / 2;
	while (i < NB_RAYS / 2)
	{
		cast_ray(core, i);
		i++;
	}	
}
