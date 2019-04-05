/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:52:30 by amendelo          #+#    #+#             */
/*   Updated: 2018/10/29 20:10:48 by amendelo         ###   ########.fr       */
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

/*
** vars[0] = space_remaining - stores space left in destination string
** vars[1] = dest_len - total length of original destination string
** vars[2] = src_len - total length of source string
*/

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*d;
	char			*s;
	unsigned int	vars[3];

	vars[2] = strlength(src);
	d = dest;
	s = src;
	vars[0] = size;
	while (vars[0]-- != 0 && *d != '\0')
		d++;
	vars[1] = d - dest;
	vars[0] = size - vars[1];
	if (vars[0] == 0)
		return (vars[1] + vars[2]);
	while (*s != '\0')
	{
		if (vars[0] != 1)
		{
			*d++ = *s;
			vars[0]--;
		}
		s++;
	}
	*d = '\0';
	return (vars[1] + vars[2]);
}
