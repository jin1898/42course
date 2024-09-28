/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:15:21 by jsunwoo           #+#    #+#             */
/*   Updated: 2022/12/11 21:43:56 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_make_hex_and_print(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_make_hex_and_print(ptr / 16);
		ft_make_hex_and_print(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
		{
			if (ft_putchar_fd((ptr + '0'), 1) == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar_fd((ptr - 10 + 'a'), 1) == -1)
				return (-1);
		}
	}
	return (1);
}

int	ft_hex_len(unsigned long long ptr)
{
	int	print_len;

	print_len = 0;
	while (ptr)
	{
		ptr /= 16;
		print_len++;
	}
	return (print_len);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	print_len;

	print_len = 0;
	if (write(1, "0x", 2) == -1)
		return (-1);
	print_len = 2;
	if (ptr == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		print_len += 1;
	}
	else
	{
		if (ft_make_hex_and_print(ptr) == -1)
			return (-1);
		print_len += ft_hex_len(ptr);
	}
	return (print_len);
}
