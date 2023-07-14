/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihham <jihham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:57:22 by marvin            #+#    #+#             */
/*   Updated: 2023/05/19 12:59:21 by jihham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_env_manager *env_manager)
{// 환경변수를 출력하는 함수
	t_env	*temp;

	temp = env_manager->head;//순환을 위한 머리만때오기!
	while (temp)
	{
		if (temp->value) //환경변수의 값이 존재할 경우에만
			ft_printf(1, "%s=%s\n", temp->key, temp->value); // 환경변수를 "key=value" 형식으로 출력
		temp = temp->next;//다음으로 이동
	}
	return (0);
}
