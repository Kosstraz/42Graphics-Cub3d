/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:36:54 by ymanchon          #+#    #+#             */
/*   Updated: 2025/02/05 14:31:51 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_insert_data(t_btree **root, int item,
			int (*cmpf)(int, int))
{
	int	cmp;

	if (!root || !*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	cmp = cmpf(item, (*root)->item);
	if (cmp < 0)
		btree_insert_data(&(*root)->left, item, cmpf);
	else if (cmp >= 0)
		btree_insert_data(&(*root)->right, item, cmpf);
}
