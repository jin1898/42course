/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_info_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:53:23 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/07/21 20:29:37 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_exit_status;

static int	redir_error(int cnt[], t_list **token_now, t_cmd_info *cmd_info_arr)
{
	cnt[REDIR] += 1;
	(*token_now) = (*token_now)->next;
	if ((*token_now) == NULL || check_redir((*token_now)->content) \
	|| !ft_strncmp((*token_now)->content, "|", 2))
	{
		if ((*token_now) == NULL)
			ft_printf(1, "minishell: syntax error near \
			unexpected token `newline'\n");
		else
			print_token_err((*token_now)->content, cmd_info_arr);
		return (0);
	}
	else
		return (1);
}

static int	error_check(t_list **token_now, t_cmd_info \
**cmd_info_arr, t_list **token_list)
{
	if ((*token_now)->next == NULL)
	{
		print_token_err(" `|\'", *cmd_info_arr);
		free_list1(token_list);
		return (0);
	}
	else if (((*token_now)->next == 0) || \
	(!ft_strncmp((*token_now)->next->content, "|", 2)))
	{
		print_token_err(" `|\'", *cmd_info_arr);
		free_list1(token_list);
		return (0);
	}
	else if (!ft_strncmp((*token_list)->content, "|", 2))
	{
		print_token_err(" `|\'", *cmd_info_arr);
		free_list1(token_list);
		return (0);
	}
	else
		return (1);
}

static void	init_var(int cnt[], t_cmd_info **cmd_info_arr, \
t_cmd_info **cmd_now, int pipe_num)
{
	cnt[ARGC] = 0;
	cnt[REDIR] = 0;
	*cmd_info_arr = make_to_list_cmdinfo(pipe_num);
	*cmd_now = *cmd_info_arr;
}

t_cmd_info	*cmd_arr_init(t_list \
**token_list, int pipe_num)
{
	t_cmd_info	*cmd_info_arr;
	t_list		*token_now;
	t_cmd_info	*cmd_now;
	int			cnt[2];

	token_now = *token_list;
	init_var(cnt, &cmd_info_arr, &cmd_now, pipe_num);
	while (token_now)
	{
		if (!ft_strncmp(token_now -> content, "|", 2))
		{
			init_cmd_info(cmd_now, cnt);
			cmd_now = cmd_now->next;
			if (!error_check(&token_now, &cmd_info_arr, token_list))
				return (NULL);
		}
		else if (check_redir(token_now -> content) && \
		(!redir_error(cnt, &token_now, cmd_info_arr)))
			return (NULL);
		else
			cnt[ARGC] += 1;
		token_now = token_now->next;
	}
	init_cmd_info(cmd_now, cnt);
	return (cmd_info_arr);
}
