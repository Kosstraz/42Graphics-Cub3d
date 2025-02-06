/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_applyptr_prefix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:27:43 by ymanchon          #+#    #+#             */
/*   Updated: 2025/02/05 14:31:18 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_applyptr_prefix(t_btree **root, void (*applyf)(int))
{
	if (root && *root)
	{
		applyf(&(*root)->item);
		btree_applyptr_prefix((*root)->left, applyf);
		btree_applyptr_prefix((*root)->right, applyf);
	}
}
