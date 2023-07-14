/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihham <jihham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 00:11:18 by marvin            #+#    #+#             */
/*   Updated: 2023/05/19 09:48:28 by jihham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exit_with_print(int n)
{
	ft_printf(1, "exit\n");
	exit(n);
}

int	ft_exit(char **args)
{//minishell을 종료하는 함수
	int	i;

	if (!args || !*args)//args가 NULL이거나 첫번째 인수가 없을시
		exit_with_print(0);//종료 문구 출력후 minishell종료
	i = is_ignore_first_arg(args[0]);// 첫번째 인수를 무시해야하는지 확인할수있는 i를 구하기 
	if (i && !args[1])//첫번째 인수가 무시되고 두번째 인수에 아무것도 없을 경우 
		exit_with_print(0); //종료 문구 출력후 minishell종료
	if (is_num(args[i]))// 첫번째 인수가 숫자일 경우 
	{
		if (args[i + 1] && ft_printf(2, \
		"exit\nminishell: exit: too many arguments\n"))// 두번째 인수가 존재할 경우 에러 메세지를 출력후
			return (1);//종료
		else
			exit_with_print((unsigned char)ft_atoi(args[i])); // 첫번째만 존재할때 인수를 정수로 변환후 종료문구 출력후 minishell종료
	}
	else//첫번째 인수가 숫자가 아닐경우
	{
		ft_printf(2, "exit\nminishell: exit: %s: numeric argument required\n", \
		args[i]);//에러메세지 출력
		exit(255); // 255로 프로그램 종료
	}
	return (0);
}
