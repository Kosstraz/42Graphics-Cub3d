/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:10:35 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/18 23:09:57 by ymanchon         ###   ########.fr       */
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

char	*ft_strchr_inv(const char *str, const char c)
{
	unsigned long	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
		if (str[i++] != c)
			return ((char *)&(str[i - 1]));
	if (c == 0)
		return ((char *)&(str[i]));
	return (NULL);
}
