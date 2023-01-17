/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:43:35 by jsunwoo           #+#    #+#             */
/*   Updated: 2022/12/11 21:43:43 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_d_i(int num)
{
	int		print_len;
	char	*str;

	print_len = 0;
	str = ft_itoa(num);
	print_len = ft_print_str(str);
	free(str);
	return (print_len);
}
