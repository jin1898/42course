/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihham <jihham@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:45:53 by jihham            #+#    #+#             */
/*   Updated: 2022/11/11 14:05:38 by jihham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	slen;
	size_t	i;

	slen = ft_strlen((char *)s);
	i = 0;
	if (slen < start)
		return (ft_strdup(""));
	if (slen - start < len)
		len = slen - start;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	while (i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
