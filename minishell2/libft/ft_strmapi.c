/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihham <jihham@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:08:04 by jihham            #+#    #+#             */
/*   Updated: 2022/11/11 18:08:05 by jihham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;
	unsigned int	slen;

	i = 0;
	slen = ft_strlen(s);
	if (!s)
		return (0);
	result = malloc(sizeof(char) * slen + 1);
	if (!result)
		return (0);
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[slen] = 0;
	return (result);
}
