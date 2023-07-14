/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihham <jihham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:29:43 by jihham            #+#    #+#             */
/*   Updated: 2023/06/01 19:23:43 by jihham           ###   ########.fr       */
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
