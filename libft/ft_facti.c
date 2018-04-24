/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_fact.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 13:55:35 by fmessina          #+#    #+#             */
/*   Updated: 2017/05/17 14:57:58 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_int_fact(int n)
{
	int	i;
	int	res;

	res = 1;
	i = 1;
	if (n > 16)
	{
		ft_putendl("ERROR: Result is over the INT_MAX limit");
		return (-1);
	}
	while (i <= n)
		res *= i++;
	return (res);
}
