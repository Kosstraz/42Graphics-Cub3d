/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:10:35 by ymanchon          #+#    #+#             */
/*   Updated: 2024/08/07 16:33:51 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, const char c)
{
	unsigned long	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
		if (str[i++] == c)
			return ((char *)&(str[i - 1]));
	if (c == 0)
		return ((char *)&(str[i]));
	return (NULL);
}
