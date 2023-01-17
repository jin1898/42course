/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:23:37 by jsunwoo           #+#    #+#             */
/*   Updated: 2022/11/15 13:31:38 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s11;
	const unsigned char	*s22;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	else if (!s2)
		return (*s2);
	else if (!s1)
		return (*s1);
	i = 0;
	while (((i + 1) < n) && (s11[i] && s22[i]) && (s11[i] == s22[i]))
		i++;
	return (s11[i] - s22[i]);
}
