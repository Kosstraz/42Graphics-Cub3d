/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_extra2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:00:20 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/29 14:02:28 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_face(t_face *face, t_entity *entity, int index1, int index2)
{
	face->angle1 = entity->corps.angle[index1];
	face->angle2 = entity->corps.angle[index2];
	face->length1 = entity->corps.distance[index1];
	face->length2 = entity->corps.distance[index2];
}

void	draw_3points_extra(t_core *core, t_entity *entity, int index)
{
	t_face	face;

	if (index == 2)
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
	else
		draw_3points_extra(core, entity, index);
}

float	get_distance(t_pos player1, t_pos player2)
{
	return (sqrtf((player1.x - player2.x) * \
	(player1.x - player2.x) + (player1.y - player2.y) \
	* (player1.y - player2.y)));
}

void	set_distance(t_entity *entity, t_player player)
{
	entity->corps.distance[0] = \
	get_distance(player.position, entity->corps.points[0]);
	entity->corps.distance[1] = \
	get_distance(player.position, entity->corps.points[1]);
	entity->corps.distance[2] = \
	get_distance(player.position, entity->corps.points[2]);
	entity->corps.distance[3] = \
	get_distance(player.position, entity->corps.points[3]);
}
