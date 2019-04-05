/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:55:04 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/07 22:23:36 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
**	choosing where to insert follows the following logic:
**	> if we need to place an element in the middle of the list...
**	> else, if we need to place an element BEFORE the first thing...
**	> else, if we need to palce an element LAST
*/

/*
**	nodes[0] = new pointer
**	nodes[1] = cursor
**	nodes[2] = previous node
*/

void	insert_node(t_list **begin_list, t_list **nodes, int (*cmp)())
{
	if (nodes[1] == *begin_list && cmp(nodes[0]->data, nodes[1]->data) < 0)
	{
		*begin_list = nodes[0];
		nodes[0]->next = nodes[1];
	}
	else if (cmp(nodes[0]->data, nodes[1]->data) <= 0)
	{
		nodes[0]->next = nodes[1];
		nodes[2]->next = nodes[0];
	}
	else
		nodes[1]->next = nodes[0];
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list *nodes[3];

	nodes[0] = ft_create_elem(data);
	nodes[1] = *begin_list;
	nodes[2] = *begin_list;
	if (nodes[1])
	{
		while (nodes[1]->next && cmp(nodes[0]->data, nodes[1]->data) > 0)
		{
			nodes[2] = nodes[1];
			nodes[1] = nodes[1]->next;
		}
		insert_node(begin_list, nodes, (int(*)())cmp);
	}
	else
		*begin_list = nodes[0];
}
