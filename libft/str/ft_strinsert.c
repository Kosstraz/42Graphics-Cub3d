/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:58:20 by bama              #+#    #+#             */
/*   Updated: 2024/11/17 17:27:44 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strinsert(char *str, const char *insert_, int at)
{
	char	*ret;
	int		size;
	int		i;

	if (!insert_ || !insert_[0])
		return (str);
	i = 0;
	size = ft_strlen(str) + ft_strlen(insert_);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	while (i < at)
	{
		ret[i] = str[i];
		i++;
	}
	while (i - at < (int)ft_strlen(insert_))
	{
		ret[i] = insert_[i - at];
		i++;
	}
	while (at < (int)ft_strlen(str))
		ret[i++] = str[at++];
	ret[i] = 0;
	return (ret);
}

char	*ft_strfinsert(char *str, const char *insert_, int at)
{
	char	*ret;
	int		size;
	int		i;

	if (!insert_ || !insert_[0])
		return (str);
	i = 0;
	size = ft_strlen(str) + ft_strlen(insert_);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	while (i < at)
	{
		ret[i] = str[i];
		i++;
	}
	while (i - at < (int)ft_strlen(insert_))
	{
		ret[i] = insert_[i - at];
		i++;
	}
	while (i < size)
		ret[i++] = str[at++];
	ret[i] = 0;
	return (free(str), ret);
}
