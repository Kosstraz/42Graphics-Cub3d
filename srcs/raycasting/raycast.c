/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:19:35 by mkhoury           #+#    #+#             */
/*   Updated: 2024/11/25 21:13:09 by mkhoury          ###   ########.fr       */
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

// void	cast_ray(t_core *core, int i)
// {
// 	int		h_w;
// 	int		mx, my;
// 	float	ra;
// 	float	ry;
// 	float	rx;
// 	float	py,px;
// 	float	x0, y0;
// 	py = core->player.position.y;
// 	px = core->player.position.x;
// 	ra = core->player.view.angle;
	
// 	// horizontal
// 	float	aTan;

// 	aTan = -1 / tan(ra);
// 	h_w = 0;
// 	if (ra > PI)
// 	{
// 		ry = (((int) py >> 6) << 6) - 0.0001;
// 		rx = (py - ry) * aTan + px;
// 		y0 = -64;
// 		x0 = - y0 * aTan;
// 	}
// 	else if (ra < PI && ra != 0)
// 	{
// 		ry = (((int) py >> 6) << 6) + 64;
// 		rx = (py - ry) * aTan + px;
// 		y0 = 64;
// 		x0 = - y0 * aTan;
// 	}
// 	else
// 	{
// 		rx = px;
// 		ry = py;
// 		h_w = 10;
// 	}
	
// 	while (h_w < 10)
// 	{
// 		if (core->map.buf[(int) ry][(int) rx] == '1')
// 			break ;
// 		else
// 		{
// 			h_w++;
// 			ry += y0;
// 			rx += x0;
// 		}
// 	}
	
// }

float	ray_cast(t_core *core, float angle)
{
	t_fvector	unit;
	t_fvector	vector_dir;
	t_ivector	step;
	t_fvector	side;
	t_ivector	ray_start;
	t_ivector	map_check;

	
	ray_start.x = core->player.position.x;
	ray_start.y = core->player.position.y;
	map_check.x = (int) ray_start.x;
	map_check.y	= (int) ray_start.y;
	vector_dir.x = cos(deg2rad(angle));
	vector_dir.y = sin(deg2rad(angle));
	unit.x = sqrt(1 + (vector_dir.y / vector_dir.x) * (vector_dir.y / vector_dir.x));
	unit.y = sqrt(1 + (vector_dir.x / vector_dir.y) * (vector_dir.x / vector_dir.y));

	if (vector_dir.x < 0)
	{
		step.x = -1;
		side.x = (ray_start.x - (float) map_check.x) * unit.x;
	}
	else
	{
		step.x = 1;
		side.x = ((float) (map_check.x + 1) - ray_start.x) * unit.x;
	}

	if (vector_dir.y < 0)
	{
		step.y = -1;
		side.y = (ray_start.y - (float) map_check.y) * unit.y;
	}
	else
	{
		step.y = 1;
		side.y = ((float) (map_check.y + 1) - ray_start.y) * unit.y;
	}

		// 	bool bTileFound = false;
		// float fMaxDistance = 100.0f;
		// float fDistance = 0.0f;
		// while (!bTileFound && fDistance < fMaxDistance)
		// {
		// 	// Walk along shortest path
		// 	if (vRayLength1D.x < vRayLength1D.y)
		// 	{
		// 		vMapCheck.x += vStep.x;
		// 		fDistance = vRayLength1D.x;
		// 		vRayLength1D.x += vRayUnitStepSize.x;
		// 	}
		// 	else
		// 	{
		// 		vMapCheck.y += vStep.y;
		// 		fDistance = vRayLength1D.y;
		// 		vRayLength1D.y += vRayUnitStepSize.y;
		// 	}

		// 	// Test tile at new test point
		// 	if (vMapCheck.x >= 0 && vMapCheck.x < vMapSize.x && vMapCheck.y >= 0 && vMapCheck.y < vMapSize.y)
		// 	{
		// 		if (vecMap[vMapCheck.y * vMapSize.x + vMapCheck.x] == 1)
		// 		{
		// 			bTileFound = true;
		// 		}
		// 	}
		// }
	
}
