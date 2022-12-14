/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 22:00:51 by jsunwoo           #+#    #+#             */
/*   Updated: 2022/12/11 22:01:53 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_print_char(va_arg(args, int));
	else if (format == 's')
		print_len += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		print_len += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_len += ft_print_d_i(va_arg(args, int));
	else if (format == 'u')
		print_len += ft_print_u(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_len += ft_print_x(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_len += ft_print_percent();
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int		print_len;
	int		check;
	int		index;
	va_list	args;

	va_start(args, str);
	print_len = 0;
	index = 0;
	check = 0;
	while (str[index])
	{
		if (str[index] == '%')
		{
			check = ft_format(args, str[index + 1]);
			index++;
		}
		else
			check = ft_print_char(str[index]);
		index++;
		if (check == -1)
			return (-1);
		print_len += check;
	}
	va_end(args);
	return (print_len);
}
