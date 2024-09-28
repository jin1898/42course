/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseong <hyseong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:17:20 by hyseong           #+#    #+#             */
/*   Updated: 2023/07/21 17:17:21 by hyseong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

int	run_built_in(t_cmd_info *cmd_arr, t_env_manager *env_manager)
{
	int	res;

	res = -1;
	if (!cmd_arr->argv || !*(cmd_arr->argv))
		return (-1);
	if (ft_strncmp(*(cmd_arr->argv), "cd", 3) == 0)
		res = ft_cd(cmd_arr->argv + 1, env_manager);
	else if (ft_strncmp(*cmd_arr->argv, "echo", 5) == 0)
		res = ft_echo(cmd_arr->argv + 1);
	else if (ft_strncmp(*(cmd_arr->argv), "env", 4) == 0)
		res = ft_env(env_manager);
	else if (ft_strncmp(*(cmd_arr->argv), "exit", 5) == 0)
		res = ft_exit(cmd_arr->argv + 1);
	else if (ft_strncmp(*(cmd_arr->argv), "export", 7) == 0)
		res = ft_export(cmd_arr->argv + 1, env_manager);
	else if (ft_strncmp(*(cmd_arr->argv), "pwd", 4) == 0)
		res = ft_pwd();
	else if (ft_strncmp(*(cmd_arr->argv), "unset", 6) == 0)
		res = ft_unset(cmd_arr->argv + 1, env_manager);
	if (res != -1)
		g_exit_status = res;
	return (res);
}

void	run_execve(t_cmd_info *cmd_arr, t_env_manager *env_manager)
{
	set_child_signal();
	if (execve(cmd_arr->argv[0], \
		cmd_arr->argv, env_list_to_arr(env_manager)))
	{
		if (opendir(cmd_arr->argv[0]) && \
			ft_printf(2, "minishell: %s: is a directory\n", cmd_arr->argv[0]))
			exit(126);
		else
		{
			if (ft_strchr(cmd_arr->argv[0], '/'))
				ft_printf(2, "minishell: %s: No such file or directory\n", \
				cmd_arr->argv[0]);
			else
				ft_printf(2, "minishell: %s: command not found\n", \
				cmd_arr->argv[0]);
			exit(127);
		}
	}
}

int	ft_execution(t_cmd_info *cmd_arr, t_env_manager *env_manager)
{
	int	is_sigint;

	is_sigint = 0;
	ft_redirection(cmd_arr, env_manager, &is_sigint);
	if (cmd_arr->pipe_num == 0)
		execute_single_pipe(cmd_arr, env_manager);
	else
		execute_multiple_pipe(cmd_arr, env_manager);
	return (0);
}
