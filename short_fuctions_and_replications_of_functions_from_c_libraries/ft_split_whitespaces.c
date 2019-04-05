/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:19:30 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/13 15:37:08 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	a function that splits a string of characters into words.
**	Separators are spaces, tabs and line breaks.
**	This function returns an array where each box contains a character-string’s
**		address represented by a word. The last element of this array is
**		equal to 0 to emphasise the end of the array.
*/

// gets length of the word beginning at index i of the string
int		len_w(char *str, int i)
{
	int len;

	len = 0;
	while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
	{
		i++;
		len++;
	}
	return (len);
}

// counts the number of words in a string
int		wordcount(char *str)
{
	int state;
	int wc;

	state = 0;
	wc = 0;
	while (*str)
	{
		if (*str == ' ' || *str == '\n' || *str == '\t')
			state = 0;
		else if (state == 0)
		{
			state = 1;
			wc++;
		}
		str++;
	}
	return (wc);
}

char	**ft_split_whitespaces(char *str)
{
	char	**output;
	int		i;
	int		j;
	int		k;

	if (!(output = malloc((wordcount(str) + 1) * sizeof(char*))))
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
		if (str[i])
		{
			k = 0;
			if (!(output[j] = malloc(sizeof(char*) * len_w(str, i) + 1)))
				return (0);
			while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i])
				output[j][k++] = str[i++];
			output[j++][k] = '\0';
		}
	}
	output[j] = 0;
	return (output);
}
