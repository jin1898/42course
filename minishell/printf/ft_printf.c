/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseong <hyseong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:14:01 by hyseong           #+#    #+#             */
/*   Updated: 2023/07/21 17:14:02 by hyseong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int fd, char c)
{
	int	len;

	len = 0;
	len += write(fd, &c, 1);
	return (len);
}

int	parsing_find(int fd, char format, va_list *ap)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_char(fd, va_arg(*ap, int));
	else if (format == 's')
		len += ft_print_str(fd, va_arg(*ap, char *));
	else if (format == 'p')
	{
		len += write(fd, "0x", 2);
		len += ft_print_addr(fd, va_arg(*ap, size_t));
	}
	else if (format == 'd' || format == 'i')
		len += ft_print_nbr(fd, va_arg(*ap, int));
	else if (format == 'u')
		len += ft_print_unbr(fd, va_arg(*ap, unsigned int));
	else if (format == 'x')
		len += ft_print_up_hex(fd, va_arg(*ap, unsigned int));
	else if (format == 'X')
		len += ft_print_lw_hex(fd, va_arg(*ap, unsigned int));
	else if (format == '%')
		len += write(fd, "%", 1);
	return (len);
}

int	ft_printf(int fd, const char *format, ...)
{
	va_list	ap;
	int		res;
	int		i;

	res = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
			res += write(fd, &format[i], 1);
		else if (format[i] == '%')
		{
			res += parsing_find(fd, format[i + 1], &ap);
			i++;
		}
		i++;
	}
	va_end(ap);
	return (res);
}
