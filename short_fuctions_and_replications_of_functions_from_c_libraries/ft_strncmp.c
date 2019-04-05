/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 21:09:07 by amendelo          #+#    #+#             */
/*   Updated: 2018/10/29 21:46:29 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned char *p1;
	unsigned char *p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while ((*p1 != '\0' && *p2 != '\0') && *p1 == *p2 && n != 1)
	{
		p1++;
		p2++;
		n--;
	}
	if (*p1 == *p2)
		return (0);
	else
		return (*p1 - *p2);
}
