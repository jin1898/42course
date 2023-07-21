/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseong <hyseong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:13:48 by hyseong           #+#    #+#             */
/*   Updated: 2023/07/21 17:13:50 by hyseong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int fd, int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len += write(fd, "-2147483648", 11);
		return (len);
	}
	else if (n < 0)
	{
		n *= -1;
		len += ft_print_char(fd, '-');
	}
	if (n < 10)
	{
		len += ft_print_char(fd, n + '0');
	}
	else if (n >= 0)
	{
		len += ft_print_nbr(fd, n / 10);
		len += ft_print_char(fd, n % 10 + 48);
	}
	return (len);
}

int	ft_print_unbr(int fd, unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 10)
	{
		len += ft_print_unbr(fd, nb / 10);
		len += ft_print_unbr(fd, nb % 10);
	}
	else if (nb < 10)
	{
		len += ft_print_char(fd, nb + 48);
	}
	return (len);
}

int	ft_print_str(int fd, char *s)
{
	int	len;

	len = 0;
	if (!s)
		s = "(null)";
	while (*s)
	{
		len += write(fd, s, 1);
		s++;
	}
	return (len);
}
