/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:41:57 by jihham            #+#    #+#             */
/*   Updated: 2023/07/13 17:30:14 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

int	ft_output(char *outfile)
{
	return (open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0644));
}

int	ft_input(char *infile)
{
	return (open(infile, O_RDONLY));
}

int	ft_heredoc(char *delimiter, int i, \
	t_env_manager *env_manager, int *is_sigint)
{//히어독리다이렉션을 처리/필요한 파일 디스크립터를 열고 닫는다/자식프로세스생성해서 리다이렉션 내용 처리/ 종료상태확인해서 추가작업실행
	int		fd;
	pid_t	pid;
	int		child_status;
	int		signum;

	fd = new_heredoc_open(i); //새 파일 디스크립트 열고 fd받음, 히어독 리다이렉션에 사용될 예정
	set_signal_parent();// 부모 프로세스의 시그널 처리를 설정하는 함수
	pid = fork();//자식프로세스 생성후 자식프로세스 pid 저장
	if (pid == -1 && ft_printf(2, "minishell: here_doc: fork error\n"))//fork 실패시 -1 에러 출력후 -1 리턴
		return (-1);
	else if (pid == 0) //실행중인 프로세스가 자식프로세스이면 아래실행
		heredoc_child_check(delimiter, fd, env_manager); // 히어독 리다이렉션 처리후 fd 파일 디스크립터에 해당 내용을 저장
	waitpid(pid, &child_status, 0);// 부모프로세스가 자식프로세스를 기다림, 자식프로세스 종료되면 child_status 변수에 자식프로세스 종료 상태를 저장
	check_exit_status(child_status, &signum); // 자식프로세스의 종료상태를 확인후 signum 에 결과 저장
	if (WIFEXITED(child_status)) //자식프로세스가 정상적으로 종료됬을 경우 아래 실행
	{
		g_exit_status = WEXITSTATUS(child_status); // 전역변수에 자식프로세스 종료 상태를 저장
		*is_sigint = WEXITSTATUS(child_status);// 자식프로세스 종료 상태를 저장 (시그널 발생했는지 추적하기 위함)
	}
	if (fd > -1) // 파일 디스크립터가 아직 열려있다면
	{
		close(fd); // 파일디스크립터 닫아주기 
		fd = heredoc_open(i); // 새로운파일디스크립터 열고 fd에 저장
	}
	return (fd);//히어독 리다이렉션 파일 디스크립터 돌려주기
}

int	ft_append(char *outfile)
{
	return (open(outfile, O_CREAT | O_APPEND | O_WRONLY, 0644));
}
