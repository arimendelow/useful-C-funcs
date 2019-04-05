/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:55:04 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/08 18:56:10 by amendelo         ###   ########.fr       */
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

void	sorted_list_insert(t_list **begin_list, t_list *node, int (*cmp)())
{
	t_list *nodes[3];

	nodes[0] = node;
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

/*
**	gets second to last node (last node in which ->next exists)
*/

t_list	*get_snd_to_last(t_list *begin_list)
{
	t_list	*cursor;
	t_list	*snd_to_last;

	cursor = begin_list;
	snd_to_last = begin_list;
	if (cursor)
	{
		while (cursor->next)
		{
			snd_to_last = cursor;
			cursor = cursor->next;
		}
		return (snd_to_last);
	}
	return (snd_to_last);
}

/*
**	using the functions created in ex16, go backwards from last element
**	in list 2 and add them to list 1
*/

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
															int (*cmp)())
{
	t_list	*cursor;
	t_list	*snd_to_last;

	cursor = *begin_list1;
	if (!cursor)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (begin_list2)
	{
		snd_to_last = get_snd_to_last(begin_list2);
		sorted_list_insert(begin_list1, snd_to_last->next, cmp);
		if (snd_to_last == begin_list2)
		{
			sorted_list_insert(begin_list1, snd_to_last, cmp);
			begin_list2 = 0;
		}
		else
			snd_to_last->next = 0;
	}
}
