/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:33:57 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/07 17:43:14 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list	*link;
	t_list	*next_link;

	link = *begin_list;
	if (link)
	{
		while (link)
		{
			next_link = link->next;
			free(link);
			link = next_link;
		}
	}
	*begin_list = 0;
}
