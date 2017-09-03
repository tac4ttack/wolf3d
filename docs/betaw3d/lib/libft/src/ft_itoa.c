/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 16:10:48 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/03 16:16:36 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		i;
	int		sign;
	int		size;
	char	*new;

	size = ft_nbrlen(n);
	sign = (n < 0 ? 1 : 0);
	if (!(new = ft_strnew(size + sign)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(new, "-2147483648"));
	i = -1;
	(n < 0 ? n *= -1 : 0);
	while (++i < size)
	{
		new[i] = n % 10 + '0';
		n /= 10;
	}
	(sign == 1 ? new[size] = '-' : 0);
	return (ft_strrev(new, size + sign));
}
