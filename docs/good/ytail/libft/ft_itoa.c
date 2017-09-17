/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 18:54:27 by ytailor           #+#    #+#             */
/*   Updated: 2013/12/29 18:54:28 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_nb_char(int n)
{
	int		i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		rev_n;
	char	*str;

	rev_n = ft_nb_char(n);
	str = (char *)malloc(sizeof(char) * rev_n + 1);
	if (str)
	{
		str[rev_n--] = '\0';
		if (n < 0)
			str[0] = '-';
		else if (n == 0)
			str[0] = '0';
		while (n != 0)
		{
			if (n > 0)
				str[rev_n--] = ((n % 10) + '0');
			else
				str[rev_n--] = ((-(n % 10)) + '0');
			n /= 10;
		}
	}
	return (str);
}
