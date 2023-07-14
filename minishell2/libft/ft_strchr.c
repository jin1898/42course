/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihham <jihham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:17:06 by jihham            #+#    #+#             */
/*   Updated: 2023/04/11 13:40:13 by jihham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*stmp;
	char	ctmp;
	int		i;

	i = 0;
	if (!s)
		return (0);
	stmp = (char *)s;
	ctmp = (char)c;
	while (stmp[i] != ctmp)
	{
		if (stmp[i] == '\0')
			return (0);
		i++;
	}
	return (&stmp[i]);
}
