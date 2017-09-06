/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:39:53 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/19 19:14:57 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char			*dest;
	const char		*src;
	unsigned char	_c;

	dest = s1;
	src = s2;
	_c = c;
	while (n > 0 && *src != _c)
	{
		*dest = *src;
		n--;
		dest++;
		src++;
	}
	if (n == 0)
		return (NULL);
	*dest = *src;
	return (dest + 1);
}
