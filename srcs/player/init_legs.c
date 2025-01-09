/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_legs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:20:41 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/09 16:49:17 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    update_legl_points(t_player *player)
{
    set_point(&player->entity.liste[2].points[0],(float []) {90.f + player->view.angle, 0.08f, 12.f}, player->position);
    set_point(&player->entity.liste[2].points[1],(float []) {165.f + player->view.angle, 0.2f, 12.f}, player->position);
    set_point(&player->entity.liste[2].points[2],(float []) {205.f + player->view.angle, 0.2f, 12.f}, player->position);
    set_point(&player->entity.liste[2].points[3],(float []) {270.f + player->view.angle, 0.08f, 12.f}, player->position);
    set_point(&player->entity.liste[2].points[4],(float []) {90.f + player->view.angle, 0.08f, 0.f}, player->position);
    set_point(&player->entity.liste[2].points[5],(float []) {165.f + player->view.angle, 0.2f, 0.f}, player->position);
    set_point(&player->entity.liste[2].points[6],(float []) {205.f + player->view.angle, 0.2f, 0.f}, player->position);
    set_point(&player->entity.liste[2].points[7],(float []) {270.f + player->view.angle, 0.08f, 0.f}, player->position);
}

void    set_legl_face(t_player *player)
{
    init_face(&player->entity.liste[2].face[0], (t_pos *[]){&player->entity.liste[2].points[2], &player->entity.liste[2].points[3],\
    &player->entity.liste[2].points[6],&player->entity.liste[2].points[7]}, (int []){20, 21}, player->entity.texture);
    init_face(&player->entity.liste[2].face[1], (t_pos *[]){&player->entity.liste[2].points[3], &player->entity.liste[2].points[0],\
    &player->entity.liste[2].points[7],&player->entity.liste[2].points[4]}, (int []){28, 20}, player->entity.texture);
    init_face(&player->entity.liste[2].face[2], (t_pos *[]){&player->entity.liste[2].points[0], &player->entity.liste[2].points[1],\
    &player->entity.liste[2].points[4],&player->entity.liste[2].points[5]}, (int []){32, 21}, player->entity.texture);
    init_face(&player->entity.liste[2].face[3], (t_pos *[]){&player->entity.liste[2].points[1], &player->entity.liste[2].points[2],\
    &player->entity.liste[2].points[5],&player->entity.liste[2].points[6]}, (int []){16, 20}, player->entity.texture);
    init_face(&player->entity.liste[2].face[4], (t_pos *[]){&player->entity.liste[2].points[1], &player->entity.liste[2].points[0],\
    &player->entity.liste[2].points[2],&player->entity.liste[2].points[3]}, (int []){20, 16}, player->entity.texture);
    init_face(&player->entity.liste[2].face[5], (t_pos *[]){&player->entity.liste[2].points[5], &player->entity.liste[2].points[4],\
    &player->entity.liste[2].points[6],&player->entity.liste[2].points[7]}, (int []){28, 16}, player->entity.texture);
}

void    set_legs(t_player *player)
{
    update_legl_points(player);
    set_corps_face(player);
}