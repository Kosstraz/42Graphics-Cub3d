/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_strjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:01:38 by bama              #+#    #+#             */
/*   Updated: 2024/11/17 17:42:29 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

char	*ft_va_strjoin(size_t count, ...)
{
	char	*ret;
	size_t	i;
	va_list	va;

	va_start(va, count);
	i = 0;
	if (count == 0)
		return (NULL);
	ret = ft_strdup(va_arg(va, char *));
	while (i++ < count)
		ret = ft_strfjoin(ret, va_arg(va, char *));
	va_end(va);
	return (ret);
}

char	*ft_va_strfjoin(size_t count, ...)
{
	char	*ret;
	char	*arg;
	size_t	i;
	va_list	va;

	va_start(va, count);
	if (count == 0)
		return (NULL);
	ret = ft_strfdup(va_arg(va, char *));
	i = 0;
	count--;
	arg = va_arg(va, char *);
	while (arg && i++ < count)
	{
		ret = ft_strffjoin(ret, arg);
		arg = va_arg(va, char *);
	}
	va_end(va);
	return (ret);
}
