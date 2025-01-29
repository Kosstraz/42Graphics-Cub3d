/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:16:09 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/29 13:45:43 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	joueur_visible(t_core *core, t_entity *entity)
{
	float	angle_1;
	float	angle_2;
	float	perso_angle;
	int	i;

	perso_angle = core->player->view.angle;
	angle_1 = perso_angle + core->cast.hfov;
	angle_2 = perso_angle - core->cast.hfov;
	if (angle_1 > 360)
		angle_1 = modulo_float(angle_1, 360.f);
	if (angle_2 < 0)
		angle_2 = 360 + angle_2;
	//printf("angle 1 %f angle 2 %f angle js %f angle j %f\n", angle_1, angle_2, angle_joueurs, perso_angle);
	i = 0;
	//printf("angle1 %f angle2 %f p1 %f p2 %f p3 %f p4 %f\n", angle_1, angle_2, entity->corps.angle[0], entity->corps.angle[1], entity->corps.angle[2] ,entity->corps.angle[3]);
	while (i < 4)
	{
		if (angle_1 < angle_2 && ((entity->corps.angle[i] <= angle_1 && entity->corps.angle[i] >= 0) || (entity->corps.angle[i] >= angle_2 && entity->corps.angle[i] <= 360)))
			return (true);
		if (entity->corps.angle[i] <= angle_1 && entity->corps.angle[i] >= angle_2)
			return (true);
		i++;
	}
	//printf("error angle 1 %f angle 2 %f angle js %f angle j %f\n", angle_1, angle_2, angle_joueurs, perso_angle);
	return (false);
}

void	set_angle(t_entity *entity, t_pos local)
{
	entity->corps.angle[0] = get_angle(entity->corps.points[0].x - local.x, entity->corps.points[0].y - local.y);
	entity->corps.angle[1] = get_angle(entity->corps.points[1].x - local.x, entity->corps.points[1].y - local.y);
	entity->corps.angle[2] = get_angle(entity->corps.points[2].x - local.x, entity->corps.points[2].y - local.y);
	entity->corps.angle[3] = get_angle(entity->corps.points[3].x - local.x, entity->corps.points[3].y - local.y);
}



void	set_point(t_entity *entity, t_player player)
{
	float	hit;

	hit = 0.2f;
	entity->position.x = player.position.x;
	entity->position.y = player.position.y;
	entity->position.z = player.position.z;
	entity->view.dx = player.view.dx;
	entity->view.dy = player.view.dy;
	entity->view.dz = player.view.dz;
	entity->view.angle = player.view.angle;
	entity->corps.points[0].x = cosf(deg2rad(entity->view.angle + 45.f)) * hit + entity->position.x;
	entity->corps.points[0].y = sinf(deg2rad(entity->view.angle + 45.f)) * hit + entity->position.y;
	entity->corps.points[1].x = cosf(deg2rad(entity->view.angle + 135.f)) * hit + entity->position.x;
	entity->corps.points[1].y = sinf(deg2rad(entity->view.angle + 135.f)) * hit + entity->position.y;	
	entity->corps.points[2].x = cosf(deg2rad(entity->view.angle + 225.f)) * hit + entity->position.x;
	entity->corps.points[2].y = sinf(deg2rad(entity->view.angle + 225.f)) * hit + entity->position.y;	
	entity->corps.points[3].x = cosf(deg2rad(entity->view.angle + 315.f)) * hit + entity->position.x;
	entity->corps.points[3].y = sinf(deg2rad(entity->view.angle + 315.f)) * hit + entity->position.y;
	//printf("position j x:%f y:%f\n", entity->position.x, entity->position.y);
	//printf("position p1 x:%f y:%f\n", entity->corps.points[0].x, entity->corps.points[0].y);
	//printf("position p2 x:%f y:%f\n", entity->corps.points[1].x, entity->corps.points[1].y);
	//printf("position p3 x:%f y:%f\n", entity->corps.points[2].x, entity->corps.points[2].y);
	//printf("position p4 x:%f y:%f\n", entity->corps.points[3].x, entity->corps.points[3].y);
}

float	get_distance(t_pos player1, t_pos player2)
{
	return (sqrtf((player1.x - player2.x) * (player1.x - player2.x) + (player1.y - player2.y) * (player1.y - player2.y)));
}

void	set_distance(t_entity *entity, t_player player)
{
	entity->corps.distance[0] = get_distance(player.position, entity->corps.points[0]);
	entity->corps.distance[1] = get_distance(player.position, entity->corps.points[1]);
	entity->corps.distance[2] = get_distance(player.position, entity->corps.points[2]);
	entity->corps.distance[3] = get_distance(player.position, entity->corps.points[3]);
}

