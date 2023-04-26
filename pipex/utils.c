/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:08:07 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/04/26 15:46:10 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	unsigned char	*s1_c;
	unsigned char	*s2_c;
	int				i;

	i = 0;
	s1_c = (unsigned char *)s1;
	s2_c = (unsigned char *)s2;
	while (i < n && *s1_c == *s2_c)
	{
		if (*s1_c == '\0' || i == (n - 1))
			return (0);
		i++;
		s1_c++;
		s2_c++;
	}
	return (*s1_c - *s2_c);

}

char*	ft_substr(char const* s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char*	sub;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(sub = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			sub[j] = s[i];
			j++;
		}
		i++;
	}
	sub[j] = '\0';
	return (sub);
}
