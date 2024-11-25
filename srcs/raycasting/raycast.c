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

void	cast_ray(t_core *core, int i)
{
	float pa;
	
	pa = atan2(core->player.view.dx, core->player.view.dy);
	
	

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
