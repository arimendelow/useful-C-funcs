/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 21:02:13 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/09 12:11:25 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/*
**	Level Order Traversal
**	|
**	|				A
**	|			B		C
**	|		  D   E   R   S
**	|	     F G L
**	|
**	> Level: A, B, C, D, E, R, S, F, G, L
*/

int		btree_level_count(t_btree *root)
{
	int	rcount;
	int lcount;

	rcount = 0;
	lcount = 0;
	if (!root)
		return (0);
	else
	{
		rcount = btree_level_count(root->left);
		lcount = btree_level_count(root->right);
		return (lcount > rcount ? lcount + 1 : rcount + 1);
	}
}

void	do_stuff_on_level(t_btree *root, int current_level, int *levels,
			void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	is_first_elem;

	is_first_elem = 1;
	if (levels[current_level] == 1)
		is_first_elem = 0;
	else
		levels[current_level] = 1;
	applyf(root->item, current_level, is_first_elem);
	if (root->left)
		do_stuff_on_level(root->left, current_level + 1, levels, applyf);
	if (root->right)
		do_stuff_on_level(root->left, current_level + 1, levels, applyf);
}

void	btree_apply_by_level(t_btree *root,
			void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	levcount;
	int	*levels;
	int	i;

	if (!root)
		return ;
	levcount = btree_level_count(root);
	if (!(levels = (int*)malloc(sizeof(int) * levcount)))
		return ;
	i = -1;
	while (++i < levcount)
		levels[i] = 0;
	do_stuff_on_level(root, 0, levels, applyf);
}
