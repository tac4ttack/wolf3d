/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:13:45 by ytailor           #+#    #+#             */
/*   Updated: 2013/12/24 12:12:17 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		l1;
	int		l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (s2 == 0)
		return ((char *)s1);
	while (l1 >= l2)
	{
		if (ft_memcmp(s1, s2, l2) == 0)
			return ((char *)s1);
		s1++;
		l1--;
	}
	return (NULL);
}
