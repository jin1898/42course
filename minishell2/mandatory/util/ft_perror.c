/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:20:56 by hamjihyeon        #+#    #+#             */
/*   Updated: 2023/07/13 17:59:44 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_perror_join(char *prefix, char *postfix)
{//prefix 랑 postfix를 합쳐서 에러 메세지를 출력하는 함수
	char	*temp;

	if (!prefix || !postfix)// 두 변수가 모두 널일 경우 
		return (1 & \
			ft_printf(2, "ft_prerror_join error [%s] [%s]\n", prefix, postfix));//에러 메세지 출력후 1반환
	temp = ft_strjoin(prefix, postfix);// prefix랑 postfix를 합친 문자열 생성하기
	perror(temp); //에러메시지 출력하는 곳
	free(temp);
	return (1);
}

int	ft_perror(char *cause)
{
	if (!cause)
		perror("minishell");
	else
		perror(cause);
	return (1);
}
