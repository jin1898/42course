/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_single_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 00:48:06 by hamjihyeon        #+#    #+#             */
/*   Updated: 2023/07/14 15:12:40 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

static int	set_fd_child(t_cmd_info *cmd_arr)
{ // 자식프로세스에서 파일 디스크립트를 설정하는 함수
	if (cmd_arr->in_fd)
		dup2(cmd_arr->in_fd, STDIN_FILENO);// 입력 리다이렉션 파일 디스크립터를 표준 입력(STDIN_FILENO)으로 복제.
	if (cmd_arr->out_fd)
		dup2(cmd_arr->out_fd, STDOUT_FILENO);// 출력 리다이렉션 파일 디스크립터를 표준 출력(STDOUT_FILENO)으로 복제.
	return (0);
}

static	int	run_child(pid_t *pid, t_cmd_info *cmd_arr, \
t_env_manager *env_manager)
{ //자식 프로세스를 생성하고 파일 디스크립터를 설정한 후 외부 명령어 fork실행, 실패한 경우 에러 메시지를 출력하고 자원을 정리.
	*pid = fork();// 새로운 자식 프로세스를 생성하고, 자식 프로세스의 PID를 저장
	if (*pid == -1 && ft_printf(2, "minishell: %s: fork error\n", \
		cmd_arr->argv[0]))
		free_for_exit(env_manager, 1);// fork 실패 시 에러 메시지를 출력하고, 메모리 해제 함수를 호출하여 종료 전에 할당된 자원을 정리
	if (*pid == 0 && !set_fd_child(cmd_arr))// 자식 프로세스 일경우
		run_execve(cmd_arr, env_manager); //함수 실행
	return (0);
}

int	execute_single_pipe(t_cmd_info *cmd_arr, t_env_manager *env_manager)
{//단일 파이프 실행 
	pid_t	pid; // 자식 프로세스의 PID를 저장하기 위한 변수
	int		child_status; // 자식 프로세스의 종료 상태를 저장하기 위한 변수
	int		signum; // 시그널 번호를 저장하기 위한 변수

	if (cmd_arr && cmd_arr->pipe_num == 0)//cmd_arr이 유효하고 파이프 갯수가 0개일시
	{
		if (cmd_arr->is_redir_error)// 리다이렉션 에러가 있다면
			return (1); // 바로 종료 
		if (!cmd_arr->argv || !*cmd_arr->argv) //argv가 없을시 
			return (0);//0으로 반환해 실행중지
		if (run_built_in(cmd_arr, env_manager) == -1)// run_built_in명령어를 실행하는 함수를 호출하고, 반환 값이 -1인 경우
		{
			set_parent_ignore_signal();// 부모 프로세스의 시그널 처리를 무시
			run_child(&pid, cmd_arr, env_manager);// 자식 프로세스를 생성하여 명령어 실행
			waitpid(pid, &child_status, 0);// 자식 프로세스의 종료를 기다림
			check_exit_status(child_status, &signum);// 자식 프로세스의 종료 상태와 시그널 번호를 확인
			if (signum && signum == SIGQUIT)// 시그널 번호가 SIGQUIT(3)인 경우
				ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);// "Quit: 3"을 표준 출력에 출력
			else if (signum)// 시그널 번호가 있는 경우
				ft_putstr_fd("\n", STDOUT_FILENO);// 개행 문자를 표준 출력에 출력
			set_signal();// 시그널 처리 설정을 원래대로 복원
		}
	}
	return (0);// 0을 반환하여 정상 종료
}
