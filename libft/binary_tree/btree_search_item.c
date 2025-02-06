/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:58:29 by ymanchon          #+#    #+#             */
/*   Updated: 2025/02/05 14:32:26 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*btree_infix_node(t_btree *root)
{
	if (!root)
		return (NULL);
	while (root->left)
		root = root->left;
	return (root);
}

int	btree_search_item_recu(t_btree *root, const int data_ref,
		int *nullable, int (*cmpf)(int, int))
{
	if (!root)
		return (*nullable);
	btree_search_item_recu(root->left, data_ref, nullable, cmpf);
	if (cmpf(data_ref, root->item) == 0)
	{
		*nullable = data_ref;
		return (*nullable);
	}
	btree_search_item_recu(root->right, data_ref, nullable, cmpf);
	return (*nullable);
}

int	btree_search_item(t_btree *root, const int data_ref,
		int (*cmpf)(int, int))
{
	int	ret;

	ret = 0;
	return (btree_search_item_recu(root, data_ref, &ret, cmpf));
}
