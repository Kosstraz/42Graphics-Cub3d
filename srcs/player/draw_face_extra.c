/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_face_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:16:47 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/07 16:24:06 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_col(t_ipos points[2], int index, t_core *core, t_face face)
{
	int				i;
	int				nb_pixel;
	t_color_type	color;

	i = 0;
	nb_pixel = points[1].y - points[0].y;
	while (i < nb_pixel)
	{
		color = (unsigned int *) (face.texture->pixels[i * 12 + index]);
		draw_pixel(points[0].x, points[0].y, color, &core->layer[CAST_LAYER]);
		points[0].y++;
		i++;
	}
}

void	change_p1(t_ipos *p, float var)
{
	float	temp;

	temp = (float) p->y + var;
	p->y = (int) (roundf(temp));
}

void	draw_face_extra(t_screenp points[4], t_face face, t_core *core)
{
	int	i;
	int	iter;
	float	delta[2];
	t_ipos	p[2];

	iter = points[1].x - points[0].x;
	delta[0] = (float) ((points[1].y - points[0].y) / (points[1].x - points[0].x));
	delta[1] = (float) ((points[3].y - points[2].y) / (points[3].x - points[2].x));
	p[0].y = points[0].y;
	p[1].y = points[2].y;
	i = 0;
	while (i < iter)
	{
		p[0].x++;
		p[1].x++;
		change_p1(&p[0], delta[0]);
		change_p2(&p[1], delta[1]);
		draw_col(p, i, core, face);
		i++;
	}
}
