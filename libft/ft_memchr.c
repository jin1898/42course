/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:00:25 by jsunwoo           #+#    #+#             */
/*   Updated: 2022/11/22 22:06:13 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*s1;
	unsigned char	c1;

	c1 = (unsigned char)c;
	s1 = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		if (*(s1 + count) == c1)
			return ((void *)(s1 + count));
		count++;
	}
	return (0);
}
