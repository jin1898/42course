/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:59:05 by jsunwoo           #+#    #+#             */
/*   Updated: 2022/11/29 21:20:00 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s1_strlen;
	char	*mal;
	size_t	i;

	i = 0;
	s1_strlen = ft_strlen(s1);
	mal = malloc(sizeof(*s1) * (s1_strlen + 1));
	if (!mal)
		return (NULL);
	while (s1[i])
	{
		mal[i] = s1[i];
		i++;
	}
	mal[i] = 0;
	return (mal);
}
