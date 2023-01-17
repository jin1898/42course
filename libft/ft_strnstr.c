/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:24:03 by jsunwoo           #+#    #+#             */
/*   Updated: 2022/11/15 22:08:07 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;
	size_t	start;
	size_t	i;

	len_needle = ft_strlen(needle);
	start = -1;
	if ((! *haystack && ! *needle) || (! *needle))
		return ((char *)haystack);
	if ((! *haystack) || (ft_strlen(haystack) < ft_strlen(needle)))
		return (NULL);
	else
	{
		while (haystack[++start] != 0)
		{
			i = 0;
			while (i < len_needle && (needle[i] == haystack[i + start]) \
			&& ((i + start) < len))
			{
				i++;
				if (i == (len_needle))
					return ((char *)&haystack[start]);
			}
		}
		return (NULL);
	}
}
