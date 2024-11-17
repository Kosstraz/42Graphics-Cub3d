/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:05:04 by bama              #+#    #+#             */
/*   Updated: 2024/11/17 17:27:37 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strerase(char **buffer, const char *insert, int at, int len)
{
	int	i;

	i = 0;
	while (insert[i] && i < len)
		(*buffer)[at++] = insert[i++];
	while (i++ < len)
		(*buffer)[at++] = 0;
}
