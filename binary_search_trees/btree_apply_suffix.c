/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:49:26 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/09 13:02:07 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/*
**	PostOrder traversal:
**	1. Call itself to traverse the node's left subtree
**	2. Call itself to traverse the node's right subtree
**	3. Visit the node
**	(Left - Right - Root)
**	|
**	|				A
**	|			B		C
**	|		  D   E   R   S
**	|	     F G L
**	|
**	> Suffix: F, G, D, L, E, B, R, S, C, A
*/

void	btree_apply_suffix(t_btree *root, void (*applyf)())
{
	if (!root)
		return ;
	btree_apply_suffix(root->left, applyf);
	btree_apply_suffix(root->right, applyf);
	applyf(root->item);
}
