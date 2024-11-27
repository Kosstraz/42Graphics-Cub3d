/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:00:49 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/27 15:19:26 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

	// char[3] to color
t_color	ctocol(t_uchar r, t_uchar g, t_uchar b)
{
	t_color	ret;
	ret.r = r;
	ret.g = g;
	ret.b = b;
	ret._overflow = FALSE;
	return (ret);
}

	// color to int (hexa val) 0xRRGGBBAA with A=f
unsigned int	coltohexa(t_color col)
{
	return (
		(col.r << 16)
		| (col.g << 8)
		| (col.b << 4)
		| (0x000000ff & 0xff)
	);
}

t_color	stocol(const char *str)
{
	size_t	i;
	char	**split;
	int		tmp;
	t_color	ret;

	ret._overflow = FALSE;
	split = ft_split(str, ',');
	i = 0;
	while (split[i])
	{
		tmp = ft_atoi(split[i]);
		if (tmp > 255)
			ret._overflow = TRUE;
		i++;
	}

	ft_dfree((void **)split);
	ret.bytes_wrote = i;
	ret.b = tmp;
	return (ret);
}

//F 123, 456, 789
//C 987, 654, 321
