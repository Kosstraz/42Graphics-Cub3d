/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:05:35 by mkhoury           #+#    #+#             */
/*   Updated: 2024/12/04 20:52:09 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rectangle(float distance, int x, t_core *core)
{
	int	i;
	int	j;
	int	nb_pixel;

	i = 0;
	nb_pixel = (int) ( + 10.f / distance);
	while (i < 20)
	{
		j = 0;
		while ( j < nb_pixel)
		{
			draw_pixel(x - 10 + i, j + (core->imgs.cast->height / 2.f) - core->player[LOCAL].offset + nb_pixel, 0xff0000ff, &core->layer[CAST_LAYER]);
			j++;
		}
		
		i++;
	}
	
}
