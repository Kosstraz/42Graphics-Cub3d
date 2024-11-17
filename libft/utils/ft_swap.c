/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:50:38 by bama              #+#    #+#             */
/*   Updated: 2024/11/17 17:26:47 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap64(long long *a, long long *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void	ft_swap32(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void	ft_swap16(short *a, short *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void	ft_swap8(char *a, char *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
