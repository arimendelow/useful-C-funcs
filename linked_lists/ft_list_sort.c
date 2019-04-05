/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:47:35 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/07 16:43:16 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
** swapnodes:
** for example -
** 0 1 2 3 4
** > want to swap 2 and 3
** > 2 is current, 1 is last
** 1) 1->3
** 2) 2->4
** 3) 1->->2
** > new order: 0 1 3 2 4
** edge case - want to swap first node with second node
** > here, there is no last node. so:
** 1) make 1 *begin_list
** 2) 0->->2
** 3) 1->0
** > new order: 1 0 2 3 4
*/

void	swapnodes(t_list **begin_list, t_list **current, t_list **last)
{
	if ((*current) == *begin_list)
	{
		*begin_list = (*current)->next;
		(*current)->next = (*current)->next->next;
		(*begin_list)->next = (*current);
	}
	else
	{
		(*last)->next = (*current)->next;
		(*current)->next = (*current)->next->next;
		(*last)->next->next = (*current);
	}
	(*current) = *begin_list;
}

/*
** every time we swap nodes, resets current to the beggining of the list
*/

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	t_list	*last;

	current = *begin_list;
	if (current)
	{
		while (current->next)
		{
			if (cmp(current->data, current->next->data) > 0)
				swapnodes(begin_list, &current, &last);
			else
			{
				last = current;
				current = current->next;
			}
		}
	}
}
