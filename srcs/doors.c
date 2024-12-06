/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:46:15 by ymanchon          #+#    #+#             */
/*   Updated: 2024/12/06 15:24:00 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	vector_norm(float x, float y)
{
	return (sqrtf(x * x + y * y));
}

void	door_handling(t_core *core)
{
	uint32_t	i;
	t_pos		wallp;
	BOOL		door;

	i = 0;
	door = FALSE;
	while (i < 1920)
	{
		wallp.x = core->cast.wall[i].x;
		wallp.y = core->cast.wall[i].y;
		if (core->map.buf[(int)(wallp.y + 0.5f)][(int)(wallp.x + 0.5f)] == 'P'
			&& (fabsf(vector_norm(wallp.x + 0.5f, wallp.y + 0.5f) - vector_norm(core->player[LOCAL].position.x, core->player[LOCAL].position.y))) <= 1.6f)
		{
			door = TRUE;
			break ;
		}
		i++;
	}
	if (door)
		core->utils.door_text[TO_OPEN]->enabled = TRUE;
	else
		core->utils.door_text[TO_OPEN]->enabled = FALSE;
}
