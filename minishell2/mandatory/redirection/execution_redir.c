/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:38:54 by jihham            #+#    #+#             */
/*   Updated: 2023/07/13 17:27:11 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

static int	ft_redir_heredoc(t_cmd_info *cmd_arr, \
	t_env_manager *env_manager, int *is_sigint)
{//heredoc을 처리한다. 이때 각 필요한 파일디스크립터를 열고 닫는다.
	t_cmd_info	*temp;
	t_redir		*temp_redir;

	temp = cmd_arr; //정보순회용도
	while (temp)
	{
		temp->here_doc_cnt = 0;//히어독 갯수 저장
		temp_redir = temp->redir;// 순회하기 위한 변수 
		while (temp_redir)//리다이렉션 하나하나 방문
		{
			if (temp_redir->type == HERE_DOC && *is_sigint == 0)//here_doc이고 시그널에 변화가 없을시
			{
				if (temp->in_fd != 0) //이미 열린 파일 디스크립터가 있을 시
					close(temp->in_fd); //in파일 디스크립터를 닫아준다.
				temp->in_fd = ft_heredoc(temp_redir->str, \
					temp->here_doc_cnt, env_manager, is_sigint); //heredoc함수에서 히어독 처리후 결과값으로 얻은 파일디스크립터를 in_fd에 저장
				temp->here_doc_cnt++;//히어독 갯수 새는중 ++ 
			}
			temp_redir = temp_redir->next; //다음 redir구조체로 이동
		}
		temp = temp->next; //다음 cmd_info 구조체로 이동
	}
	return (0);
}

static int	ft_outfile(int *fd, int type, char *str)
{
	if (*fd != 0)
		close(*fd);
	if (type == OUTFILE)
		*fd = ft_output(str);
	else if (type == FILE_APPEND)
		*fd = ft_append(str);
	if (*fd == -1)
	{
		perror(str);
		g_exit_status = 1;
		return (g_exit_status);
	}
	return (0);
}

static int	ft_check_redir(t_cmd_info *cmd_info, t_redir *redir)
{
	char	*temp;

	if (redir->type == AMBIGUOUS)
		return (1 | !ft_printf(2, "minishell: %s: ambiguous redirect\n", \
			redir->str));
	if (redir->type == HERE_DOC)
		cmd_info->here_doc_cnt--;
	else if (redir->type == INFILE)
	{
		if (access(redir->str, F_OK | R_OK) == -1)
		{
			temp = ft_strjoin("minishell: ", redir->str);
			perror(temp);
			free(temp);
			g_exit_status = 1;
			return (1);
		}
		else if (!cmd_info->here_doc_cnt)
		{
			if (cmd_info->in_fd != 0)
				close(cmd_info->in_fd);
			cmd_info->in_fd = ft_input(redir->str);
		}
	}
	else
		return (ft_outfile(&cmd_info->out_fd, redir->type, redir->str));
	return (0);
}

int	ft_redirection(t_cmd_info *cmd_arr, \
	t_env_manager *env_manager, int *is_sigint)
{//히어독, 리다이렉션 처리 및 에러검사
	t_cmd_info	*temp;
	t_redir		*temp_redir;
	int			result;

	ft_redir_heredoc(cmd_arr, env_manager, is_sigint);
	temp = cmd_arr;// cmd_arr 정보순회 용도
	while (temp)
	{
		temp_redir = temp->redir; //리다이렉션 정보순회 용도
		while (temp_redir)
		{
			result = ft_check_redir(temp, temp_redir);// 리다이렉션 유효성검사 
			if (result) //에러 발견시 작동
			{
				temp->is_redir_error = 1; //리다이렉션 오류 플래그 표시
				break ;
			}
			temp_redir = temp_redir->next; // 다음 리다이렉션으로 이동
		}
		temp = temp->next; //다음 구조체로 이동
	}
	return (0);
}
