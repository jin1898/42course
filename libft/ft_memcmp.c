/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:58:50 by jsunwoo           #+#    #+#             */
/*   Updated: 2022/11/29 23:06:33 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s22;
	size_t			start;

	s11 = (unsigned char *) s1;
	s22 = (unsigned char *) s2;
	start = 1;
	if (n == 0)
		return (0);
	while ((*s11 == *s22) && (start < n))
	{
		s11++;
		s22++;
		start++;
	}
	return (*s11 - *s22);
}
