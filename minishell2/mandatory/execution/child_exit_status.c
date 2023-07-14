/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_exit_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 01:26:20 by hamjihyeon        #+#    #+#             */
/*   Updated: 2023/07/14 12:43:42 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

int	check_exit_status(int child_status, int *signum)
{//자식프로세스의 종료상태를 확인하는 함수
	*signum = 0; // 시그널 번호 초기화
	if (WIFSIGNALED(child_status))//자식프로세스가 시그널에 의해 종료되었는지 확인 
	{
		*signum = WTERMSIG(child_status);// 시그널 번호를 얻어오기
		g_exit_status = 128 + WTERMSIG(child_status);// 종료 상태를 설정합니다. 시그널 번호에 128을 더해준다.
	}
	else
		g_exit_status = WEXITSTATUS(child_status);// 자식 프로세스가 정상적으로 종료되었을 때(시그널로 종료되지 않았을때), 종료 상태를 설정
	return (0);

	/*
	<함수공부>
	WIFSIGNALED 매크로는 인자값의 비트를 검사하여 자식 프로세스가 시그널에 의해 종료되었는지 여부를 판단한다. 
	시그널에 의해 종료된 경우 0이 아닌 값(참)을 반환하며, 그렇지 않은 경우 0(거짓)을 반환한다.
	
	WEXITSTATUS 매크로는 status의 비트를 검사하여 자식 프로세스의 종료 상태 값을 반환합니다. 
	종료 상태 값은 자식 프로세스가 exit 함수를 호출하거나 main 함수에서 반환한 값입니다. 
	반환된 값을 얻을 수 있는 범위는 0에서 255까지이며, 0은 일반적으로 성공을 나타냅니다.
	*/
}
