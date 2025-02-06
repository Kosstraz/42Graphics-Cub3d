/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:02:41 by ymanchon          #+#    #+#             */
/*   Updated: 2025/02/06 16:03:14 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	no_full_file(bool is_here[6])
{
	int	count;
	int	i;

	i = H_NO;
	count = 0;
	while (i <= H_WE)
	{
		if (is_here[i])
			++count;
		++i;
	}
	if (count > 0 && count < 4)
		return (TRUE);
	return (FALSE);
}

bool	no_full_cf(bool is_here[6])
{
	int	count;

	count = 0;
	count += is_here[H_F];
	count += is_here[H_C];
	if (count > 0 && count < 2)
		return (TRUE);
	return (FALSE);
}

bool	is_here_is_valid(bool is_here[6])
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!is_here[i])
			return (FALSE);
		++i;
	}
	return (TRUE);
}

void	init_is_here(bool is_here[6])
{
	is_here[0] = FALSE;
	is_here[1] = FALSE;
	is_here[2] = FALSE;
	is_here[3] = FALSE;
	is_here[4] = FALSE;
	is_here[5] = FALSE;
}
