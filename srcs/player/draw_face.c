/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_face.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:27:41 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/15 16:53:04 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// translate coord into screen coords

void	get_x(t_pos *point, t_screenp *dest, t_pos local, t_core *core)
{
	float	angle;
	float	delta;

	angle = get_angle((point->x - local.x), (point->y - local.y));
	
	if (angle - core->player[LOCAL].view.angle > 180.f)
		delta = 360.f - (angle - core->player[LOCAL].view.angle);
	else if (angle - core->player[LOCAL].view.angle < -180.f)
		delta = -360.f - (angle - core->player[LOCAL].view.angle);
	else
		delta = angle - core->player[LOCAL].view.angle;
	//printf("angle : %f delta : %f player view angle %f\n", angle, delta, core->player[LOCAL].view.angle);
	dest->x = (int) (core->half_width + (delta / core->cast.di));
	dest->angle = angle;
}

void	get_y(t_pos *point, t_screenp *dest, t_pos local, t_core *core)
{
	float	distance;

	distance = sqrtf((point->x - local.x) * (point->x  - local.x)\
		+ (point->y - local.y) * (point->y - local.y));
	dest->y = (int) (point->z * 100.f / distance + 100.f / distance);
	dest->distance = distance;
}

t_screenp	*transform_points(t_pos *points, t_pos local, t_core *core)
{
	t_screenp	*dest;

	dest = malloc(sizeof(t_screenp));
	if (!dest)
		return (NULL);
	get_x(points, dest, local, core);
	get_y(points, dest, local, core);
	return (dest);
}
// 

void	free_points(t_screenp **points)
{
	if (points[0])
		free(points[0]);
	if (points[1])
		free(points[1]);
	if (points[2])
		free(points[2]);
	if (points[3])
		free(points[3]);
	free(points);
}
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

void	draw_face(t_face face, t_core *core)
{
	t_screenp	**points;

	points = malloc(sizeof(t_screenp *) * 4);
	points[0] = transform_points(face.p1, core->player[LOCAL].position, core);
	points[1] = transform_points(face.p2, core->player[LOCAL].position, core);
	points[2] = transform_points(face.p3, core->player[LOCAL].position, core);
	points[3] = transform_points(face.p4, core->player[LOCAL].position, core);
	if (!points[0] || !points[1] || !points[2] || !points[3])
	{
		free_points(points);
		return ;
	}
	// printf("p1 x: %i y:%i\n", points[0].x, points[0].y);
	// printf("p2 x: %i y:%i\n", points[1].x, points[1].y);
	// printf("p3 x: %i y:%i\n", points[2].x, points[2].y);
	// printf("p4 x: %i y:%i\n", points[3].x, points[3].y);
	//draw_face_extra(points, face, core);
	draw_rectanglej((t_screenp []){*points[0], *points[3]}, Red, core);
	printf("point x: %i\n", points[0]->x);
//	draw_t1((t_screenp []){*points[1], *points[0], *points[3]}, core, face);
//	draw_t1();
	free_points(points);
}

