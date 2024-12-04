/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deg2rad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:12:53 by mkhoury           #+#    #+#             */
/*   Updated: 2024/12/04 20:49:52 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	deg2rad(float deg)
{
	return (deg / 180.f * PI);
}

float	rad2deg(float rad)
{
	return (rad / PI * 180.f);
}

float	modulo_float(float nb, float mod)
{
	nb -= mod * fabsf(nb /  mod);
	if (nb >= 0.f)
		return (nb);
	return (nb + mod);
}


float	get_angle(float dx, float dy)
{
	float	x;

	if (dx < 0 && dy < 0)
		return (rad2deg(atanf(dy / dx)) + 180.f);
	if (dx < 0 && dy > 0)
	{
		x = -dx;
		return (180.f - rad2deg(atanf(dy / x)));
	}
	if (dy < 0)
		return (360.f - rad2deg(atanf(-dy / dx)));
	return (rad2deg(atanf(dy / dx)));
}
