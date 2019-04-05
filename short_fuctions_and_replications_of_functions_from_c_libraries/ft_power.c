/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:42:38 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/13 15:50:12 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// calculates nb raised to the exponent power.
int		ft_power(int nb, int power)
{
	int counter;
	int output;

	counter = 0;
	output = nb;
	// maximum exponent supported is 30 as this would be larger than MAX_INT.
	if (power < 0 || (power > 30 && nb != 1))
		return (0);
	else if (power == 0)
		return (1);
	while (++counter < power)
		output *= nb;
	return (output);
}
