/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_multiple_pipe.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseong <hyseong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:17:11 by hyseong           #+#    #+#             */
/*   Updated: 2023/07/21 17:17:12 by hyseong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	set_fd(t_cmd_info *cmd_arr, int pipe_fd[], int old_fd, int i)
{
	close(pipe_fd[0]);
	if (cmd_arr->in_fd > 0)
	{
		dup2(cmd_arr->in_fd, STDIN_FILENO);
		if (i != 0)
			close(old_fd);
	}
	else if (i != 0)
	{
		dup2(old_fd, STDIN_FILENO);
		close(old_fd);
	}
	if (cmd_arr->out_fd > 0)
		dup2(cmd_arr->out_fd, STDOUT_FILENO);
	else if (i != cmd_arr->pipe_num)
		dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
}

static int	run_another(t_cmd_info *cmd_arr, t_env_manager *env_manager)
{
	if (!cmd_arr->argv || !*cmd_arr->argv)
		exit(1);
	if (run_built_in(cmd_arr, env_manager) == -1)
		run_execve(cmd_arr, env_manager);
	else
		exit(1);
	return (0);
}

static int	run_children(pid_t *pids, t_cmd_info *cmd_arr, \
	t_env_manager *env_manager)
{
	int		pipe_fd[2];
	int		old_fd;
	int		i;

	i = -1;
	while (cmd_arr && ++i <= cmd_arr->pipe_num)
	{
		pipe(pipe_fd);
		pids[i] = fork();
		if (pids[i] == 0)
		{
			if (cmd_arr->is_redir_error)
				exit (1);
			set_fd(cmd_arr, pipe_fd, old_fd, i);
			run_another(cmd_arr, env_manager);
		}
		if (i != 0)
			close(old_fd);
		old_fd = pipe_fd[0];
		close(pipe_fd[1]);
		cmd_arr = cmd_arr->next;
	}
	close(pipe_fd[0]);
	return (0);
}

static int	wait_children(pid_t *pids, t_cmd_info *cmd_arr)
{
	int	i;
	int	child_status;
	int	signum;

	i = -1;
	while (cmd_arr)
	{
		if (cmd_arr->is_redir_error)
		{
			cmd_arr = cmd_arr->next;
			i++;
			continue ;
		}
		waitpid(pids[++i], &child_status, 0);
		check_exit_status(child_status, &signum);
		cmd_arr = cmd_arr->next;
	}
	if (signum && signum == SIGQUIT)
		ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
	else if (signum)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}

int	execute_multiple_pipe(t_cmd_info *cmd_arr, t_env_manager *env_manager)
{
	pid_t		*pids;

	pids = malloc(sizeof(pid_t) * (cmd_arr->pipe_num + 1));
	set_parent_ignore_signal();
	run_children(pids, cmd_arr, env_manager);
	wait_children(pids, cmd_arr);
	ft_free_util((void **)&pids);
	return (0);
}
