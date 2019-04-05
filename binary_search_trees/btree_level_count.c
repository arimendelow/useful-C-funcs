/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:51:22 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/08 21:46:35 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/*
**	Returns the size of the largest branch.
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
