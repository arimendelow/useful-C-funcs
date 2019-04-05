/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:49:26 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/09 12:00:22 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/*
**	Preorder traversal:
**	1. Visit the node.
**	2. Call itself to traverse the node's left subtree.
**	3. Call itself to traverse the node's right subtree.
**	(Root - Left - Right)
**	|
**	|				A
**	|			B		C
**	|		  D   E   R   S
**	|	     F G L
**	|
**	> Prefix: A, B, D, F, G, E, L, C, R, S
*/

void	btree_apply_prefix(t_btree *root, void (*applyf)())
{
	if (!root)
		return ;
	applyf(root->item);
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
}
