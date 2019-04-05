/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:27:11 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/09 13:29:41 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/*
**	Returns the first element related to the reference data given as argument.
**	- Tree is browsed using In Order traversal.
**	- If element isn't found, function returns NULL.
**		- if we get to the rightmost element and it has not yet been found,
**			return NULL.
*/

char	*btree_search_item(t_btree *root, char *data_ref, int (*cmpf)())
{
	void	*out;

	out = 0;
	if (!root || !data_ref)
		return (out);
	out = btree_search_item(root->left, data_ref, cmpf);
	if (!out && cmpf(data_ref, root->item) == 0)
		out = root->item;
	if (!out)
		out = btree_search_item(root->right, data_ref, cmpf);
	return (out);
}
