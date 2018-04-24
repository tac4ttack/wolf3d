/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_frs1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:01:53 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/27 20:40:56 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin_frs1(char *s1, char *s2)
{
	char	*r;
	int		i;
	int		j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(r = malloc(sizeof(s1) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i])
	{
		r[j + i] = s2[i];
		i++;
	}
	r[i++ + j] = 0;
	free(s1);
	return (r);
}
