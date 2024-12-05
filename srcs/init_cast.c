/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:28:29 by mkhoury           #+#    #+#             */
/*   Updated: 2024/12/05 15:26:36 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cast_2(t_casting *cast)
{
	int	i;

	i = 0;
	while (i < 1920)
	{
		cast->angle[i] = 0.f;
		cast->casts[i] = 0.f;
		cast->wall[i].x = 0.f;
		cast->wall[i].y = 0.f;
		cast->wall[i].z = 0.f;
		i++;
	}
}

void	init_cast(t_casting *cast, t_player player)
{
	ft_memset(cast, 0, sizeof(t_casting));
	cast->last_pose.x = player.position.x;
	cast->last_pose.y = player.position.y;
	cast->last_pose.z = player.position.z;
	cast->last_view.dx = player.view.dx;
	cast->last_view.dy = player.view.dy;
	cast->last_view.dz = player.view.dz;
	cast->last_view.angle = player.view.angle;
	cast->di = -1.f;
	cast->hfov = FOV / 2.f;
	cast->last_width = -1;
	init_cast_2(cast);
}
