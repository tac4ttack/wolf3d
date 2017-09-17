/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 12:32:53 by ytailor           #+#    #+#             */
/*   Updated: 2013/12/24 12:09:17 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len_dst;
	size_t		len_src;
	int			result;

	len_dst = (size_t)ft_strlen(dst);
	len_src = (size_t)ft_strlen(src);
	result = size - len_dst - 1;
	if (size >= len_dst && result >= 0)
	{
		if (result >= 0)
			ft_strncat(dst, src, result);
		return (len_dst + len_src);
	}
	return (len_src + size);
}
