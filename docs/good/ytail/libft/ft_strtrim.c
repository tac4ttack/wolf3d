/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 17:14:16 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/19 19:19:01 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*dest;
	size_t	l;
	size_t	j;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	l = ft_strlen(s);
	while ((j != l) && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j++;
	while ((l != j) && (s[l - 1] == ' ' || s[l - 1] == '\n'
			|| s[l - 1] == '\t'))
		l--;
	dest = ft_strnew(l - j);
	if (l > j)
	{
		while (j != l)
			dest[i++] = s[j++];
	}
	return (dest);
}
