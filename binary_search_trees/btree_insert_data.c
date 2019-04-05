/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:42:02 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/09 12:15:40 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/*
**	Inserting data into its correct position!
**	- If we've passed in an empty tree, put the new node at root and then return
**	- If item is LESS than the item in the current node...
**		- ... IF the left node already exists, go LEFT
**		- Else, put the new node as the left node.
**	- ELSE,
**		- IF the RIGHT node already exists, go RIGHT
**		- Else, put the new node as the right node.
*/

void	btree_insert_data(t_btree **root, char *item, int (*cmpf)())
{
	t_btree *cursor;

	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	cursor = *root;
	if (cmpf(item, cursor->item) < 0)
	{
		if (cursor->left)
			btree_insert_data(&cursor->left, item, cmpf);
		else
			cursor->left = btree_create_node(item);
	}
	else
	{
		if (cursor->right)
			btree_insert_data(&cursor->right, item, cmpf);
		else
			cursor->right = btree_create_node(item);
	}
}
