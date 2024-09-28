/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseong <hyseong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:16:23 by hyseong           #+#    #+#             */
/*   Updated: 2023/07/21 17:16:24 by hyseong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

int	ft_output(char *outfile)
{
	return (open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0644));
}

int	ft_input(char *infile)
{
	return (open(infile, O_RDONLY));
}

int	ft_heredoc(char *delimiter, int i, \
	t_env_manager *env_manager, int *is_sigint)
{
	int		fd;
	pid_t	pid;
	int		child_status;
	int		signum;

	fd = new_heredoc_open(i);
	set_signal_parent();
	pid = fork();
	if (pid == -1 && ft_printf(2, "minishell: here_doc: fork error\n"))
		return (-1);
	else if (pid == 0)
		heredoc_child_check(delimiter, fd, env_manager);
	waitpid(pid, &child_status, 0);
	check_exit_status(child_status, &signum);
	if (WIFEXITED(child_status))
	{
		g_exit_status = WEXITSTATUS(child_status);
		*is_sigint = WEXITSTATUS(child_status);
	}
	if (fd > -1)
	{
		close(fd);
		fd = heredoc_open(i);
	}
	return (fd);
}

int	ft_append(char *outfile)
{
	return (open(outfile, O_CREAT | O_APPEND | O_WRONLY, 0644));
}
