/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:10:17 by jihham            #+#    #+#             */
/*   Updated: 2023/07/13 03:11:54 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

void	newline_ctrl_c(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
}

void	heredoc_ctrl_c(int signum)
{// (SIGINT:(ctrl+c:인터럽트시그널/프로그램종료시킴))이 입력됬을때  (SIGINT:(ctrl+c:인터럽트시그널/프로그램종료시킴))를 실행시키고 개행출력하는 함수 -> 히어독 동작중에도 언제든지 ctrl+c를 사용할 수있다~
	if (signum != SIGINT)//입력된 시그널값(signum)이 (SIGINT:(ctrl+c:인터럽트시그널/프로그램종료시킴))가 아니라면 
		return ;// 함수 종료
	write(1, "\n", 1);// 표준출력(1)에 개행출력
	exit(1); // 종료해
}

void	ctrl_c(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 0);
	rl_redisplay();
	g_exit_status = 1;
}
