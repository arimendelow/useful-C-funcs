/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:16:52 by amendelo          #+#    #+#             */
/*   Updated: 2018/10/29 20:55:43 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	strlength(char *str)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	char			*s;
	char			*d;

	src_len = strlength(src);
	if (size == 0)
		return (src_len);
	s = src;
	d = dest;
	while (*s != '\0')
	{
		if (size != 1)
		{
			*d++ = *s;
			size--;
		}
		s++;
	}
	*d = '\0';
	return (src_len);
}
