/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:49:26 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/09 12:00:28 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/*
**	InOrder traversal:
**	- Causes all the nodes to be visited in ascending order
**	- If we want to create a sorted list of the data in a binary tree,
**    this is one way to do it.
**	1. Call itself to traverse the node's left subtree
**	2. Visit the node
**	3. Call itself to traverse the node's right subtree
**	(Left - Root - Right)
**	|
**	|				A
**	|			B		C
**	|		  D   E   R   S
**	|	     F G L
**	|
**	> Infix: F, D, G, B, L, E, A, R, C, S
*/

void	btree_apply_infix(t_btree *root, void (*applyf)())
{
	if (!root)
		return ;
	btree_apply_infix(root->left, applyf);
	applyf(root->item);
	btree_apply_infix(root->right, applyf);
}
