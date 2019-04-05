/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:03:36 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/07 17:47:04 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*list_begin;
	t_list	*list_end;
	t_list	*cursor;
	void	*data_tmp;

	list_begin = begin_list;
	cursor = begin_list;
	if (cursor)
	{
		while (cursor->next)
			cursor = cursor->next;
		list_end = cursor;
		while (list_begin != list_end && list_end->next != list_begin)
		{
			data_tmp = list_begin->data;
			list_begin->data = list_end->data;
			list_end->data = data_tmp;
			list_begin = list_begin->next;
			cursor = begin_list;
			while (cursor->next != list_end)
				cursor = cursor->next;
			list_end = cursor;
		}
	}
}
