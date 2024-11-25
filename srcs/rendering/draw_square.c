/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:32:18 by mkhoury           #+#    #+#             */
/*   Updated: 2024/11/25 15:38:38 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(mlx_image_t *image, t_pos a, t_color_type color)
{
	int		i;
	int		j;
	double	x;
	double	y;

	i = 0;
	y = a.y - 2;
	while (i < 5)
	{
		x = a.x - 2;
		j = 0;
		while (j < 5)
		{
			mlx_put_pixel(image, x, y, color);
			x++;
			j++;
		}
		y++;
		i++;
	}
}
