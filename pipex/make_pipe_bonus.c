/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pipe_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:41:03 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/05/01 01:18:22 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	make_and_open_pipe(int argc, t_db *db)
{
	int	i;

	i = 0;
	db->cmdnum = argc - 3 - db->h_flag;
	db->pipebox = (int *)malloc(sizeof(int) * ((db->cmdnum - 1) * 2));
	if (!db->pipebox)
		error_message("pipe");
	while (i < (db->cmdnum - 1))
	{
		if (pipe(db->pipebox + (i * 2)) < 0)
		{
			free_everything(db);
			error_message("pipe");
		}
		i++;
	}
}

void	make_child(t_db *db, char **argv, char **envp)
{
	int		i;
	pid_t	a;

	i = 0;
	while (i < db->cmdnum)
	{
		a = fork();
		if (a == -1)
			error_message("fork error");
		else if (a == 0)
			start_child(db, i, argv, envp);
		i++;
	}
}

void	start_child(t_db *db, int cmd_sequence, char **argv, char **envp)
{
	if (cmd_sequence == 0)
	{
		dup2(db->infilenum, STDIN_FILENO);
		dup2(db->pipebox[1], STDOUT_FILENO);
	}
	else if (cmd_sequence == (db->cmdnum - 1))
	{
		dup2(db->pipebox[2 * cmd_sequence - 2], STDIN_FILENO);
		dup2(db->outfilenum, STDOUT_FILENO);
	}
	else
	{
		dup2(db->pipebox[2 * cmd_sequence - 2], STDIN_FILENO);
		dup2(db->pipebox[2 * cmd_sequence + 1], STDOUT_FILENO);
	}
	pipe_close(db);
	excute_cmd(cmd_sequence, argv, db, envp);
}

void	pipe_close(t_db	*db)
{
	int	i;

	i = 0;
	while (i < (db->cmdnum - 1) * 2)
	{
		close(db->pipebox[i]);
		i++;
	}
}
