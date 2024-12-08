/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:00:49 by ymanchon          #+#    #+#             */
/*   Updated: 2024/12/08 12:39:07 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color_type	increase_lighting(t_color_type col, int by)
{
    t_color_type ret;
    int r, g, b;

    // Extraire les composantes ABGR
    r = (col & 0x000000FF);
    g = (col & 0x0000FF00) >> 8;
    b = (col & 0x00FF0000) >> 16;

    // Augmenter les composantes RGB avec clamping à 255
    r = (r + by > 255) ? 255 : (r + by);
    g = (g + by > 255) ? 255 : (g + by);
    b = (b + by > 255) ? 255 : (b + by);

    // Reconstruire la couleur avec le même canal Alpha
    ret = (col & 0xFF000000) // Conserve Alpha
        | (b << 16)          // Ajoute Blue
        | (g << 8)           // Ajoute Green
        | r;                 // Ajoute Red
	//t_color_type	ret;
//
	//ret = col;
	//if (((ret >> 16) & 0xff) + by > 255)
	//	ret = (ret) | 0x00ff0000;
	//else if (((ret >> 8) & 0xff) + by > 255)
	//	ret = (ret) | 0x0000ff00;
	//else if ((ret & 0xff) + by > 255)
	//	ret = (ret) | 0x000000ff;
	//ret = (ret & 0xff000000)
	//	| ((ret & 0x00ff0000) + (by << 16))
	//	| ((ret & 0x0000ff00) + (by << 8))
	//	| ((ret & 0x000000ff) + (by));//(by << 24) | (ret & 0x00ffffff);
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
