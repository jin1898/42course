/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihham <jihham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:45:28 by jihham            #+#    #+#             */
/*   Updated: 2023/05/26 11:45:28 by jihham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_echo(char **args, int i)
{
	if (!args[i])
		ft_printf(1, "");
	else
		ft_printf(1, "%s", args[i]);
	if (args[i] && args[i + 1])
		ft_printf(1, " ");
}

static int	check_option(char *str)
{//주어진 문자열이 옵션인지 확인한다. 옵션은 -로 시작해야하고 n으로만 구성되어야하나보다.
	int	i;

	if (!str || str[0] != '-' || (str[0] == '-' && !str[1]))// 문자열이 NULL이거나 '-'로 시작하지 않거나 '-' 이후에 아무 문자도 없는 경우
		return (0); //0을 반환한다.옵션아님
	i = 0;
	while (str[++i])
		if (str[i] != 'n') //n을 제외한 다른문자가 있을 경우
			return (0); //옵션아님을 리턴
	return (1); //모든 문자가 n인경우 1을 반환
}

int	ft_echo(char **args)
{//echo 명령을 실행하는 함수 
	int	i;
	int	is_set_option;

	i = 0;
	is_set_option = check_option(args[0]); //옵션확인하기 
	if (is_set_option)
		while (args[++i] && check_option(args[i]))// 옵션일시 인덱스 증가시키기
			;
	while (args[i]) //args전부
		print_echo(args, i++);//인자 출력하기
	if (!is_set_option)//옵션이 없을시
		ft_printf(1, "\n"); //개행만 출력
	return (0);
}
