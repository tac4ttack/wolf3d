/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:56:01 by fmessina          #+#    #+#             */
/*   Updated: 2016/11/23 17:24:59 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(char const *s1, char const *s2)
{
	char *tmp1;
	char *tmp2;

	if (!*s2)
		return ((char*)s1);
	while (*s1)
	{
		tmp1 = (char *)s1;
		tmp2 = (char *)s2;
		while (*tmp2 && *tmp1 == *tmp2)
		{
			tmp1++;
			tmp2++;
		}
		if (!*tmp2)
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
