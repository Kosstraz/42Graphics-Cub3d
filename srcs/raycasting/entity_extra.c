/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:48:22 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/29 14:04:59 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_ok(float angle_1, float angle_2, t_entity *entity, int i)
{
	if (angle_1 < angle_2 && ((entity->corps.angle[i] <= angle_1 \
	&& entity->corps.angle[i] >= 0) \
	|| (entity->corps.angle[i] >= angle_2 \
	&& entity->corps.angle[i] <= 360)))
		return (true);
	if (entity->corps.angle[i] <= angle_1 && \
	entity->corps.angle[i] >= angle_2)
		return (true);
	return (false);
}

bool	joueur_visible(t_core *core, t_entity *entity)
{
	float	angle_1;
	float	angle_2;
	float	perso_angle;
	int		i;

	perso_angle = core->player->view.angle;
	angle_1 = perso_angle + core->cast.hfov;
	angle_2 = perso_angle - core->cast.hfov;
	if (angle_1 > 360)
		angle_1 = modulo_float(angle_1, 360.f);
	if (angle_2 < 0)
		angle_2 = 360 + angle_2;
	i = 0;
	while (i < 4)
	{
		if (is_ok(angle_1, angle_2, entity, i) == true)
			return (true);
		i++;
	}
	return (false);
}

void	set_angle(t_entity *entity, t_pos local)
{
	entity->corps.angle[0] = \
	get_angle(entity->corps.points[0].x \
	- local.x, entity->corps.points[0].y - local.y);
	entity->corps.angle[1] = \
	get_angle(entity->corps.points[1].x \
	- local.x, entity->corps.points[1].y - local.y);
	entity->corps.angle[2] = \
	get_angle(entity->corps.points[2].x \
	- local.x, entity->corps.points[2].y - local.y);
	entity->corps.angle[3] = \
	get_angle(entity->corps.points[3].x \
	- local.x, entity->corps.points[3].y - local.y);
}

void	set_point(t_entity *entity, t_player player)
{
	float	hit;
	int		i;

	hit = 0.2f;
	entity->position.x = player.position.x;
	entity->position.y = player.position.y;
	entity->position.z = player.position.z;
	entity->view.dx = player.view.dx;
	entity->view.dy = player.view.dy;
	entity->view.dz = player.view.dz;
	entity->view.angle = player.view.angle;
	i = 0;
	while (i < 4)
	{
		entity->corps.points[i].x = \
		cosf(deg2rad(entity->view.angle + 45.f + 90.f * i)) \
		* hit + entity->position.x;
		entity->corps.points[i].y = \
		sinf(deg2rad(entity->view.angle + 45.f + 90.f * i)) \
		* hit + entity->position.y;
		i++;
	}
}
