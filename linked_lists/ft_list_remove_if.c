/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 20:28:15 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/07 17:45:55 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *cursor;
	t_list *tmp;
	t_list *last;

	cursor = *begin_list;
	tmp = 0;
	last = 0;
	while (cursor)
	{
		if (cmp(cursor->data, data_ref) == 0)
		{
			if (cursor == *begin_list)
				*begin_list = cursor->next;
			else
				last->next = cursor->next;
			tmp = cursor;
			cursor = cursor->next;
			free(tmp);
		}
		else
		{
			last = cursor;
			cursor = cursor->next;
		}
	}
}
