/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihham <jihham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:14:32 by jihham            #+#    #+#             */
/*   Updated: 2023/04/12 14:14:59 by jihham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*result;

	if (!s2)
		return (0);
	if (!s1)
		s1len = 0;
	else
		s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	result = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!result)
		return (0);
	ft_memcpy(result, s1, s1len);
	ft_memcpy(result + s1len, s2, s2len);
	result[s1len + s2len] = 0;
	return (result);
}
