/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:01:11 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/19 19:29:12 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t oldsize, size_t newsize)
{
	void	*ret;

	ret = malloc(newsize);
	if (!ptr)
		return (ret);
	if (oldsize > newsize)
		oldsize = newsize;
	ret = ft_memmove(ret, ptr, oldsize);
	free(ptr);
	return (ret);
}
