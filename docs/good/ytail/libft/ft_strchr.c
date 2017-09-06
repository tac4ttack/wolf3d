/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 11:04:42 by ytailor           #+#    #+#             */
/*   Updated: 2013/12/24 11:52:35 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	_c;
	int		i;

	i = 0;
	_c = c;
	while (s[i] != '\0')
	{
		if (s[i] == _c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == _c)
		return ((char *) &s[i]);
	return (NULL);
}
