/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:06:50 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/07 12:39:54 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *cursor1;

	if (*begin_list1)
	{
		cursor1 = *begin_list1;
		while (cursor1->next)
			cursor1 = cursor1->next;
		cursor1->next = begin_list2;
	}
	else
		*begin_list1 = begin_list2;
}
