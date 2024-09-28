/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:44:16 by jsunwoo           #+#    #+#             */
/*   Updated: 2022/12/11 21:44:51 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		n_len;

	n_len = ft_len(n);
	num = (char *)malloc(sizeof(char) * (n_len + 1));
	if (!num)
		return (0);
	num[n_len] = '\0';
	while (n != 0)
	{
		num[n_len - 1] = n % 10 + '0';
		n = n / 10;
		n_len--;
	}
	return (num);
}

int	ft_print_u(unsigned int n)
{
	int		print_len;
	char	*num;

	print_len = 0;
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		print_len += 1;
	}
	else
	{
		num = ft_uitoa(n);
		if (!num)
			return (0);
		print_len += ft_print_str(num);
		free(num);
	}
	return (print_len);
}
