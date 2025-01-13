/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:58:09 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/13 18:31:21 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    update_arml_points(t_player *player)
{
    set_point(&player->entity.liste[4][0],(float []) {8.f, 2.f, player->view.angle, 24.f}, player->position);
    set_point(&player->entity.liste[4][1],(float []) {4.f, 2.f, player->view.angle, 24.f}, player->position);
    set_point(&player->entity.liste[4][2],(float []) {4.f, -2.f, player->view.angle, 24.f}, player->position);
    set_point(&player->entity.liste[4][3],(float []) {8.f, -2.f, player->view.angle, 24.f}, player->position);
    set_point(&player->entity.liste[4][4],(float []) {8.f, 2.f, player->view.angle, 12.f}, player->position);
    set_point(&player->entity.liste[4][5],(float []) {4.f, 2.f, player->view.angle, 12.f}, player->position);
    set_point(&player->entity.liste[4][6],(float []) {4.f, -2.f, player->view.angle, 12.f}, player->position);
    set_point(&player->entity.liste[4][7],(float []) {8.f, -2.f, player->view.angle, 12.f}, player->position);
}

void    update_armr_points(t_player *player)
{
    set_point(&player->entity.liste[5][0],(float []) {-4.f, 2.f, player->view.angle, 24.f}, player->position);
    set_point(&player->entity.liste[5][1],(float []) {-8.f, 2.f, player->view.angle, 24.f}, player->position);
    set_point(&player->entity.liste[5][2],(float []) {-8.f, -2.f, player->view.angle, 24.f}, player->position);
    set_point(&player->entity.liste[5][3],(float []) {-4.f, -2.f, player->view.angle, 24.f}, player->position);
    set_point(&player->entity.liste[5][4],(float []) {-4.f, 2.f, player->view.angle, 12.f}, player->position);
    set_point(&player->entity.liste[5][5],(float []) {-8.f, 2.f, player->view.angle, 12.f}, player->position);
    set_point(&player->entity.liste[5][6],(float []) {-8.f, -2.f, player->view.angle, 12.f}, player->position);
    set_point(&player->entity.liste[5][7],(float []) {-4.f, -2.f, player->view.angle, 12.f}, player->position);
}

void    set_arml_face(t_player *player, t_core *core)
{
    init_face(&core->liste[4].face[0], (t_pos *[]){&core->liste[4].points[2], &core->liste[4].points[3],\
    &core->liste[4].points[6],&core->liste[4].points[7]}, (int []){20, 21}, core->player_texture);
    init_face(&core->liste[4].face[1], (t_pos *[]){&core->liste[4].points[3], &core->liste[4].points[0],\
    &core->liste[4].points[7], &core->liste[4].points[4]}, (int []){28, 20}, core->player_texture);
    init_face(&core->liste[4].face[2], (t_pos *[]){&core->liste[4].points[0], &core->liste[4].points[1],\
    &core->liste[4].points[4], &core->liste[4].points[5]}, (int []){32, 21}, core->player_texture);
    init_face(&core->liste[4].face[3], (t_pos *[]){&core->liste[4].points[1], &core->liste[4].points[2],\
    &core->liste[4].points[5], &core->liste[4].points[6]}, (int []){16, 20}, core->player_texture);
    init_face(&core->liste[4].face[4], (t_pos *[]){&core->liste[4].points[1], &core->liste[4].points[0],\
    &core->liste[4].points[2], &core->liste[4].points[3]}, (int []){20, 16}, core->player_texture);
    init_face(&core->liste[4].face[5], (t_pos *[]){&core->liste[4].points[5], &core->liste[4].points[4],\
    &core->liste[4].points[6], &core->liste[4].points[7]}, (int []){28, 16}, core->player_texture);
}

void    set_armr_face(t_player *player, t_core *core)
{
    init_face(&core->liste[5].face[0], (t_pos *[]){&core->liste[5].points[2], &core->liste[5].points[3],\
    &core->liste[5].points[6], &core->liste[5].points[7]}, (int []){20, 21}, core->player_texture);
    init_face(&core->liste[5].face[1], (t_pos *[]){&core->liste[5].points[3], &core->liste[5].points[0],\
    &core->liste[5].points[7], &core->liste[5].points[4]}, (int []){28, 20}, core->player_texture);
    init_face(&core->liste[5].face[2], (t_pos *[]){&core->liste[5].points[0], &core->liste[5].points[1],\
    &core->liste[5].points[4], &core->liste[5].points[5]}, (int []){32, 21}, core->player_texture);
    init_face(&core->liste[5].face[3], (t_pos *[]){&core->liste[5].points[1], &core->liste[5].points[2],\
    &core->liste[5].points[5], &core->liste[5].points[6]}, (int []){16, 20}, core->player_texture);
    init_face(&core->liste[5].face[4], (t_pos *[]){&core->liste[5].points[1], &core->liste[5].points[0],\
    &core->liste[5].points[2], &core->liste[5].points[3]}, (int []){20, 16}, core->player_texture);
    init_face(&core->liste[5].face[5], (t_pos *[]){&core->liste[5].points[5], &core->liste[5].points[4],\
    &core->liste[5].points[6], &core->liste[5].points[7]}, (int []){28, 16}, core->player_texture);
}

void    set_arms(t_player *player, t_core *core)
{
	update_arml_points(player);
	update_armr_points(player);
	set_arml_face(player, core);
	set_armr_face(player, core);
}
