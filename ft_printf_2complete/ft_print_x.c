/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:16:07 by jsunwoo           #+#    #+#             */
/*   Updated: 2022/12/11 21:45:27 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_make_hex_and_print_x(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_make_hex_and_print_x (n / 16, format);
		ft_make_hex_and_print_x (n % 16, format);
	}	
	else
	{
		if (n <= 9)
		{
			if (ft_putchar_fd((n + '0'), 1) == -1)
				return (-1);
		}
		else
		{
			if (format == 'x')
				if (ft_putchar_fd((n - 10 + 'a'), 1) == -1)
					return (-1);
			if (format == 'X')
				if (ft_putchar_fd((n - 10 + 'A'), 1) == -1)
					return (-1);
		}
	}
	return (1);
}

int	ft_n_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_print_x(unsigned int n, const char format)
{
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	else
		if (ft_make_hex_and_print_x(n, format) == -1)
			return (-1);
	return (ft_n_len(n));
}
