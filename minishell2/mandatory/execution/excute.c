/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 03:22:05 by seonghle          #+#    #+#             */
/*   Updated: 2023/07/14 14:28:35 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

int	run_built_in(t_cmd_info *cmd_arr, t_env_manager *env_manager)
{//빌트인이다. 
	int	res;

	res = -1;
	if (!cmd_arr->argv || !*(cmd_arr->argv))
		return (-1);
	if (ft_strncmp(*(cmd_arr->argv), "cd", 3) == 0)
		res = ft_cd(cmd_arr->argv + 1, env_manager); //cd 구현
	else if (ft_strncmp(*cmd_arr->argv, "echo", 5) == 0)
		res = ft_echo(cmd_arr->argv + 1); //echo구현
	else if (ft_strncmp(*(cmd_arr->argv), "env", 4) == 0)
		res = ft_env(env_manager); // env환경변수 출력
	else if (ft_strncmp(*(cmd_arr->argv), "exit", 5) == 0)
		res = ft_exit(cmd_arr->argv + 1);//exit 함수 구현
	else if (ft_strncmp(*(cmd_arr->argv), "export", 7) == 0)
		res = ft_export(cmd_arr->argv + 1, env_manager); // 확장 함수 구현 
	else if (ft_strncmp(*(cmd_arr->argv), "pwd", 4) == 0)
		res = ft_pwd(); //pwd 구현 
	else if (ft_strncmp(*(cmd_arr->argv), "unset", 6) == 0)
		res = ft_unset(cmd_arr->argv + 1, env_manager); //
	if (res != -1)
		g_exit_status = res; // 전역 변수  // 전역 변수 g_exit_status에 결과(에러번호) 저장
	return (res);
}

void	run_execve(t_cmd_info *cmd_arr, t_env_manager *env_manager)
{//execve함수로 명령어 실행,자식프로세스의 시그널 처리 설정하고 execv함수 실행결과 확인한다. 만약 명령어가 디렉토리이면 종료 126로 프로세스 종료, 파일 명령어 없을시 종료코드 127으로 프로세스 종료
	set_child_signal();// 자식 프로세스의 시그널 처리를 설정
	if (execve(cmd_arr->argv[0], \
		cmd_arr->argv, env_list_to_arr(env_manager)))// execve 함수를 통해 명령어 실행을 시도하고, 실패한 경우 실행됩니다.
	{
		if (opendir(cmd_arr->argv[0]) && \
			ft_printf(2, "minishell: %s: is a directory\n", cmd_arr->argv[0]))
			exit(126);// 명령어가 디렉토리인 경우 종료 코드 126로 프로세스를 종료
		else
		{
			if (ft_strchr(cmd_arr->argv[0], '/'))//'/' 문자가 포함되어 있는지 확인한다. 이는 명령어에 경로가 포함되어 있는지를 검사하는 것
				ft_printf(2, "minishell: %s: No such file or directory\n", \
				cmd_arr->argv[0]);//->여기서 2는 출력 스트림 번호로, 2는 표준 에러 출력을 의미
			else
				ft_printf(2, "minishell: %s: command not found\n", \
				cmd_arr->argv[0]);// 만약 명령어에 경로가 포함되어 있지 않다면 에러메세지 출력
			exit(127);// 파일 또는 명령어가 없는 경우 종료 코드 127로 프로세스를 종료
		}
	}
}

int	ft_execution(t_cmd_info *cmd_arr, t_env_manager *env_manager)
{// 명령어의 실행을 위해서 리다이렉션 처리후, 단일 혹은 여러 파이프 실행 
	int	is_sigint;//시그널 상태 추적용 변수

	is_sigint = 0;// 상태값 0으로 만들기 
	ft_redirection(cmd_arr, env_manager, &is_sigint); // //히어독, 리다이렉션 처리 및 에러검사 / is_sigint는 시그널 상태 추적용도
	if (cmd_arr->pipe_num == 0) // 파이프 갯수가 0일시 (파이프가 없는 입력값일 경우)
		execute_single_pipe(cmd_arr, env_manager); // 단일 파이프를 실행하는 함수 실행
	else // 파이프 갯수가 0아닐시 (파이프가 있을시)
		execute_multiple_pipe(cmd_arr, env_manager); //여러 파이프 실행하는 함수 실행
	return (0);
}
