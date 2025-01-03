/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:32:22 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/03 18:29:32 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_angles(t_component *component, t_pos local)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		component->angle[i] = get_angle(component->points[i].x\
		 - local.x, component->points[i].y - local.y);
		i++;
	}
}

int	set_distance(t_component *component, t_pos local)
{
	int	i;
	int	min_index;

	i = 0;
	min_index = 0;
	while (i < 8)
	{
		component->distance[i] = sqrtf((component->points->x - local.x) * (component->points->x  - local.x)\
		+ (component->points->y - local.y) * (component->points->y - local.y));
		if (component->distance[i] < component->distance[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

void    draw_player(t_core *core, t_player *distant, t_player *local)
{
	int	i;
	int	distances[6][3];

	i = 0;
	while (i < 6)
	{
		distances[i][0] = i;
		distances[i][1] = set_distance(&distant->entity.liste[i], local->position);
		distances[i][2] = distant->entity.liste[i].distance[distances[i][1]];
		i++;
	}
	sort_distance(&distances);
	i = 0;
	while (i < 6)
	{
		draw_component(distant->entity.liste[distances[i][0]], distances[i][1], core);
		i++;
	}
}
