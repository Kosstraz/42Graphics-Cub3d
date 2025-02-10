/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:47:27 by bama              #+#    #+#             */
/*   Updated: 2025/02/10 14:49:10 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_occurence(const char *str, const char *to_find, int i)
{
	int	j;

	j = 0;
	while (to_find[j] && str[i])
		if (to_find[j++] != str[i++])
			return (0);
	if (to_find[j] && !str[i])
		return (0);
	return (1);
}

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t	i;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	if (ft_strlen(to_find) > ft_strlen(str))
		return (NULL);
	while (str[i])
	{
		if (find_occurence(str, to_find, i) == 1)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
