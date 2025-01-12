/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_face.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:27:41 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/12 18:49:23 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// translate coord into screen coords

void	get_x(t_pos point, t_screenp *dest, t_pos local, t_core *core)
{
	float	angle;
	float	delta;

	angle = get_angle((point.x - local.x), (point.y - local.y));
	if (angle - core->player[LOCAL].view.angle > 180.f)
		delta = 360.f - (angle - core->player[LOCAL].view.angle);
	else if (angle - core->player[LOCAL].view.angle < -180.f)
		delta = -360.f - (angle - core->player[LOCAL].view.angle);
	else
		delta = angle - core->player[LOCAL].view.angle;
	dest->x = (int) (core->half_width + (delta / core->cast.di));
	dest->angle = angle;
}

void	get_y(t_pos point, t_screenp *dest, t_pos local, t_core *core)
{
	float	distance;

	distance = sqrtf((point.x - local.x) * (point.x  - local.x)\
		+ (point.y - local.y) * (point.y - local.y));
	dest->y = (int) (point.z * 100.f / distance + 100.f / distance);
	dest->distance = distance;
}

void	transform_points(t_pos *points[4], t_screenp **dest, t_pos local, t_core *core)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		get_x(*points[i], dest[i], local, core);
		get_y(*points[i], dest[i], local, core);
		i++;
	}
}
// 

void	draw_face(t_face face, t_core *core)
{
	t_screenp	*points;

	points = malloc(sizeof(t_screenp) * 4);
	if (!points)
		return ;
	transform_points((t_pos *[]){face.p1, face.p2, face.p3, face.p4}, &points, core->player[LOCAL].position, core);
	//draw_face_extra(points, face, core);
	//draw_t1(points, core, face);
//	draw_t1();
	free(points);
}
