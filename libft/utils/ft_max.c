/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:35:09 by bama              #+#    #+#             */
/*   Updated: 2025/02/05 14:35:10 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_maxul(size_t *tab, size_t size)
{
	size_t	i;
	size_t	tmp;

	tmp = tab[0];
	i = 1;
	while (i < size)
	{
		if (tmp < tab[i])
			tmp = tab[i];
		i++;
	}
	return (tmp);
}

ssize_t	ft_maxl(ssize_t *tab, size_t size)
{
	size_t	i;
	ssize_t	tmp;

	tmp = tab[0];
	i = 1;
	while (i < size)
	{
		if (tmp < tab[i])
			tmp = tab[i];
		i++;
	}
	return (tmp);
}

char	ft_maxc(char *tab, size_t size)
{
	size_t	i;
	char	tmp;

	tmp = tab[0];
	i = 1;
	while (i < size)
	{
		if (tmp < tab[i])
			tmp = tab[i];
		i++;
	}
	return (tmp);
}

int	ft_maxi(int *tab, size_t size)
{
	size_t	i;
	int		tmp;

	tmp = tab[0];
	i = 1;
	while (i < size)
	{
		if (tmp < tab[i])
			tmp = tab[i];
		i++;
	}
	return (tmp);
}

unsigned int	ft_maxui(unsigned int *tab, size_t size)
{
	size_t				i;
	unsigned int		tmp;

	tmp = tab[0];
	i = 1;
	while (i < size)
	{
		if (tmp < tab[i])
			tmp = tab[i];
		i++;
	}
	return (tmp);
}
