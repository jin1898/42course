/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_single_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:17:15 by hyseong           #+#    #+#             */
/*   Updated: 2023/07/21 19:26:00 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

static int	set_fd_child(t_cmd_info *cmd_arr)
{
	if (cmd_arr->in_fd)
		dup2(cmd_arr->in_fd, STDIN_FILENO);
	if (cmd_arr->out_fd)
		dup2(cmd_arr->out_fd, STDOUT_FILENO);
	return (0);
}

static int	run_built_in_single(t_cmd_info *cmd_arr, t_env_manager *env_manager)
{
	int	res;

	res = -1;
	if (!cmd_arr->argv || !*(cmd_arr->argv))
		return (-1);
	if (ft_strncmp(*cmd_arr->argv, "echo", 5) == 0)
		res = ft_echo(cmd_arr->argv + 1);
	else if (ft_strncmp(*(cmd_arr->argv), "env", 4) == 0)
		res = ft_env(env_manager);
	else if (ft_strncmp(*(cmd_arr->argv), "pwd", 4) == 0)
		res = ft_pwd();
	if (res != -1)
	{
		g_exit_status = res;
		exit(g_exit_status);
	}
	return (res);
}

static int	check_cd_and_exit(t_cmd_info *cmd_arr, t_env_manager *env_manager)
{
	int	res;

	res = -1;
	if (!cmd_arr->argv || !*(cmd_arr->argv))
		return (-1);
	if (ft_strncmp(*(cmd_arr->argv), "cd", 3) == 0)
		res = ft_cd(cmd_arr->argv + 1, env_manager);
	else if (ft_strncmp(*(cmd_arr->argv), "exit", 5) == 0)
		res = ft_exit(cmd_arr->argv + 1);
	else if (ft_strncmp(*(cmd_arr->argv), "export", 7) == 0)
		res = ft_export(cmd_arr->argv + 1, env_manager);
	else if (ft_strncmp(*(cmd_arr->argv), "unset", 6) == 0)
		res = ft_unset(cmd_arr->argv + 1, env_manager);
	if (res != -1)
		g_exit_status = res;
	return (res);
}

static	int	run_child(pid_t *pid, t_cmd_info *cmd_arr, \
t_env_manager *env_manager)
{
	*pid = fork();
	if (*pid == -1 && ft_printf(2, "minishell: %s: fork error\n", \
		cmd_arr->argv[0]))
		free_for_exit(env_manager, 1);
	if (*pid == 0 && !set_fd_child(cmd_arr))
		if (run_built_in_single(cmd_arr, env_manager) == -1)
			run_execve(cmd_arr, env_manager);
	return (0);
}

int	execute_single_pipe(t_cmd_info *cmd_arr, t_env_manager *env_manager)
{
	pid_t	pid;
	int		child_status;
	int		signum;

	if (cmd_arr && cmd_arr->pipe_num == 0)
	{
		if (cmd_arr->is_redir_error)
			return (1);
		if (!cmd_arr->argv || !*cmd_arr->argv)
			return (0);
		if (check_cd_and_exit(cmd_arr, env_manager) == -1)
		{
			set_parent_ignore_signal();
			run_child(&pid, cmd_arr, env_manager);
			waitpid(pid, &child_status, 0);
			check_exit_status(child_status, &signum);
			if (signum && signum == SIGQUIT)
				ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
			else if (signum)
				ft_putstr_fd("\n", STDOUT_FILENO);
			set_signal();
		}
	}
	return (0);
}
