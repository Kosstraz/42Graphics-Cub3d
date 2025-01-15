/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:26:41 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/15 15:43:29 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	place_texture(t_ipos point, t_face face, t_core *core, float prc[2])
{
	if (point.x < 0 || point.x > core->layer[CAST_LAYER].width)
		return ;
	if (point.y < 0 || point.y > core->layer[CAST_LAYER].height)
		return ;
	draw_pixel(point.x, point.y, Red, &core->layer[CAST_LAYER]);
}

void	draw_line_x(t_screenp points[2], t_face face, t_core *core, float prc)
{
	int		step;
	int		i;
	t_ipos	point;
	t_pos	delta;
	
	if (points[1].x - points[0].x > 0)
		step = 1;
	else
		step = -1;
	i = 0;
	delta.y = (float) (points[1].y - points[0].y) / (points[1].x - points[0].x);
	delta.x = (float) abs((points[1].x - points[0].x));
	while (point.x != points[1].x)
	{
		point.x = points[0].x + i * step;
		point.y = points[0].y + (int) (delta.y * ((float)i));
		place_texture(point, face, core, (float []){prc, (float) i / delta.x});
		//draw_pixel(point.x, point.y, Red, &core->layer[CAST_LAYER]);
		i++;
	}
}

void	draw_line_texture(t_screenp points[2], t_face face, t_core *core, float prc)
{
	t_ipos	delta;

	delta.x = abs(points[1].x - points[0].x);
	delta.y = abs(points[1].y - points[0].y);
	if (delta.x > delta.y)
		draw_line_x(points, face, core, prc);
	else
		draw_line_x(points, face, core, prc);
}