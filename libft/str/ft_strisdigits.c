/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 00:03:13 by bama              #+#    #+#             */
/*   Updated: 2024/11/17 17:27:48 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 0 : no only digits
// 1 : only digits
char	ft_strisdigits(const char *str)
{
	size_t	i;

	i = 0ULL;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}
