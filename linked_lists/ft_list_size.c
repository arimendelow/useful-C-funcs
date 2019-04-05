/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:06:36 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/06 18:21:12 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	t_list	*cursor;
	int		i;

	cursor = begin_list;
	i = 0;
	if (cursor)
	{
		while (cursor)
		{
			cursor = cursor->next;
			i++;
		}
	}
	return (i);
}
