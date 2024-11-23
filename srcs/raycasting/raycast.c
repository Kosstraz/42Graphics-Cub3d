/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:19:35 by mkhoury           #+#    #+#             */
/*   Updated: 2024/11/22 18:32:32 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	get_x_wall(t_core *core)
{
	float	m;
	int		x;
	int		sign_x;

	if (core->player.view.dx = 0)
		return ();
	else if (core->player.view.dx > 0)
		sign_x = 1;
	else
		sign_x = -1;
	m = core->player.view.dy / core->player.view.dx * sign_x;
	if (core->player.view.dy > 0)
		x = (int) core->player.position.x;
	else if (core->player.view.dy == 0)
		

}

void	cast_ray(t_core *core, int i)
{
	//float angle;

	//angle = FOV / NB_RAYS * i;
	// int	x1;
	// int	y1;
	// int	x2;
	// int y2;
	// float	x_wall;
	// float	y_wall;

	// x1 = core->player.position.x;
	// y1 = core->player.position.y;
	

}

void	raycast(t_core *core)
{
	int	i;

	i = - NB_RAYS / 2;
	while (i < NB_RAYS / 2)
	{
		cast_ray(core, i);
		i++;
	}	
}
