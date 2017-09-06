/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 13:49:14 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/01 16:00:57 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*dest;
	size_t	len_s;

	i = 0;
	if (s != NULL && f != NULL)
	{
		len_s = ft_strlen(s);
		dest = (char *) malloc(sizeof(*dest) * len_s);
		while (s[i] != '\0')
		{
			dest[i] = (*f)(s[i]);
			i++;
		}
		return (dest);
	}
	return (NULL);
}
