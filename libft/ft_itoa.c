/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 06:21:47 by jsunwoo           #+#    #+#             */
/*   Updated: 2022/11/28 18:35:51 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	char_put(char *numbox, long num, size_t *n_idx)
{	
	if (num > 9)
	{
		char_put (numbox, num / 10, n_idx);
		char_put (numbox, num % 10, n_idx);
	}
	else
		numbox[(*n_idx)++] = num + '0';
}

static int	count(long num)
{
	int	i;

	i = 0;
	if (num < 0)
	{
		i++;
		num *= -1;
	}
	while (num)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	num;
	size_t	n_idx;
	char	*numbox;

	num = n;
	n_idx = 0;
	if (n == 0)
		return (ft_strdup("0"));
	numbox = malloc(sizeof(char) * (count(num) + 1));
	if (numbox == NULL)
		return (NULL);
	if (num < 0)
	{
		num *= -1;
		numbox[n_idx] = '-';
		n_idx += 1;
	}
	char_put(numbox, num, &n_idx);
	numbox[n_idx] = '\0';
	return (numbox);
}
