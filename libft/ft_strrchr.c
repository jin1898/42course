/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:26:42 by jsunwoo           #+#    #+#             */
/*   Updated: 2022/11/29 21:04:29 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_strlen;
	char	c1;

	c1 = (char)c;
	s_strlen = ft_strlen(s);
	while (s[s_strlen] != c1 && s_strlen != 0)
		s_strlen--;
	if (s[s_strlen] == c1)
		return ((char *)s + s_strlen);
	else
		return (0);
}
