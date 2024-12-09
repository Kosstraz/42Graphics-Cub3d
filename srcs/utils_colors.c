/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:00:49 by ymanchon          #+#    #+#             */
/*   Updated: 2024/12/09 13:30:31 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color_type	increase_lighting(t_color_type col, int by)
{
	t_color_type	ret;
	int 			r;
	int				g;
	int				b;

	r = (col & 0x000000FF);
	g = (col & 0x0000FF00) >> 8;
	b = (col & 0x00FF0000) >> 16;
	if (r + by > 255)
		r = 255;
	else if (r + by < 0)
		r = 0;
	else
		r += by;
	if (g + by > 255)
		g = 255;
	else if (g + by < 0)
		g = 0;
	else
		g += by;
	if (b + by > 255)
		b = 255;
	else if (b + by < 0)
		b = 0;
	else
		b += by;
	ret = (col & 0xFF000000)
		| (b << 16)
		| (g << 8)
		| (r);
	return (ret);
}

int	invbits(int col)
{
	return (((col & 0xff000000) >> 24)
			| ((col & 0x00ff0000) >> 8)
			| ((col & 0x0000ff00) << 8)
			| ((col & 0x000000ff) << 24));
}

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

uint32_t	coltoui(t_color c)
{
	uint32_t	ret;
	ret = (0xff000000)
		| (c.b << 16)
		| (c.g << 8)
		| (c.r);
	return (ret);
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
