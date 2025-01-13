/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_legs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:20:41 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/13 19:01:33 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    update_legl_points(t_player *player)
{
    set_point(&player->entity.liste[2][0],(float []) {8.f, 2.f, player->view.angle, 12.f}, player->position);
    set_point(&player->entity.liste[2][1],(float []) {4.f, 2.f, player->view.angle, 12.f}, player->position);
    set_point(&player->entity.liste[2][2],(float []) {4.f, -2.f, player->view.angle, 12.f}, player->position);
    set_point(&player->entity.liste[2][3],(float []) {8.f, -2.f, player->view.angle, 12.f}, player->position);
    set_point(&player->entity.liste[2][4],(float []) {8.f, 2.f, player->view.angle, 0.f}, player->position);
    set_point(&player->entity.liste[2][5],(float []) {4.f, 2.f, player->view.angle, 0.f}, player->position);
    set_point(&player->entity.liste[2][6],(float []) {4.f, -2.f, player->view.angle, 0.f}, player->position);
    set_point(&player->entity.liste[2][7],(float []) {8.f, -2.f, player->view.angle, 0.f}, player->position);
}

void    update_legr_points(t_player *player)
{
    set_point(&player->entity.liste[3][0],(float []) {-4.f, 2.f, player->view.angle, 12.f}, player->position);
    set_point(&player->entity.liste[3][1],(float []) {-8.f, 2.f, player->view.angle, 12.f}, player->position);
    set_point(&player->entity.liste[3][2],(float []) {-8.f, -2.f, player->view.angle, 12.f}, player->position);
    set_point(&player->entity.liste[3][3],(float []) {-4.f, -2.f, player->view.angle, 12.f}, player->position);
    set_point(&player->entity.liste[3][4],(float []) {-4.f, 2.f, player->view.angle, 0.f}, player->position);
    set_point(&player->entity.liste[3][5],(float []) {-8.f, 2.f, player->view.angle, 0.f}, player->position);
    set_point(&player->entity.liste[3][6],(float []) {-8.f, -2.f, player->view.angle, 0.f}, player->position);
    set_point(&player->entity.liste[3][7],(float []) {-4.f, -2.f, player->view.angle, 0.f}, player->position);
}

void    set_legl_face(t_player *player, t_core *core)
{
    init_face(&core->liste[2].face[0], (t_pos *[]){&core->liste[2].points[2], &core->liste[2].points[3],\
    &core->liste[2].points[6],&core->liste[2].points[7]}, (int []){20, 21}, core->player_texture);
    init_face(&core->liste[2].face[1], (t_pos *[]){&core->liste[2].points[3], &core->liste[2].points[0],\
    &core->liste[2].points[7],&core->liste[2].points[4]}, (int []){28, 20}, core->player_texture);
    init_face(&core->liste[2].face[2], (t_pos *[]){&core->liste[2].points[0], &core->liste[2].points[1],\
    &core->liste[2].points[4],&core->liste[2].points[5]}, (int []){32, 21}, core->player_texture);
    init_face(&core->liste[2].face[3], (t_pos *[]){&core->liste[2].points[1], &core->liste[2].points[2],\
    &core->liste[2].points[5],&core->liste[2].points[6]}, (int []){16, 20}, core->player_texture);
    init_face(&core->liste[2].face[4], (t_pos *[]){&core->liste[2].points[1], &core->liste[2].points[0],\
    &core->liste[2].points[2],&core->liste[2].points[3]}, (int []){20, 16}, core->player_texture);
    init_face(&core->liste[2].face[5], (t_pos *[]){&core->liste[2].points[5], &core->liste[2].points[4],\
    &core->liste[2].points[6],&core->liste[2].points[7]}, (int []){28, 16}, core->player_texture);
}

void    set_legr_face(t_player *player, t_core *core)
{
    init_face(&core->liste[3].face[0], (t_pos *[]){&core->liste[3].points[2], &core->liste[3].points[3],\
    &core->liste[3].points[6],&core->liste[3].points[7]}, (int []){20, 21}, core->player_texture);
    init_face(&core->liste[3].face[1], (t_pos *[]){&core->liste[3].points[3], &core->liste[3].points[0],\
    &core->liste[3].points[7],&core->liste[3].points[4]}, (int []){28, 20}, core->player_texture);
    init_face(&core->liste[3].face[2], (t_pos *[]){&core->liste[3].points[0], &core->liste[3].points[1],\
    &core->liste[3].points[4],&core->liste[3].points[5]}, (int []){32, 21}, core->player_texture);
    init_face(&core->liste[3].face[3], (t_pos *[]){&core->liste[3].points[1], &core->liste[3].points[2],\
    &core->liste[3].points[5],&core->liste[3].points[6]}, (int []){16, 20}, core->player_texture);
    init_face(&core->liste[3].face[4], (t_pos *[]){&core->liste[3].points[1], &core->liste[3].points[0],\
    &core->liste[3].points[2],&core->liste[3].points[3]}, (int []){20, 16}, core->player_texture);
    init_face(&core->liste[3].face[5], (t_pos *[]){&core->liste[3].points[5], &core->liste[3].points[4],\
    &core->liste[3].points[6],&core->liste[3].points[7]}, (int []){28, 16}, core->player_texture);
}

void    set_legs(t_player *player, t_core *core)
{
	update_legl_points(player);
	update_legr_points(player);
	set_legl_face(player, core);
	set_legr_face(player, core);
}
