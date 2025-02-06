/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:16:09 by mkhoury           #+#    #+#             */
/*   Updated: 2025/02/05 14:44:22 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_x(float angle_j, float *angles, int lim)
{
	int		i;
	float	delta;
	int		index;
	float	dist;

	i = -1;
	dist = 3;
	index = 0;
	while (++i < lim)
	{
		if (angle_j > angles[i])
			delta = angle_j - angles[i];
		else
			delta = angles[i] - angle_j;
		if (delta < dist)
		{
			index = i;
			dist = delta;
		}
		if (dist <= 0.5)
			return (index);
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

void	draw_face(t_core *core, t_face face)
{
	int		index1;
	int		index2;

	index1 = get_x(face.angle1, core->cast.angle, core->imgs.cast->width);
	index2 = get_x(face.angle2, core->cast.angle, core->imgs.cast->width);
	if (index1 == -1 || index2 == -1)
		return ;
	draw_rectangle3((int []){index1, index2}, \
	(float []){face.length1, face.length2}, face.side, core);
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
	if (get_distance(core->player[LOCAL].position, \
	core->player[DISTANT].position) < 0.2f)
		return ;
	if (joueur_visible(core, &joueur_distant) == false)
		return ;
	set_distance(&joueur_distant, core->player[LOCAL]);
	draw_corps(core, &joueur_distant);
}
