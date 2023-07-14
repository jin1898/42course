/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_convert_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 02:37:03 by hamjihyeon        #+#    #+#             */
/*   Updated: 2023/07/14 15:40:32 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_exist_oldpwd(char *key)
{//환경변수에 oldpwd라는 값이 있는지 확인하기
	if (!ft_strncmp(key, "OLDPWD", 7))
		return (1);
	return (0);
}

int	check_shlvl(t_env *env)
{//주어진 Env 구조체의 키가 "SHLVL"과 일치하는지 확인하고, 값의 유형을 분석(값이 숫자가 아니거나 비어 있을 경우 새로운 값을 설정하고/값이 숫자인 경우에는 기존 값에 1을 더한 값을 설정한다) 최종적으로 환경 변수의 값을 업데이트하고, 처리가 완료되었음을 반환합니다.
	char	*new_value;

	if (!ft_strncmp(env->key, "SHLVL", 6))// 환경 변수의 키가 "SHLVL"인지 확인
	{
		if (env->value && is_unsigned_num(env->value) ^ is_num(env->value))// 기존 값이 부호 없는 숫자인지 확인
			new_value = ft_itoa(0);// 기존 값이 부호 없는 숫자가 아니면 0으로 설정
		else if (!env->value || !is_num(env->value))// 기존 값이 없거나 숫자가 아닌 경우
			new_value = ft_itoa(1);// 값이 없거나 숫자가 아니면 1로 설정
		else// 값이 숫자인경우
			new_value = ft_itoa(ft_atoi(env->value) + 1);// 기존 값에 1을 더한 값을 설정
		if (env->value)//기존 값 해제
			free(env->value);
		env->value = new_value; //새로운 값 할당
		return (1); 
	}
	return (0);
}
