/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 10:38:06 by amendelo          #+#    #+#             */
/*   Updated: 2018/10/30 11:51:49 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		cmp_strings(char *s1, char *s2)
{
	unsigned char *p1;
	unsigned char *p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while ((*p1 != '\0' && *p2 != '\0') && *p1 == *p2)
	{
		p1++;
		p2++;
	}
	if (*p1 == *p2)
		return (0);
	else
		return (*p1 - *p2);
}

void	sort_strings(char *argv[], int size)
{
	int		indx;
	int		last_unsorted_indx;
	char	*tmp;

	last_unsorted_indx = size - 1;
	while (last_unsorted_indx > 0)
	{
		indx = 0;
		while (indx < last_unsorted_indx)
		{
			if (cmp_strings(argv[indx], argv[indx + 1]) > 0)
			{
				tmp = argv[indx];
				argv[indx] = argv[indx + 1];
				argv[indx + 1] = tmp;
			}
			indx++;
		}
		last_unsorted_indx--;
	}
}

int		main(int argc, char *argv[])
{
	int i;

	argv++;
	sort_strings(argv, argc - 1);
	i = 0;
	while (i < argc - 1)
	{
		while (*argv[i])
		{
			ft_putchar(*argv[i]);
			argv[i]++;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);
}
