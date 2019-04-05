/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:55:11 by amendelo          #+#    #+#             */
/*   Updated: 2018/10/27 00:01:46 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int counter;

	if (nb <= 0)
	{
		return (0);
	}
	counter = 1;
	while ((counter * counter) < nb)
	{
		counter++;
	}
	if (counter * counter == nb)
	{
		return (counter);
	}
	else
	{
		return (0);
	}
}
