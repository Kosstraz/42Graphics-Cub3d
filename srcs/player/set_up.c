/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:42:44 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/02 20:10:20 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_face(t_face *face, t_pos *points[4], int pos[2], mlx_texture *texture)
{
    face->p1 = points[0];
    face->p2 = points[1];
    face->p3 = points[2];
    face->p4 = points[3];
    face->offset.x = pos[0];
    face->offset.y = pos[1];
    face->texture = texture; 
}

void    set_point(t_pos *point, float att[3], t_pos pos)
{
    point->x = cos(deg2rad(att[0])) * att[1] + pos.x;
    point->y = sin(deg2rad(att[0])) * att[1] + pos.y;
    point->z = att[3];
}
