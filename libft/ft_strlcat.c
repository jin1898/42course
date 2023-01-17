/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:20:03 by jsunwoo           #+#    #+#             */
/*   Updated: 2022/11/30 15:45:33 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_strlen;

	dst_strlen = ft_strlen(dst);
	if (ft_strlen(dst) > dstsize)
		return (ft_strlen(src) + dstsize);
	else
	{
		i = 0;
		while ((i + 1 < (dstsize - dst_strlen)) && (i < ft_strlen(src)))
		{
			dst[dst_strlen + i] = src[i];
			i++;
		}
		dst[dst_strlen + i] = 0;
	}
	return (ft_strlen(src) + dst_strlen);
}
