/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_head.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:45:45 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/09 16:39:07 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    update_head_points(t_player *player)
{
    set_point(&player->entity.liste[1].points[0],(float []) {45.f + player->view.angle, 0.3f, 32.f}, player->position);
    set_point(&player->entity.liste[1].points[1],(float []) {135.f + player->view.angle, 0.3f, 32.f}, player->position);
    set_point(&player->entity.liste[1].points[2],(float []) {225.f + player->view.angle, 0.3f, 32.f}, player->position);
    set_point(&player->entity.liste[1].points[3],(float []) {315.f + player->view.angle, 0.3f, 32.f}, player->position);
    set_point(&player->entity.liste[1].points[4],(float []) {45.f + player->view.angle, 0.3f, 24.f}, player->position);
    set_point(&player->entity.liste[1].points[5],(float []) {135.f + player->view.angle, 0.3f, 24.f}, player->position);
    set_point(&player->entity.liste[1].points[6],(float []) {225.f + player->view.angle, 0.3f, 24.f}, player->position);
    set_point(&player->entity.liste[1].points[7],(float []) {315.f + player->view.angle, 0.3f, 24.f}, player->position);
}

void    set_head_face(t_player *player)
{
    init_face(&player->entity.liste[1].face[0], (t_pos *[]){&player->entity.liste[1].points[2], &player->entity.liste[1].points[3],\
    &player->entity.liste[1].points[6],&player->entity.liste[1].points[7]}, (int []){20, 21}, player->entity.texture);
    init_face(&player->entity.liste[1].face[1], (t_pos *[]){&player->entity.liste[1].points[3], &player->entity.liste[1].points[0],\
    &player->entity.liste[1].points[7],&player->entity.liste[1].points[4]}, (int []){28, 20}, player->entity.texture);
    init_face(&player->entity.liste[1].face[2], (t_pos *[]){&player->entity.liste[1].points[0], &player->entity.liste[1].points[1],\
    &player->entity.liste[1].points[4],&player->entity.liste[1].points[5]}, (int []){32, 21}, player->entity.texture);
    init_face(&player->entity.liste[1].face[3], (t_pos *[]){&player->entity.liste[1].points[1], &player->entity.liste[1].points[2],\
    &player->entity.liste[1].points[5],&player->entity.liste[1].points[6]}, (int []){16, 20}, player->entity.texture);
    init_face(&player->entity.liste[1].face[4], (t_pos *[]){&player->entity.liste[1].points[1], &player->entity.liste[1].points[0],\
    &player->entity.liste[1].points[2],&player->entity.liste[1].points[3]}, (int []){20, 16}, player->entity.texture);
    init_face(&player->entity.liste[1].face[5], (t_pos *[]){&player->entity.liste[1].points[5], &player->entity.liste[1].points[4],\
    &player->entity.liste[1].points[6],&player->entity.liste[1].points[7]}, (int []){28, 16}, player->entity.texture);
}

void    set_head(t_player *player)
{
    update_head_points(player);
    set_head_face(player);
} 