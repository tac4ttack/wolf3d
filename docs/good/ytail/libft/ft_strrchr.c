/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 12:27:41 by ytailor           #+#    #+#             */
/*   Updated: 2013/12/24 12:01:49 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;
	char	_c;

	size = ft_strlen((char *) s);
	_c = c;
	while (size > 0)
	{
		if (s[size] == _c)
			return ((char *) &s[size]);
		size--;
	}
	if (s[size] == _c)
		return ((char *) &s[size]);
	return (NULL);
}
