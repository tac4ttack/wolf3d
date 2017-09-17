/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 15:29:35 by ytailor           #+#    #+#             */
/*   Updated: 2013/12/29 15:29:38 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_count(char c, int *count)
{
	write(1, &c, 1);
	*count = *count + 1;
}

void	ft_putnbr_count(long int n, int *count)
{
	if (n >= 10)
	{
		ft_putnbr_count(n / 10, count);
		ft_putnbr_count(n % 10, count);
	}
	else if (n < 0)
	{
		ft_putchar_count('-', count);
		ft_putnbr_count(-n, count);
	}
	else
		ft_putchar_count(n + 48, count);
}

void	ft_put_octal(long int n, int *count)
{
	if (n >= 8)
	{
		ft_put_octal(n / 8, count);
		ft_put_octal(n % 8, count);
	}
	else
		ft_putchar_count(n + 48, count);
}

void	ft_putstr_count(char *str, int *count)
{
	write(1, str, ft_strlen(str));
	*count = *count + ft_strlen(str);
}
