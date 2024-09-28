/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 06:21:47 by jsunwoo           #+#    #+#             */
/*   Updated: 2022/12/12 15:12:31 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

int	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return (-1);
	return (1);
}
