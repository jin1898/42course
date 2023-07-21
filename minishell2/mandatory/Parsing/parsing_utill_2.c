/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utill_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:48:17 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/07/21 21:27:58 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

int	get_pipnum(t_list *token_list)
{
	t_list	*cur;
	int		pipe_num;

	cur = token_list;
	pipe_num = 0;
	while (cur)
	{
		if (!ft_strncmp(cur->content, "|", 2))
			pipe_num += 1;
		cur = cur -> next;
	}
	return (pipe_num);
}

int	check_space(char ch)
{
	if (ch == ' ' || ch == '\t')
		return (1);
	return (0);
}

void	print_token_err(char *str, t_cmd_info *cmd_info_arr)
{
	free_eveything(0, &cmd_info_arr);
	if (!strncmp(str, "|", 2))
		str = " `|\'";
	ft_printf(1, "minishell: syntax error near unexpected token %s\n", str);
	g_exit_status = 258;
}

int	redir_type(char *str)
{
	if (!ft_strncmp(str, "<", 2))
		return (INFILE);
	if (!ft_strncmp(str, "<<", 3))
		return (HERE_DOC);
	if (!ft_strncmp(str, ">", 2))
		return (OUTFILE);
	if (!ft_strncmp(str, ">>", 3))
		return (FILE_APPEND);
	return (0);
}
