/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_info_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:28:36 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/07/21 20:29:20 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_redir(char *str)
{
	if (!ft_strncmp(str, "<", 2))
		return (1);
	if (!ft_strncmp(str, "<<", 3))
		return (1);
	if (!ft_strncmp(str, ">", 2))
		return (1);
	if (!ft_strncmp(str, ">>", 3))
		return (1);
	return (0);
}

int	init_cmd_info(t_cmd_info *cmd_info, int cnt[])
{
	cmd_info->argc = cnt[ARGC];
	if (cnt[ARGC])
	{
		cmd_info->argv = malloc(sizeof(char *) * (cnt[ARGC] + 1));
		ft_memset(cmd_info->argv, 0, (sizeof(*cmd_info->argv) * cnt[ARGC]));
		cmd_info->argv[cnt[ARGC]] = NULL;
	}
	cmd_info->redir_num = cnt[REDIR];
	if (!cmd_info->redir_num)
		cmd_info->redir = NULL;
	else
		cmd_info->redir = make_to_list_redir(cnt[REDIR]);
	cnt[ARGC] = 0;
	cnt[REDIR] = 0;
	return (1);
}

t_cmd_info	*make_to_list_cmdinfo(int num)
{
	int			i;
	t_cmd_info	*now;
	t_cmd_info	*head;

	i = 0;
	head = (t_cmd_info *)malloc(sizeof(t_cmd_info));
	ft_memset(head, 0, sizeof(t_cmd_info));
	now = head;
	while (i < num)
	{
		now->next = (t_cmd_info *)malloc(sizeof(t_cmd_info));
		now = now->next;
		ft_memset(now, 0, sizeof(t_cmd_info));
		i++;
	}
	now->next = NULL;
	return (head);
}

t_redir	*make_to_list_redir(int num)
{
	int		i;
	t_redir	*head;
	t_redir	*now;

	head = (t_redir *)malloc(sizeof(t_redir));
	now = head;
	i = 1;
	ft_memset(head, 0, sizeof(t_redir));
	while (i < num)
	{
		now->next = (t_redir *)malloc(sizeof(t_redir));
		now = now->next;
		ft_memset(now, 0, sizeof(t_redir));
		i++;
	}
	now->next = NULL;
	return (head);
}
