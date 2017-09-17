/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 12:44:54 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/19 19:13:21 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int		i;
	int		neg;

	i = 0;
	neg = 0;
	while (*str == ' ' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == '\t')
			str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-' && ft_isdigit(*(str + 1)) == 1)
			neg = 1;
		str++;
	}
	else if (ft_isdigit(*str) != 1)
		return (0);
	while (ft_isdigit(*str) == 1)
	{
		i = i * 10 + (*str - '0');
		str++;
	}
	if (neg == 1)
		return (i * -1);
	return (i);
}
