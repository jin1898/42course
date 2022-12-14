/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:48:44 by jsunwoo           #+#    #+#             */
/*   Updated: 2022/12/11 21:59:23 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int			ft_print_str(char *str);
char		*ft_itoa(int n);
int			ft_make_hex_and_print(unsigned long long ptr);
int			ft_putchar_fd(char c, int fd);
int			ft_putchar_fd(char c, int fd);
int			ft_print_char(const char c);
char		*ft_strdup(const char *s1);
int			ft_print_ptr(unsigned long long ptr);
int			ft_print_d_i(int num);
int			ft_print_u(unsigned int n);
int			ft_print_x(unsigned int n, const char format);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
int			ft_printf(const char *str, ...);
int			ft_print_percent(void);

#endif
