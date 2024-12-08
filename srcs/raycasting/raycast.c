/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:19:35 by mkhoury           #+#    #+#             */
/*   Updated: 2024/12/08 17:50:09 by mkhoury          ###   ########.fr       */
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

float	ray_cast(t_core *core, float angle, int i)
{
	t_fvector	unit;
	t_fvector	vector_dir;
	t_ivector	step;
	t_fvector	side;
	t_fvector	ray_start;
	t_ivector	map_check;

	ft_memset(&vector_dir, 0, sizeof(t_fvector));
	ft_memset(&map_check, 0, sizeof(t_ivector));
	ray_start.x = core->player[LOCAL].position.x;
	ray_start.y = core->player[LOCAL].position.y;
	map_check.x = (int) ray_start.x;
	map_check.y	= (int) ray_start.y;
	vector_dir.x = cosf(deg2rad(angle));
	vector_dir.y = sinf(deg2rad(angle));
	unit.x = sqrtf(1.f + (vector_dir.y / vector_dir.x) * (vector_dir.y / vector_dir.x));
	unit.y = sqrtf(1.f + (vector_dir.x / vector_dir.y) * (vector_dir.x / vector_dir.y));

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

	int	max;
	float	distance;
	int		side_int;

	max =  30;
	while (max)
	{
		if (side.x < side.y)
		{
			map_check.x += step.x;
			distance = side.x;
			side.x += unit.x;
			side_int = 0;
		}	
		else
		{
			map_check.y += step.y;
			distance = side.y;
			side.y += unit.y;
			side_int = 1;
		}
		if (core->map.buf[map_check.y] != NULL && core->map.buflens[map_check.y] > (size_t)map_check.x)
		{
			if (core->map.buf[map_check.y][map_check.x] == '1')
				break ;
			else if (core->map.buf[map_check.y][map_check.x] == 'P')
				if (doors_check_state(map_check.x, map_check.y, core) < 0)
					break ;
		}
	}
	double WallDist;
	
	if (side_int == 0)
		WallDist = side.x - side.y;
	else
		WallDist = side.y - side.x;
	core->cast.height[i] = core->mlx->height / WallDist;
	core->cast.wallDist[i] = cosf(deg2rad(angle - core->player->view.angle)) * (distance);
	float WallX;
	if (side_int == 0)
		WallX = sin(deg2rad(angle)) * distance + ray_start.y;//ray_start.y + WallDist * vector_dir.y;
	else
		WallX = cos(deg2rad(angle)) * distance + ray_start.x;//ray_start.x + WallDist * vector_dir.x;
	WallX -= (int) WallX;
	core->cast.wallx[i] = WallX;
	core->cast.wall[i].x = map_check.x;
	core->cast.wall[i].y = map_check.y;
	core->cast.wall[i].z = 1.f;
	if (side_int == 1)
	 	core->cast.side[i] = 1;
	else
		core->cast.side[i] = 0;
	return (distance);
}

