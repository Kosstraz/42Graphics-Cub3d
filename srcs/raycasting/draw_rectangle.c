/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:05:35 by mkhoury           #+#    #+#             */
/*   Updated: 2024/12/11 16:18:05 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rectangle(long distance, int x, t_core *core)
{
	int	i;
	int	j;
	int	nb_pixel;

	i = 0;
	
	while (i < 20)
	{
		j = 0;
		while ( j < 10)
		{
			draw_pixel(x - 10 + i, j + (core->imgs.cast->height / 2.f) - core->player[LOCAL].offset + nb_pixel, distance, &core->layer[CAST_LAYER]);
			j++;
		}
		
		i++;
	}
	
}

void	draw_rectangle2(int x, int y, long color, t_core *core)
{
	int	i;
	int	j;
	
	//draw_pixel(x , y, color, &core->layer[CAST_LAYER]);
	//return ;
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			if (i >= 0 && i <= core->layer[CAST_LAYER].height && j >= 0 && j <= core->layer[CAST_LAYER].width)
				draw_pixel(x - 10 + j, y + i - 10, color, &core->layer[CAST_LAYER]);
			j++;
		}
		i++;
	}
	
}
