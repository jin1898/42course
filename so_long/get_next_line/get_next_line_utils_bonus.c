/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:43:19 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/01/13 15:52:50 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strfind(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (*s != (char)c)
	{
		if (*s == 0)
			return (0);
		s++;
		i++;
	}
	return (1);
}

char	*ft_strjoin(const char *s1, const char *s2, \
size_t s1_len, size_t s2_len)
{
	size_t		a;
	char		*box;

	while (s1[s1_len] != 0)
		s1_len++;
	while (s2[s2_len] != 0)
		s2_len++;
	box = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (box == NULL)
	{
		free((void *)s1);
		return (NULL);
	}
	a = -1;
	while (++a < s1_len)
		box[a] = s1[a];
	a = -1;
	while (++a < s2_len + 1)
		box[a + s1_len] = s2[a];
	free((void *)s1);
	return ((char *)box);
}

char	*subline(t_box **fd_node, t_box **head)
{
	char	*print;
	int		i;
	char	*tmp;

	i = 0;
	tmp = (*fd_node)->back;
	while ((*fd_node)->back[i] != '\n')
		i++;
	print = ft_substr((*fd_node)->back, 0, (i + 1));
	if ((*fd_node)->back[i + 1])
	{
		(*fd_node)->back = ft_strdup((*fd_node)->back + i + 1);
		free(tmp);
		if (!(*fd_node)->back)
			return (NULL);
	}
	else
		del(head, (*fd_node)->fd);
	return (print);
}

char	*ft_strdup(const char *s1)
{
	size_t	s1_strlen;
	char	*mal;
	size_t	i;

	s1_strlen = 0;
	i = 0;
	while (s1[s1_strlen])
		s1_strlen++;
	mal = malloc(sizeof(*s1) * (s1_strlen + 1));
	if (!mal)
		return (NULL);
	while (s1[i])
	{
		mal[i] = s1[i];
		i++;
	}
	mal[i] = 0;
	return (mal);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	if (s == NULL)
		return (NULL);
	else
	{
		if (start + len > i)
			len = i - start;
		dst = malloc(sizeof(char) * (len + 1));
		if (dst == NULL)
			return (NULL);
		i = 0;
		while (++i - 1 < len)
			*(dst + i - 1) = *(s + start + i - 1);
		*(dst + i - 1) = '\0';
		return (dst);
	}
}
