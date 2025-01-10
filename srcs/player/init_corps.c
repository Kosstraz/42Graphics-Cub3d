/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_corps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:09:50 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/10 17:26:25 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    update_corps_points(t_player *player)
{
    set_point(&player->entity.liste[0].points[0],(float []) {4.f, 2.f, player->view.angle, 24.f}, player->position);
    set_point(&player->entity.liste[0].points[1],(float []) {-4.f, 2.f, player->view.angle, 24.f}, player->position);
    set_point(&player->entity.liste[0].points[2],(float []) {-4.f, -2.f, player->view.angle, 24.f}, player->position);
    set_point(&player->entity.liste[0].points[3],(float []) {4.f, -2.f, player->view.angle, 24.f}, player->position);
    set_point(&player->entity.liste[0].points[4],(float []) {4.f, 2.f, player->view.angle, 12.f}, player->position);
    set_point(&player->entity.liste[0].points[5],(float []) {-4.f, 2.f, player->view.angle, 12.f}, player->position);
    set_point(&player->entity.liste[0].points[6],(float []) {-4.f, -2.f, player->view.angle, 12.f}, player->position);
    set_point(&player->entity.liste[0].points[7],(float []) {4.f, -2.f, player->view.angle, 12}, player->position);
}

void    set_corps_face(t_player *player)
{
    init_face(&player->entity.liste[0].face[0], (t_pos *[]){&player->entity.liste[0].points[2], &player->entity.liste[0].points[3],\
    &player->entity.liste[0].points[6],&player->entity.liste[0].points[7]}, (int []){20, 21}, player->entity.texture);
    init_face(&player->entity.liste[0].face[1], (t_pos *[]){&player->entity.liste[0].points[3], &player->entity.liste[0].points[0],\
    &player->entity.liste[0].points[7],&player->entity.liste[0].points[4]}, (int []){28, 20}, player->entity.texture);
    init_face(&player->entity.liste[0].face[2], (t_pos *[]){&player->entity.liste[0].points[0], &player->entity.liste[0].points[1],\
    &player->entity.liste[0].points[4],&player->entity.liste[0].points[5]}, (int []){32, 21}, player->entity.texture);
    init_face(&player->entity.liste[0].face[3], (t_pos *[]){&player->entity.liste[0].points[1], &player->entity.liste[0].points[2],\
    &player->entity.liste[0].points[5],&player->entity.liste[0].points[6]}, (int []){16, 20}, player->entity.texture);
    init_face(&player->entity.liste[0].face[4], (t_pos *[]){&player->entity.liste[0].points[1], &player->entity.liste[0].points[0],\
    &player->entity.liste[0].points[2],&player->entity.liste[0].points[3]}, (int []){20, 16}, player->entity.texture);
    init_face(&player->entity.liste[0].face[5], (t_pos *[]){&player->entity.liste[0].points[5], &player->entity.liste[0].points[4],\
    &player->entity.liste[0].points[6],&player->entity.liste[0].points[7]}, (int []){28, 16}, player->entity.texture);
}

void    set_corps(t_player *player)
{
    update_corps_points(player);
    set_corps_face(player);
}
