/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:42:44 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/13 18:33:57 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_face(t_face *face, t_pos *points[4], int pos[2], mlx_texture_t *texture)
{
    face->p1 = points[0];
	face->p2 = points[1];
    face->p3 = points[2];
    face->p4 = points[3];
    face->offset.x = pos[0];
    face->offset.y = pos[1];
    face->texture = texture;
}

void    set_point(t_pos *point, float att[4], t_pos pos)
{
	float	angle;
	float	distance;

	angle = get_angle(att[0], att[1]) + att[3];
	distance = sqrtf((att[0] * att[0]) + (att[1] * att[1])) * 0.1f;
    point->x = cos(deg2rad(angle)) * distance + pos.x;
    point->y = sin(deg2rad(angle)) * distance + pos.y;
    point->z = att[2];
}

void	cpy_ptbl(t_core *core, t_player player)
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 8)
		{
			core->liste[i].points[j].x = player.entity.liste[i][j].x;
			core->liste[i].points[j].y = player.entity.liste[i][j].y;
			core->liste[i].points[j].z = player.entity.liste[i][j].z;
			j++;
		}
		i++;
	}	
}
