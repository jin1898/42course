/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:58:19 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/01/14 12:06:58 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_box	*add_node(t_box **head, int fd)
{
	t_box	*new;

	new = (t_box *)malloc(sizeof(t_box));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->read_rlt = 1;
	new->back = ft_strdup("");
	if (!new->back)
		return (NULL);
	new->next = *head;
	*head = new;
	return (*head);
}

char	*del(t_box	**head, int fd)
{
	t_box	*prev_node;
	t_box	*cur_node;

	prev_node = NULL;
	cur_node = *head;
	if (*head == NULL)
		return (NULL);
	if (cur_node->fd == fd)
		*head = cur_node->next;
	else
	{
		while (cur_node->fd != fd)
		{
			prev_node = cur_node;
			cur_node = cur_node->next;
		}
		prev_node->next = cur_node->next;
	}
	free(cur_node->back);
	free(cur_node);
	return (NULL);
}

t_box	*ft_find(int fd, t_box **head)
{
	t_box	*b;

	b = *head;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (b)
	{
		if (b->fd == fd)
			return (b);
		b = b->next;
	}
	return (add_node(head, fd));
}

char	*read_result(int fd, char *buffer, t_box **fd_node, t_box **head)
{
	char	*ret;

	while ((!ft_strfind((*fd_node)->back, '\n')) && (*fd_node)->read_rlt)
	{
		(*fd_node)->read_rlt = read(fd, buffer, BUFFER_SIZE);
		if ((*fd_node)->read_rlt < 0
			|| ((*fd_node)->read_rlt == 0 && !(*fd_node)->back[0]))
			return (del(head, (*fd_node)->fd));
		else if ((*fd_node)->read_rlt == 0 && (*fd_node)->back[0])
			break ;
		buffer[(*fd_node)->read_rlt] = 0;
		(*fd_node)->back = ft_strjoin((*fd_node)->back, buffer, 0, 0);
		if ((*fd_node)->back == NULL)
			return (NULL);
	}
	if (ft_strfind((*fd_node)->back, '\n'))
		return (subline(fd_node, head));
	ret = ft_strdup((*fd_node)->back);
	del(head, (*fd_node)->fd);
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_box	*head;
	t_box			*fd_node;
	char			*buffer;
	char			*ret;

	fd_node = ft_find(fd, &head);
	if (!fd_node)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
	{
		del(&head, fd);
		return (NULL);
	}
	ret = read_result(fd, buffer, &fd_node, &head);
	free(buffer);
	return (ret);
}
