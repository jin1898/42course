/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 02:41:05 by hamjihyeon        #+#    #+#             */
/*   Updated: 2023/07/14 15:49:24 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_unsigned_num(char *arg)
{//주어진 문자열이 부호 없는 숫자인지 확인한다.
	int	i;

	if (!arg || !*arg)  // 인수가 NULL이거나 빈 문자열인 경우
		return (0);
	i = 0;
	if (arg[0] == '+')// 인수가 '+'로 시작하는 경우
		i++;// 첫 번째 문자는 부호이므로 건너뛴다
	while (arg[i])// 인수의 나머지 문자들에 대해 반복
		if (!ft_isdigit(arg[i++])) // 숫자가 아닌 문자가 있는 경우
			return (0);// 부호 없는 숫자가 아님을 반환
	return (1);// 부호 없는 숫자임을 반환
}

int	is_num(char *arg)
{ // 숫자인지확인
	int	i;

	if (!arg || !*arg)
		return (0);
	i = 0;
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	while (arg[i])
		if (!ft_isdigit(arg[i++]))
			return (0);
	return (1);
}
