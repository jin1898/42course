/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihham <jihham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 00:37:17 by jihham            #+#    #+#             */
/*   Updated: 2023/05/19 13:00:02 by jihham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(char **args, t_env_manager *env_manager)
{//주어진 환경변수를 제거하는 함수이다. 
	int	i;
	int	error;
	int	current_error;

	error = 0;
	if (!args || !*args)// NULL이거나 첫번째 인자가 없을시 error반환
		return (error);
	i = is_ignore_first_arg(args[0]) - 1; // 첫번째 인자를 무시하는지 확인
	while (args[++i])
	{
		current_error = !is_valid_env_key(args[i]); // 환경변수에서 args[i]가 있는지 확인한다.
		error |= current_error;// *error변수와 current_error변수간에 비트 or연산을 수행하고 결과 *error에 저장
		if (current_error \
		&& ft_printf(2, "minishell: unset: %s: not a valid identifier\n", \
		args[i]))// 환경 변수 키가 없을 경우 에러 메시지를 출력하고 다음 인자로 넘어가기
			continue ;
		delete_env(env_manager, args[i]); //환경변수 삭제해버리기
	}
	return (error);
}
