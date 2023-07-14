/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_multiple_pipe.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 00:46:50 by hamjihyeon        #+#    #+#             */
/*   Updated: 2023/07/14 15:10:25 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	set_fd(t_cmd_info *cmd_arr, int pipe_fd[], int old_fd, int i)
{//명령어에 대한 파일 디스크립터를 설정한다. 입력 리다이렉션이나 출력 리다이렉션이 존재하는 경우 해당 파일 디스크립터를 표준 입력 또는 표준 출력으로 복제하고, 파이프를 연결한다., 이전 파이프의 파일 디스크립터를 닫아준다.
	close(pipe_fd[0]);// 현재 파이프의 읽기용 파일 디스크립터를 닫음
	if (cmd_arr->in_fd > 0)// 입력 리다이렉션이 있는 경우
	{
		dup2(cmd_arr->in_fd, STDIN_FILENO);// 입력 리다이렉션을 표준 입력으로 복제
		if (i != 0)// 첫 번째 명령어가 아니라면
			close(old_fd);// 이전 파이프의 파일 디스크립터를 닫음
	}
	else if (i != 0)// 입력 리다이렉션이 없고 첫 번째 명령어가 아닌 경우
	{
		dup2(old_fd, STDIN_FILENO);// 이전 파이프의 파일 디스크립터를 표준 입력으로 복제
		close(old_fd);// 이전 파이프의 파일 디스크립터를 닫음
	}
	if (cmd_arr->out_fd > 0)// 출력 리다이렉션이 있는 경우
		dup2(cmd_arr->out_fd, STDOUT_FILENO); // 출력 리다이렉션을 표준 출력으로 복제
	else if (i != cmd_arr->pipe_num)// 출력 리다이렉션이 없고 마지막 명령어가 아닌 경우
		dup2(pipe_fd[1], STDOUT_FILENO); // 현재 파이프의 쓰기용 파일 디스크립터를 표준 출력으로 복제
	close(pipe_fd[1]);// 현재 파이프의 쓰기용 파일 디스크립터를 닫음
}

static int	run_another(t_cmd_info *cmd_arr, t_env_manager *env_manager)
{//명령어 자체가 존재하지 않는 경우나 실행에 실패한 경우 프로세스를 종료한다.
	if (!cmd_arr->argv || !*cmd_arr->argv)// 명령어의 argv가 없거나 첫 번째 요소가 없는 경우
		exit(1);// 종료 코드 1로 프로세스를 종료
	if (run_built_in(cmd_arr, env_manager) == -1)// 내장 명령어를 실행하고 실패한 경우
		run_execve(cmd_arr, env_manager);// execve를 통해 외부 명령어 실행
	else
		exit(1);// 내장 명령어 실행에 실패한 경우 종료 코드 1로 프로세스를 종료
	return (0);
}

static int	run_children(pid_t *pids, t_cmd_info *cmd_arr, \
	t_env_manager *env_manager)
{ // 여러 개의 파이프를 이용하여 자식 프로세스들을 생성하고 실행하는 함수
	int		pipe_fd[2];// 파이프의 파일 디스크립터를 저장하기 위한 배열
	int		old_fd;// 이전 파이프의 파일 디스크립터
	int		i;

	i = -1;
	while (cmd_arr && ++i <= cmd_arr->pipe_num)// cmd_arr이 유효하고 파이프의 개수까지 반복
	{
		pipe(pipe_fd);// 파이프 생성
		pids[i] = fork();// 자식 프로세스 생성
		if (pids[i] == 0)// 자식 프로세스인 경우
		{
			if (cmd_arr->is_redir_error)// 리다이렉션 에러가 있다면
				exit (1);// 1로 종료
			set_fd(cmd_arr, pipe_fd, old_fd, i);// 파일 디스크립터 설정
			run_another(cmd_arr, env_manager);// 다음 명령어 실행
		}
		if (i != 0) // 이전 파이프의 파일 디스크립터를 복제했던걸 닫는다.->첫파이프가 아닌경우에 이전파이프의 파일 디스크립터를 복제하고 닫는다. 이유 : 현재파이프의 파일 디스크릷터와 이전파이프의 파일디스크립터가 분리되서 각각의 자식 프로세스가 독립적으로 사용가능하기 때문이다.
			close(old_fd); // 이전 파이프의 출력 파일 디스크립터는 현재 파이프의 입력 파일 디스크립터로 사용되므로, 이전 파이프의 출력 파일 디스크립터를 닫아야 한다.이를 통해 이전 파이프와 현재 파이프의 파일 디스크립터가 분리되어 각각의 자식 프로세스가 독립적으로 사용할 수 있게 된다.
		old_fd = pipe_fd[0];// 현재 파이프의 입력 파일 디스크립터를 이전 파이프의 입력 파일 디스크립터로 설정
		close(pipe_fd[1]);// 현재 파이프의 출력 파일 디스크립터를 닫음 ->쓰기파일디스크립터를 닫음 쓰기 연산이 이루어지지않음
		cmd_arr = cmd_arr->next;// 다음 명령어로 이동
	}
	close(pipe_fd[0]);// 마지막 파이프의 입력 파일 디스크립터를 닫음
	return (0);
}

static int	wait_children(pid_t *pids, t_cmd_info *cmd_arr)//pids에는 자식프로세스의 PID있음 
{//자식 프로세스들이 모두 종료될 때까지 기다렸다가 종료 상태를 확인하고 출력하는 것입니다. 리다이렉션 에러가 있는 경우는 대기하지 않고 다음 명령어로 이동
	int	i;
	int	child_status;
	int	signum;

	i = -1;
	while (cmd_arr)
	{
		if (cmd_arr->is_redir_error)// 리다이렉션 에러가 있는 경우
		{
			cmd_arr = cmd_arr->next;// 다음 명령어로 이동
			i++;// 자식 프로세스 인덱스 증가
			continue ;
		}
		waitpid(pids[++i], &child_status, 0);//자식 프로세스의 종료를 대기
		check_exit_status(child_status, &signum);// 자식 프로세스의 종료 상태 확인
		cmd_arr = cmd_arr->next;// 다음 명령어로 이동
	}
	if (signum && signum == SIGQUIT)// signum이 SIGQUIT인 경우
		ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);// "Quit: 3" 메시지 출력
	else if (signum)// signum이 0이 아닌 경우
		ft_putstr_fd("\n", STDOUT_FILENO);// 개행 출력
	return (0);
}

int	execute_multiple_pipe(t_cmd_info *cmd_arr, t_env_manager *env_manager)
{// 여러 개의 파이프로 구성된 명령어를 실행한다.
	pid_t		*pids; // 자식 프로세스의 PID를 저장하기 위한 배열

	pids = malloc(sizeof(pid_t) * (cmd_arr->pipe_num + 1)); // 자식 프로세스의 PID를 저장할 배열 동적 할당
	set_parent_ignore_signal();// 부모 프로세스가 SIGINT 및 SIGQUIT 시그널을 무시하도록 설정
	run_children(pids, cmd_arr, env_manager);// 여러 개의 자식 프로세스를 생성하여 실행
	wait_children(pids, cmd_arr);// 자식 프로세스가 종료될 때까지 대기
	ft_free_util((void **)&pids);// 자식 프로세스의 PID 배열 동적 할당 해제
	return (0);
}
