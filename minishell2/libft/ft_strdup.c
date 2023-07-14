/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihham <jihham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:19:58 by jihham            #+#    #+#             */
/*   Updated: 2022/11/10 17:30:40 by jihham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static char	*ft_strcpy(const char *dst, const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)dst;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*sd;
	int		len;

	len = ft_strlen(s1);
	sd = malloc(len + 1);
	if (!sd)
		return (0);
	ft_strcpy(sd, s1);
	return (sd);
}
