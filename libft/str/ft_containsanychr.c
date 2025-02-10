/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containsanychr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:27:47 by bama              #+#    #+#             */
/*   Updated: 2025/02/10 14:46:10 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_containonlychr(const char *str, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	set_size;

	i = 0;
	set_size = ft_strlen(set);
	while (str[i])
	{
		j = 0;
		while (set[j] && str[i] != set[j++])
			;
		if (j == set_size)
			return (0);
		i++;
	}
	return (1);
}

char	ft_containonlychr_until(const char *str, const char *set, char c)
{
	size_t	i;
	size_t	j;
	size_t	set_size;

	i = 0;
	set_size = ft_strlen(set);
	while (str[i] && str[i] != c)
	{
		j = 0;
		while (set[j] && str[i] != set[j++])
			;
		if (j == set_size)
			return (0);
		i++;
	}
	return (1);
}

ssize_t	ft_containsanychr(const char *str, const char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (set[j])
		{
			if (str[i] == set[j])
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

char	ft_isanychr(const char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
