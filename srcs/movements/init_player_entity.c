// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   movement.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/11/22 18:42:44 by mkhoury           #+#    #+#             */
// /*   Updated: 2024/12/09 17:22:12 by ymanchon         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "cub3d.h"

// void    set_corps(t_player *player)
// {
//     set_point(&player->entity.corps.points[0],(float []) {25.f + player->view.angle, 0.2f, 24.f}, player->position);
//     set_point(&player->entity.corps.points[1],(float []) {165.f + player->view.angle, 0.2f, 24.f}, player->position);
//     set_point(&player->entity.corps.points[2],(float []) {205.f + player->view.angle, 0.2f, 24.f}, player->position);
//     set_point(&player->entity.corps.points[3],(float []) {335.f + player->view.angle, 0.2f, 24.f}, player->position);
//     set_point(&player->entity.corps.points[4],(float []) {25.f + player->view.angle, 0.2f, 12.f}, player->position);
//     set_point(&player->entity.corps.points[5],(float []) {165.f + player->view.angle, 0.2f, 12.f}, player->position);
//     set_point(&player->entity.corps.points[6],(float []) {205.f + player->view.angle, 0.2f, 12.f}, player->position);
//     set_point(&player->entity.corps.points[7],(float []) {335.f + player->view.angle, 0.2f, 12.f}, player->position);
//     init_face(&player->entity.corps.face[0], (t_pos *[]){&player->entity.corps.points[3], &player->entity.corps.points[4],\
//     &player->entity.corps.points[6],&player->entity.corps.points[7]}, (int []){20, 21}, player->entity.texture);
//     init_face(&player->entity.corps.face[1], (t_pos *[]){&player->entity.corps.points[3], &player->entity.corps.points[0],\
//     &player->entity.corps.points[7],&player->entity.corps.points[4]}, (int []){28, 20}, player->entity.texture);
//     init_face(&player->entity.corps.face[2], (t_pos *[]){&player->entity.corps.points[0], &player->entity.corps.points[1],\
//     &player->entity.corps.points[4],&player->entity.corps.points[5]}, (int []){32, 21}, player->entity.texture);
//     init_face(&player->entity.corps.face[3], (t_pos *[]){&player->entity.corps.points[1], &player->entity.corps.points[2],\
//     &player->entity.corps.points[5],&player->entity.corps.points[6]}, (int []){16, 20}, player->entity.texture);
//     init_face(&player->entity.corps.face[4], (t_pos *[]){&player->entity.corps.points[1], &player->entity.corps.points[0],\
//     &player->entity.corps.points[2],&player->entity.corps.points[3]}, (int []){20, 16}, player->entity.texture);
//     init_face(&player->entity.corps.face[5], (t_pos *[]){&player->entity.corps.points[5], &player->entity.corps.points[4],\
//     &player->entity.corps.points[6],&player->entity.corps.points[7]}, (int []){28, 16}, player->entity.texture);
// }

// void    init_player_entity(t_player *player)
// {
//     player->view.angle = 0.f;
// 	set_corps(player);
    
// }