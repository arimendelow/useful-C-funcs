/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:41:28 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/07 22:24:22 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *cursor;

	cursor = *begin_list;
	if (cursor)
	{
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}
