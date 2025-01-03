/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:08:44 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/03 18:24:58 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	swapp_index(int *a[3], int *b[3])
{
	int	temp;
	int	i;

	i = 0;
	while (i < 3)
	{
		temp = *a[i];
		*a[i] = *b[i];
		*b[i] = temp;
		i++;
	}
}

void	sort_distance(int *tbl[6][3])
{
	int	i;
	int	j;
	int	tmp[3];

	i = 0;
	while (i < 6)
	{
		j = i + 1;
		while (j < 6)
		{
			if (tbl[i][2] < tbl[j][2])
				swapp_index(&tbl[i], &tbl[j]);
			j++;
		}
		i++;
	}
}
int	get_x(float angle_j, float *angles, int lim)
{
	int	i;
	float	delta;
	int		index;
	float	dist;

	i = 0;
	dist = 3;
	while (i < lim)
	{
		if (angle_j > angles[i])
			delta = angle_j  - angles[i];
		else
			delta = angles[i] - angle_j;
		if (delta < dist)
		{
			index = i;
			dist = delta;
		}
		i++;
	}
	if (dist == 3)
		return (-1);
	return (index);
}
