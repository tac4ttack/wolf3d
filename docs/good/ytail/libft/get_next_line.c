/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 14:38:25 by ytailor           #+#    #+#             */
/*   Updated: 2013/12/27 19:13:09 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_del_fd(t_info **list, t_info *cur);
static int	ft_match_fd(t_info **list, t_info **cur, int const fd);
static int	ft_read_buf(char **line, t_info *cur, int *len);
static int	ft_realloc(char **line, char *buf, int size, int *len);

int			get_next_line(int const fd, char **line)
{
	static t_info	*list;
	t_info			*cur;
	int				result;
	int				len;
	int				ret;

	len = -1;
	if (line == NULL || ft_match_fd(&list, &cur, fd))
		return (-1);
	if (cur->offset != 0)
	{
		if ((result = ft_read_buf(line, cur, &len)) != 0)
			return (result);
	}
	while ((ret = read(fd, cur->buf, BUFF_SIZE)) > 0)
	{
		cur->offset = ret;
		cur->start = cur->buf;
		if ((result = ft_read_buf(line, cur, &len)) != 0)
			return (result);
	}
	ft_del_fd(&list, cur);
	if (ret == -1)
		return (-1);
	return (len != -1);
}

static int	ft_match_fd(t_info **list, t_info **cur, int const fd)
{
	t_info		*temp;

	if (*list == NULL)
	{
		if ((*list = (t_info *)malloc(sizeof(t_info))) == NULL)
			return (1);
		if (((*list)->buf = (char *)malloc(BUFF_SIZE)) == NULL)
			return (1);
		(*list)->offset = 0;
		(*list)->fd = fd;
		(*list)->next = NULL;
	}
	temp = *list;
	while (temp->fd != fd)
	{
		if (temp->next == NULL)
		{
			ft_match_fd(&(temp->next), cur, fd);
			return (0);
		}
		temp = temp->next;
	}
	*cur = temp;
	return (0);
}

static void	ft_del_fd(t_info **list, t_info *cur)
{
	t_info		*temp;

	ft_memdel((void **)&(cur->buf));
	temp = *list;
	if (*list == cur)
	{
		*list = (*list)->next;
		free(cur);
	}
	else
	{
		while (temp->next != cur)
			temp = temp->next;
		temp->next = cur->next;
		free(cur);
	}
}

static int	ft_read_buf(char **line, t_info *cur, int *len)
{
	char		*n;

	if ((n = ft_memchr(cur->start, (int)'\n', cur->offset)) == NULL)
	{
		if (ft_realloc(line, cur->start, cur->offset, len))
			return (-1);
		cur->offset = 0;
		cur->start = NULL;
	}
	else
	{
		if (ft_realloc(line, cur->start, n - cur->start, len))
			return (-1);
		cur->offset = cur->offset - (n + 1 - cur->start);
		cur->start = n + 1;
		return (1);
	}
	return (0);
}

static int	ft_realloc(char **line, char *buf, int size, int *len)
{
	char		*temp;

	if (*len == -1)
	{
		if ((*line = (char *)malloc(sizeof(char) * size + 1)) == NULL)
			return (1);
		ft_memcpy(*line, buf, size);
		*len = size;
		(*line)[size] = '\0';
	}
	else
	{
		if ((temp = (char *)malloc(sizeof(char) * (*len + size + 1))) == NULL)
			return (1);
		ft_memcpy(temp, *line, *len);
		ft_memcpy(temp + *len, buf, size);
		*len = *len + size;
		temp[*len] = '\0';
		free(*line);
		*line = temp;
	}
	return (0);
}
