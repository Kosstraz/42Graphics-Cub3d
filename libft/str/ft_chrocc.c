/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrocc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 01:31:13 by bama              #+#    #+#             */
/*   Updated: 2025/02/05 14:28:43 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Compte le nombre de caractères 'chr' dans 'str'
size_t	ft_chrocc(char *str, char chr)
{
	size_t	i;
	size_t	occ;

	i = 0;
	occ = 0;
	while (str[i])
		if (str[i++] == chr)
			occ++;
	return (occ);
}
