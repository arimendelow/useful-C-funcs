/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:42:41 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/13 15:41:02 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len + 1);
}

// Reproduces the behavior of the function strdup.
char	*ft_strdup(char *src)
{
	char	*res;
	int		i;
	int		l;

	i = 0;
	l = ft_strlen(src);
	res = (char*)malloc(sizeof(char) * 1);
	if (res == 0)
		return (res);
	while (i < (l - 1))
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
