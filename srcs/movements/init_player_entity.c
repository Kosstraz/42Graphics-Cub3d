/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:42:44 by mkhoury           #+#    #+#             */
/*   Updated: 2024/12/09 17:22:12 by ymanchon         ###   ########.fr       */
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

void    set_corps(t_player *player)
{
    set_point(&player->entity.corps.points[0],(float []) {25.f + player->view.angle, 0.2f, 24.f}, player->position);
    set_point(&player->entity.corps.points[1],(float []) {165.f + player->view.angle, 0.2f, 24.f}, player->position);
    set_point(&player->entity.corps.points[2],(float []) {205.f + player->view.angle, 0.2f, 24.f}, player->position);
    set_point(&player->entity.corps.points[3],(float []) {335.f + player->view.angle, 0.2f, 24.f}, player->position);
    set_point(&player->entity.corps.points[4],(float []) {25.f + player->view.angle, 0.2f, 12.f}, player->position);
    set_point(&player->entity.corps.points[5],(float []) {165.f + player->view.angle, 0.2f, 12.f}, player->position);
    set_point(&player->entity.corps.points[6],(float []) {205.f + player->view.angle, 0.2f, 12.f}, player->position);
    set_point(&player->entity.corps.points[7],(float []) {335.f + player->view.angle, 0.2f, 12.f}, player->position);
    init_face(&player->entity.corps.face[0], (t_pos *[]){&player->entity.corps.points[3], &player->entity.corps.points[4],\
    &player->entity.corps.points[6],&player->entity.corps.points[7]}, (int []){20, 21}, player->entity.texture);
}

void    init_player_entity(t_player *player)
{
    player->view.angle = 0.f;

    
}