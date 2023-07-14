/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihham <jihham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:51:19 by jihham            #+#    #+#             */
/*   Updated: 2023/06/01 19:22:22 by jihham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(int fd, const char *format, ...);
int	parsing_find(int fd, char format, va_list *ap);
int	ft_print_char(int fd, char format);
int	ft_print_nbr(int fd, int n);
int	ft_print_unbr(int fd, unsigned int n);
int	ft_print_str(int fd, char *s);
int	ft_print_up_hex(int fd, unsigned int n);
int	ft_print_lw_hex(int fd, unsigned int n);
int	ft_print_addr(int fd, size_t n);

#endif
