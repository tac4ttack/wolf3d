/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 16:10:48 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/03 16:14:07 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dstt;
	const char	*srct;
	size_t		n;
	size_t		len;

	dstt = dst;
	srct = (char*)src;
	n = size;
	while (n-- != 0 && *dstt != '\0')
		dstt++;
	len = dstt - dst;
	if ((n = size - len) == 0)
		return (len + ft_strlen(srct));
	while (*srct != '\0')
	{
		if (n != 1)
		{
			*dstt++ = *srct;
			n--;
		}
		srct++;
	}
	*dstt = '\0';
	return (len + (srct - src));
}
