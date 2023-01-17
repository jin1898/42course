/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:14:40 by jsunwoo           #+#    #+#             */
/*   Updated: 2022/11/16 21:14:40 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	total_len;
	char	*box;
	size_t	a;
	size_t	b;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	box = malloc(sizeof(char) * (total_len + 1));
	if (box == NULL)
		return (NULL);
	box[total_len] = 0;
	a = 0;
	b = 0;
	while (a < ft_strlen(s1))
	{
		box[a] = s1[a];
		a++;
	}
	while (b < ft_strlen(s2))
	{
		box[a + b] = s2[b];
		b++;
	}
	return (box);
}
