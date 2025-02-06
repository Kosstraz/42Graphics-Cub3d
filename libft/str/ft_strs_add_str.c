/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_add_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:01:28 by bama              #+#    #+#             */
/*   Updated: 2025/02/05 14:24:54 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strs_add_str(char ***strs, char *str)
{
	size_t	i;
	char	**new;

	i = 0;
	while ((*strs)[i])
		i++;
	new = (char **)malloc(sizeof(char *) * (i + 3));
	if (!new)
		return ;
	i = 0;
	while ((*strs)[i])
	{
		new[i] = (*strs)[i];
		i++;
	}
	new[i++] = ft_strdup(str);
	new[i] = NULL;
	*strs = new;
}
	//free(*strs);
