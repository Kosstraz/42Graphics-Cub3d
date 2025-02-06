/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_applyptr_suffix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:34:56 by ymanchon          #+#    #+#             */
/*   Updated: 2025/02/05 14:31:20 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_applyptr_suffix(t_btree **root, void (*applyf)(int))
{
	if (root && *root)
	{
		btree_applyptr_suffix((*root)->left, applyf);
		btree_applyptr_suffix((*root)->right, applyf);
		applyf(&(*root)->item);
	}
}
