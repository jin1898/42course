/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 05:53:00 by seonghle          #+#    #+#             */
/*   Updated: 2023/07/14 22:37:01 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status = 0;

static void	ctrl_d(t_env_manager *env_manager, char *line)
{//ctrl_d 함수는 line이 NULL일 때, ANSI 이스케이프 시퀀스를 사용하여 터미널에 메시지를 출력하고, free_for_exit 함수를 호출하여 메모리를 해제하고 프로그램을 종료한다.
	if (!line && ft_printf(1, "\x1b[1A\x1b[33;1m\x1b[22m\033[12Cexit\n\033[0m"))// ANSI 이스케이프 시퀀스 해석 : "exit"라는 텍스트를 노란색으로 표시하고, 오른쪽으로 12칸 이동시킨 후 출력하는 효과를 갖고있음
		free_for_exit(env_manager, 0);
}

void	free_eveything(char **line, t_cmd_info **cmd_arr)
{
	t_cmd_info	*cmd_c;
	int			i;
	t_redir		*r_tmp;
	t_cmd_info	*c_tmp;

	cmd_c = *cmd_arr;
	if (line)
		free(*line);
	while (cmd_c)
	{
		i = -1;
		while (cmd_c->argv && cmd_c->argv[++i])
			free(cmd_c->argv[i]);
		free(cmd_c->argv);
		while (cmd_c->redir)
		{
			r_tmp = cmd_c->redir;
			cmd_c->redir = cmd_c->redir->next;
			free(r_tmp->str);
			free(r_tmp);
		}
		c_tmp = cmd_c->next;
		free(cmd_c);
		cmd_c = c_tmp;
	}
}

static	void	close_fd(t_cmd_info *cmd_arr)
{//명령어 정보를 담고 있는 연결 리스트를 순회하면서 입력 및 출력 파일 디스크립터를 닫는다
	while (cmd_arr)
	{
		if (cmd_arr->in_fd)// 입력 파일 디스크립터가 할당되어 있으면
			close(cmd_arr->in_fd);// 해당 파일 디스크립터를 닫음
		if (cmd_arr->out_fd)// 출력 파일 디스크립터가 할당되어 있으면
			close(cmd_arr->out_fd);// 해당 파일 디스크립터를 닫음
		cmd_arr = cmd_arr->next;// 다음 명령어로 이동
	}
}

static int	init_main(int argc, char **argv, t_env_manager *env_manager)
{
	(void)argv;
	(void)argc;
	ft_memset(env_manager, 0, sizeof(t_env_manager));
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char			*line;
	t_cmd_info		*cmd_arr;
	t_env_manager	env_manager;

	// atexit(f);
	init_main(argc, argv, &env_manager);
	if (env_arr_to_list(&env_manager, envp))// 환경 변수 배열을 환경 변수 링크드 리스트로 변환하여 관리한다.
		return (1);
	while (1)
	{
		set_signal();//터미널 속성을 변경하고, 시그널 핸들러를 설정하여 Ctrl+C 시그널을 처리하는 기능을 만든다.
		heredoc_unlink(); // /tmp 디렉토리에서 확장자가 .mine인 파일을 찾아서(모든 엔트리를 다확인해서 엔트리 이름이 ".mine"인 엔트리를 찾는다.) 삭제하는 함수다.
		line = readline("minishell > "); //입력값을 readline으로 받음
		ctrl_d(&env_manager, line);//line이 NULL일 때, ANSI 이스케이프 시퀀스를 사용하여 터미널에 메시지를 출력하고, free_for_exit 함수를 호출하여 메모리를 해제하고 프로그램을 종료.
		cmd_arr = parsing_allparts(line, &env_manager); //1차파씽
		if (cmd_arr)// 널일경우 에러상황으로 아무행동을하지않기 위함
			parsing_command(cmd_arr, expand_env("PATH", 0, &env_manager)); //2차 파씽
		if (cmd_arr)// 널일경우 에러상황으로 아무행동을하지않기 위함
			ft_execution(cmd_arr, &env_manager); //입력값에 대한 실행
		if (*line != 0)
			add_history(line);//사용자가 명령어를 입력할 때마다 add_history 함수를 호출하여 해당 명령어를 히스토리에 추가
		close_fd(cmd_arr);//모든 파일디스크립터 닫기
		free_eveything(&line, &cmd_arr); //파씽부 전부다 free해주기
		// system("leaks --list -- minishell");
	}
	return (!free_env(&env_manager));
}

//뭔가 느낌이 쎄한건 //**** 표시해놨음