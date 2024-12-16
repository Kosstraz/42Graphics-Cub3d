/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:16:09 by mkhoury           #+#    #+#             */
/*   Updated: 2024/12/12 14:40:53 by mkhoury          ###   ########.fr       */
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

	hit = 0.1f;
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
	return ( sqrtf((player1.x - player2.x) * (player1.x - player2.x) + (player1.y - player2.y) * (player1.y - player2.y)));
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

void	draw_texture_col(t_core *core, float y, int x, int side, int nb_pixels)
{
	int		i;
	long	pixel;
	int		y_p;
	
	i = 0;
	if (side == NO)
		pixel = 0xff00ff00;
	else if (side == SO)
		pixel = 0xffff0000;
	else if (side = WE)
		pixel = 0xff0000ff;
	else
		pixel = 0xffffffff;
	//printf("drawing col nb pixels = %i\n", nb_pixels);
	y_p =(int)(core->imgs.cast->height / 2.0f) - (int) core->player[LOCAL].offset - (int) core->player[LOCAL].bubbles ;
	i = 0;
	while (i < 10)
	{
		draw_pixel(x, y_p + i, pixel, &core->layer[CAST_LAYER]);
		//pixel = texture[(int) y][x];
		//y_p = (i - nb_pixels / 2) + (int)(core->imgs.cast->height / 2.0f) - (int) core->player[LOCAL].offset - (int) core->player[LOCAL].bubbles ;
		//draw_pixel(x, y_p , pixel, &core->layer[CAST_LAYER]);
		i++;
	}
}

void	draw_face(t_core *core, t_face face)
{
	int		delta;
	int		index1;
	int		index2;
	//int		i;
	float	dlength;
	int		nb_pixels;
	
	index1 = get_x(face.angle1, core->cast.angle, core->imgs.cast->width);
	index2 = get_x(face.angle2, core->cast.angle, core->imgs.cast->width);
	if (index1 == -1 || index2 == -1)
		return ;
	t_pos a;
	t_pos b;
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
	a.x = (float) index1;
	a.y = (float)((int)(core->imgs.cast->height / 2.0f) - (int) core->player[LOCAL].offset - (int) core->player[LOCAL].bubbles);
	b.x = (float) index2;
	b.y = (float)((int)(core->imgs.cast->height / 2.0f) - (int) core->player[LOCAL].offset - (int) core->player[LOCAL].bubbles);
	int i = 0;
	int	hei = 100 - (int)(face.length1 / 2.f);
	int	delL = (int) (face.length2 - face.length1);
	while (i < hei)
	{
		a.y++;
		b.y++;
		hei += delL * 10;
		mlx_put_line(&core->layer[CAST_LAYER], a, b , pixel);
		i++;
	}
	return ;
	//printf("index 1 = %i inde 2 = %i, delta %i\n", index1, index2, index2 - index1);
	if (index1 == -1 && index2 == -1)
	{
		//printf("a1 %f a2 %f min %f max %f\n", face.angle1, face.angle2, core->cast.angle[0], core->cast.angle[core->mlx->width] );
		//printf("indexs out of bounds\n");
	 	return ;
	}
	// delta = index2 - index1;
	// dlength = face.length1 - face.length2 / (float) delta;
	// while (i < delta)
	// {
	// 	if ((face.length1 + (float) i * dlength) < core->cast.casts[index1 + i])
	// 	{
	// 		nb_pixels = (int) (face.length1 + i * dlength) * 10;
	// 		draw_texture_col(core, (float)(i / delta), index1 + i, face.side, nb_pixels);
	// 	}
	// 	i++;
	// }
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

void	test(t_core *core)
{
	t_pos p[4];
	float	x;
	float	y;
	float hit = 10.f;
	float	angle;

	x = (int) core->half_width;
	y = (int) core->half_height;
	draw_rectangle2((int) x, (int) y, 0xfffffff, core);
	angle = core->player[LOCAL].bubbles / 10.f * 4.f * 36.f;
	p[0].x = cosf(deg2rad(45.f + angle) )* hit + x;
	p[0].y = sinf(deg2rad(45.f + angle) )* hit + y;
	p[1].x = cosf(deg2rad(135.f + angle)) * hit + x;
	p[1].y = sinf(deg2rad(135.f + angle)) * hit + y;	
	p[2].x = cosf(deg2rad(225.f + angle)) * hit + x;
	p[2].y = sinf(deg2rad(225.f + angle)) * hit + y;	
	p[3].x = cosf(deg2rad(315.f + angle)) * hit + x;
	p[3].y = sinf(deg2rad(315.f + angle)) * hit + y;
	draw_rectangle2((int) p[0].x, (int) p[0].y, 0xff00ff00, core);
	draw_rectangle2((int) p[1].x, (int) p[1].y, 0xffff0000, core);
	draw_rectangle2((int) p[2].x, (int) p[2].y, 0xff0000ff, core);
	draw_rectangle2((int) p[3].x, (int) p[3].y, 0xffff00ff, core);
}

void	draw_joueur(t_core *core)
{
	float	angle_joueurs;
	float	players_distance;
	t_entity	joueur_distant;
	int		x;
	
	float	deltay = core->player[DISTANT].position.y - core->player[LOCAL].position.y;
	float	deltax = core->player[DISTANT].position.x - core->player[LOCAL].position.x;
	//printf("delta x %f delta y %f\n",deltax , deltay);
	
	//angle_joueurs = get_angle(deltax, deltay);
	//printf("angle is %f\n", angle_joueurs);
	// test(core);
	// return ;
	set_point(&joueur_distant, core->player[DISTANT]);
	set_angle(&joueur_distant, core->player[LOCAL].position);
	if (joueur_visible(core, &joueur_distant) == false)
		return ;
	set_distance(&joueur_distant, core->player[LOCAL]);
	draw_corps(core, &joueur_distant);
	//players_distance = get_distance(core->player[LOCAL].position, core->player[DISTANT].position);
	//printf("angle avec l'autre j %i et la distance %f\n", angle_joueurs, players_distance);
	//x = get_x(angle_joueurs, core->cast.angle, core->imgs.cast->width);
	//if (x == -1)
	//	return ;
	//printf("wall %f player %f\n", core->cast.casts[x], players_distance);
	//if (core->cast.casts[x] < players_distance )
	//	return ;
	
	
}
