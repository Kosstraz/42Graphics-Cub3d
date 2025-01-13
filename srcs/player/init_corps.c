/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_corps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:09:50 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/13 18:35:55 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    update_corps_points(t_player *player)
{
    set_point(&player->entity.liste[0][0],(float []) {4.f, 2.f, player->view.angle, 24.f}, player->position);
    set_point(&player->entity.liste[0][1],(float []) {-4.f, 2.f, player->view.angle, 24.f}, player->position);
    set_point(&player->entity.liste[0][2],(float []) {-4.f, -2.f, player->view.angle, 24.f}, player->position);
    set_point(&player->entity.liste[0][3],(float []) {4.f, -2.f, player->view.angle, 24.f}, player->position);
    set_point(&player->entity.liste[0][4],(float []) {4.f, 2.f, player->view.angle, 12.f}, player->position);
    set_point(&player->entity.liste[0][5],(float []) {-4.f, 2.f, player->view.angle, 12.f}, player->position);
    set_point(&player->entity.liste[0][6],(float []) {-4.f, -2.f, player->view.angle, 12.f}, player->position);
    set_point(&player->entity.liste[0][7],(float []) {4.f, -2.f, player->view.angle, 12}, player->position);
}

void    set_corps_face(t_player *player, t_core *core)
{
    init_face(&core->liste[0].face[0], (t_pos *[]){&core->liste[0].points[2], &core->liste[0].points[3],\
    &core->liste[0].points[6],&core->liste[0].points[7]}, (int []){20, 21}, core->player_texture);
    init_face(&core->liste[0].face[1], (t_pos *[]){&core->liste[0].points[3], &core->liste[0].points[0],\
    &core->liste[0].points[7],&core->liste[0].points[4]}, (int []){28, 20}, core->player_texture);
    init_face(&core->liste[0].face[2], (t_pos *[]){&core->liste[0].points[0], &core->liste[0].points[1],\
    &core->liste[0].points[4],&core->liste[0].points[5]}, (int []){32, 21}, core->player_texture);
    init_face(&core->liste[0].face[3], (t_pos *[]){&core->liste[0].points[1], &core->liste[0].points[2],\
    &core->liste[0].points[5],&core->liste[0].points[6]}, (int []){16, 20}, core->player_texture);
    init_face(&core->liste[0].face[4], (t_pos *[]){&core->liste[0].points[1], &core->liste[0].points[0],\
    &core->liste[0].points[2],&core->liste[0].points[3]}, (int []){20, 16}, core->player_texture);
    init_face(&core->liste[0].face[5], (t_pos *[]){&core->liste[0].points[5], &core->liste[0].points[4],\
    &core->liste[0].points[6],&core->liste[0].points[7]}, (int []){28, 16}, core->player_texture);
}

void    set_corps(t_player *player, t_core *core)
{
    update_corps_points(player);
    set_corps_face(player, core);
}
