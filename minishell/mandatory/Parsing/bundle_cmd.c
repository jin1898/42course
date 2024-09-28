/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bundle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:01:23 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/07/21 20:10:18 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_redir(t_redir **redir_now, t_list **token_now, \
t_value *value, t_env_manager *env_lst)
{
	int	check_ambiguous;

	check_ambiguous = 0;
	value->redir = 1;
	(*redir_now)->type = redir_type((*token_now)->content);
	(*token_now) = (*token_now)->next;
	check_ambiguous = check_mbgos((*token_now)->content, value, env_lst);
	if ((*redir_now)->type != HERE_DOC && !check_ambiguous)
	{
		(*redir_now)->str = \
		replace_symbol_to_text((*token_now)->content, env_lst, value);
	}
	else
		(*redir_now)->str = ft_strdup((*token_now)->content);
	return (check_ambiguous);
}

static void	word_etc(t_cmd_info **cmd_info_arr_now, t_value *value, \
t_list *token_now, t_env_manager *env_lst)
{
	(*cmd_info_arr_now)->argv[value->av_i] = \
	replace_symbol_to_text(token_now->content, env_lst, value);
	value->av_i += 1;
}

static void	ft_pip(t_value *value, t_cmd_info \
**cmd_info_arr_now, t_redir **redir_now)
{
	value->av_i = 0;
	(*cmd_info_arr_now) = (*cmd_info_arr_now)->next;
	(*redir_now) = (*cmd_info_arr_now)->redir;
}

static void	init_value(t_value *value)
{
	value->av_i = 0;
	value->cmd_i = 0;
	value->redir = 0;
}

void	fill_cmd_info_arr(t_cmd_info *cmd_info_arr, \
t_list *token_list, t_env_manager	*env_lst)
{
	t_list		*token_now;
	t_value		value;
	t_redir		*redir_now;
	t_cmd_info	*cmd_info_arr_now;

	token_now = token_list;
	init_value(&value);
	cmd_info_arr_now = cmd_info_arr;
	redir_now = cmd_info_arr_now->redir;
	while (token_now)
	{
		if (!ft_strncmp(token_now -> content, "|", 2))
			ft_pip(&value, &cmd_info_arr_now, &redir_now);
		else if (check_redir(token_now -> content))
		{
			if ((ft_redir(&redir_now, &token_now, &value, env_lst) > 1) \
			&& value.mbgos == 1)
				cmd_info_arr_now->redir->type = 'a';
			redir_now = redir_now->next;
		}
		else
			word_etc(&cmd_info_arr_now, &value, token_now, env_lst);
		token_now = token_now -> next;
	}
}
