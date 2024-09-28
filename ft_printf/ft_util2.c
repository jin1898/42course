/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:12:03 by jsunwoo           #+#    #+#             */
/*   Updated: 2022/12/12 15:15:41 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
