/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseong <hyseong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:13:42 by hyseong           #+#    #+#             */
/*   Updated: 2023/07/21 17:13:44 by hyseong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_up_hex(int fd, unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_print_up_hex(fd, n / 16);
		len += ft_print_up_hex(fd, n % 16);
	}
	else if (n < 16)
	{
		len += ft_print_char(fd, "0123456789abcdef"[n]);
	}
	return (len);
}

int	ft_print_lw_hex(int fd, unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_print_lw_hex(fd, n / 16);
		len += ft_print_lw_hex(fd, n % 16);
	}
	if (n < 16)
	{
		len += ft_print_char(fd, "0123456789ABCDEF"[n]);
	}
	return (len);
}

int	ft_print_addr(int fd, size_t n)
{
	size_t	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_print_addr(fd, n / 16);
		len += ft_print_addr(fd, n % 16);
	}
	else if (n < 16)
	{
		len += ft_print_char(fd, "0123456789abcdef"[n]);
	}
	return (len);
}
