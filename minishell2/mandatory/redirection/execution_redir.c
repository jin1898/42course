/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:16:08 by hyseong           #+#    #+#             */
/*   Updated: 2023/07/21 19:34:25 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

static int	ft_redir_heredoc(t_cmd_info *cmd_arr, \
	t_env_manager *env_manager, int *is_sigint)
{
	t_cmd_info	*temp;
	t_redir		*temp_redir;

	temp = cmd_arr;
	while (temp)
	{
		temp->here_doc_cnt = 0;
		temp_redir = temp->redir;
		while (temp_redir)
		{
			if (temp_redir->type == HERE_DOC && *is_sigint == 0)
			{
				if (temp->in_fd != 0)
					close(temp->in_fd);
				temp->in_fd = ft_heredoc(temp_redir->str, \
					temp->here_doc_cnt, env_manager, is_sigint);
				temp->here_doc_cnt++;
			}
			temp_redir = temp_redir->next;
		}
		temp = temp->next;
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

static void	ft_access_error(char *temp)
{
	perror(temp);
	free(temp);
	g_exit_status = 1;
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
			ft_access_error(temp);
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
{
	t_cmd_info	*temp;
	t_redir		*temp_redir;
	int			result;

	ft_redir_heredoc(cmd_arr, env_manager, is_sigint);
	temp = cmd_arr;
	while (temp)
	{
		temp_redir = temp->redir;
		while (temp_redir)
		{
			result = ft_check_redir(temp, temp_redir);
			if (result)
			{
				temp->is_redir_error = 1;
				break ;
			}
			temp_redir = temp_redir->next;
		}
		temp = temp->next;
	}
	return (0);
}