int	get_x(float angle_j, float *angles, int lim)
{
	int	i;
	float	delta;
	int		index;
	float	dist;

	i = 0;
	dist = 3;
	while (i < lim)
	{
		if (angle_j > angles[i])
			delta = angle_j  - angles[i];
		else
			delta = angles[i] - angle_j;
		if (delta < dist)
		{
			index = i;
			dist = delta;
		}
		if (dist <= 0.5)
			return (index);
		i++;
	}
	if (dist == 3)
		return (-1);
	return (index);
}

int	get_indexmin(t_entity *entity)
{
	int	i;
	int	index;

	index = 0;
	i = 0;
	while (i < 4)
	{
		if (entity->corps.distance[i] < entity->corps.distance[index])
			index = i;
		i++;
	}
	return (index);
}

// void	draw_texture_col(t_core *core, float y, int x, int side, int nb_pixels)
// {
// 	int		i;
// 	long	pixel;
// 	int		y_p;
	
// 	i = 0;
// 	if (side == NO)
// 		pixel = 0xff00ff00;
// 	else if (side == SO)
// 		pixel = 0xffff0000;
// 	else if (side == WE)
// 		pixel = 0xff0000ff;
// 	else
// 		pixel = 0xffffffff;
// 	//printf("drawing col nb pixels = %i\n", nb_pixels);
// 	y_p =(int)(core->imgs.cast->height / 2.0f) - (int) core->player[LOCAL].offset - (int) core->player[LOCAL].bubbles ;
// 	i = 0;
// 	while (i < 10)
// 	{
// 		draw_pixel(x, y_p + i, pixel, &core->layer[CAST_LAYER]);
// 		//pixel = texture[(int) y][x];
// 		//y_p = (i - nb_pixels / 2) + (int)(core->imgs.cast->height / 2.0f) - (int) core->player[LOCAL].offset - (int) core->player[LOCAL].bubbles ;
// 		//draw_pixel(x, y_p , pixel, &core->layer[CAST_LAYER]);
// 		i++;
// 	}
// }

void	draw_face(t_core *core, t_face face)
{
	int		index1;
	int		index2;
	
	index1 = get_x(face.angle1, core->cast.angle, core->imgs.cast->width);
	index2 = get_x(face.angle2, core->cast.angle, core->imgs.cast->width);
	if (index1 == -1 || index2 == -1)
		return ;
	long pixel;
	if (face.side == NO)
		pixel = 0xff00ff00;
	else if (face.side == SO)
		pixel = 0xffff0000;
	else if (face.side == EA)
		pixel = 0xffffffff;
	else if (face.side == WE)
		pixel = 0xff0000ff;
	else
		pixel = 0xff000000;
	draw_rectangle3((int []){index1, index2}, (float []){face.length1, face.length2}, face.side, core);
	return;
}

void	set_face(t_face *face, t_entity *entity, int index1, int index2)
{
	face->angle1 = entity->corps.angle[index1];
	face->angle2 = entity->corps.angle[index2];
	face->length1 = entity->corps.distance[index1];
	face->length2 = entity->corps.distance[index2];
}

void	draw_3points(t_core *core, t_entity *entity, int index)
{
	t_face	face;
	
	if (index == 0)
	{
		set_face(&face, entity, 3, 0);
		face.side = EA;
		draw_face(core, face);
		set_face(&face, entity, 0, 1);
		face.side = NO;
		draw_face(core, face);
	}
	else if (index == 1)
	{
		set_face(&face, entity, 0, 1);
		face.side = NO;
		draw_face(core, face);
		set_face(&face, entity, 1, 2);
		face.side = WE;
		draw_face(core, face);
	}
	else if (index == 2)
	{
		set_face(&face, entity, 1, 2);
		face.side = WE;
		draw_face(core, face);
		set_face(&face, entity, 2, 3);
		face.side = SO;
		draw_face(core, face);
	}
	else if (index == 3)
	{
		set_face(&face, entity, 2, 3);
		face.side = SO;
		draw_face(core, face);
		set_face(&face, entity, 3, 0);
		face.side = EA;
		draw_face(core, face);
	}
}

void	draw_corps(t_core *core, t_entity *entity)
{
	int	index;

	index = get_indexmin(entity);
	draw_3points(core, entity, index);
}

void	draw_joueur(t_core *core)
{
	t_entity	joueur_distant;
	
	set_point(&joueur_distant, core->player[DISTANT]);
	set_angle(&joueur_distant, core->player[LOCAL].position);
	if (get_distance(core->player[LOCAL].position, core->player[DISTANT].position) < 0.2f)
		return ;
	if (joueur_visible(core, &joueur_distant) == false)
		return ;
	set_distance(&joueur_distant, core->player[LOCAL]);
	draw_corps(core, &joueur_distant);
}
