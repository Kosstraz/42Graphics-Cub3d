/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_face_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:16:47 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/06 17:48:03 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_face_extra(t_screenp points[4], t_face face, t_core *core)
{
	int	delta_y;
	int	i;
	int	sign;

	delta_y = points[2].y - points[0].y;
	if (delta_y < 0)
		sign = -1;
	else
		sign = 1;
	while (points[0].y < abs)
	{
		/* code */
	}
	
}