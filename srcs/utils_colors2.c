/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:00:49 by ymanchon          #+#    #+#             */
/*   Updated: 2025/02/10 15:34:24 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	stocol_while_part(t_color *col, int tmp, int i, char *val)
{
	if (!ft_containonlychr(val, "0123456789"))
	{
		col->_overflow = TRUE;
		return (FALSE);
	}
	tmp = ft_atoi(val);
	if (tmp > 255)
		col->_overflow = TRUE;
	if (i == 0)
		col->r = tmp;
	else if (i == 1)
		col->g = tmp;
	return (TRUE);
}
