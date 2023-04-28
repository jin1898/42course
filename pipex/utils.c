/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:08:07 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/04/28 19:23:20 by sunwoo-jin       ###   ########.fr       */
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

int	ft_strcmp2(char *s1, char *s2, int a)
{
	unsigned char	*s1_c;
	unsigned char	*s2_c;
	int				i;

	i = 0;
	s1_c = (unsigned char *)s1;
	s2_c = (unsigned char *)s2;
	while (*s1_c == *s2_c)
	{
		if (*s1_c == '\n')
			return (0);
		i++;
		s1_c++;
		s2_c++;
	}
	if (*s1_c == '\n' && i == a)
		return (0);
	return (*s1_c - *s2_c);
}