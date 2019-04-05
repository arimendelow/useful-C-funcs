/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:28:19 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/07 17:42:56 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*node;
	t_list	*tmp;

	i = -1;
	tmp = 0;
	node = 0;
	while (++i < ac)
	{
		node = ft_create_elem(av[i]);
		node->next = tmp;
		tmp = node;
	}
	return (node);
}
