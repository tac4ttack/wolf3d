/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 16:16:41 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/19 19:18:24 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;
	size_t	len_s;

	i = 0;
	len_s = 0;
	if (s != NULL && start < len_s && len != 0)
	{
		len_s = ft_strlen(s);
		dest = (char *) malloc(sizeof(*dest) * len);
		if (dest == NULL)
			return (NULL);
		while (i != len)
		{
			dest[i] = s[start];
			i++;
			start++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
