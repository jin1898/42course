/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:58:40 by jsunwoo           #+#    #+#             */
/*   Updated: 2022/11/30 16:08:45 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	char	*malloc_name;
	size_t	count1;

	count1 = 0;
	total = count * size;
	if (count != 0 && size != 0)
	{
		if (total / count != size)
			return (0);
	}
	malloc_name = malloc(total);
	if (malloc_name == NULL)
		return (NULL);
	while (count1 < total)
	{
		malloc_name[count1] = 0;
		count1++;
	}
	return (malloc_name);
}
