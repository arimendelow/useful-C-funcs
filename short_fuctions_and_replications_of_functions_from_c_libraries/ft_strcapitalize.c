/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 10:12:19 by amendelo          #+#    #+#             */
/*   Updated: 2018/10/29 10:37:00 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	if (str[i] >= 'a' && str[i] <= 'z')
	{
		str[i] = str[i] - 'a' + 'A';
	}
	while (str[++i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
		if (str[i] >= 'a' && str[i] <= 'z'
				&& (str[i - 1] == ' ' || str[i - 1] == '_' ||
				str[i - 1] == '+' || str[i - 1] == '-' ||
				str[i - 1] == '\n' || str[i - 1] == '\t' ||
				str[i - 1] == '\v' || str[i - 1] == '\f' ||
				str[i - 1] == '\r'))
			str[i] = str[i] - 'a' + 'A';
	}
	return (str);
}
