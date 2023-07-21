/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseong <hyseong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:13:10 by hyseong           #+#    #+#             */
/*   Updated: 2023/07/21 17:13:30 by hyseong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status = 0;

static void	ctrl_d(t_env_manager *env_manager, char *line)
{
	if (!line && ft_printf(1, "\x1b[1A\x1b[33;1m\x1b[22m\033[12Cexit\n\033[0m"))
		free_for_exit(env_manager, 0);
}

void	free_eveything(char **line, t_cmd_info **cmd_arr)
{
	t_cmd_info	*cmd_c;
	int			i;
	t_redir		*r_tmp;
	t_cmd_info	*c_tmp;

	cmd_c = *cmd_arr;
	if (line)
		free(*line);
	while (cmd_c)
	{
		i = -1;
		while (cmd_c->argv && cmd_c->argv[++i])
			free(cmd_c->argv[i]);
		free(cmd_c->argv);
		while (cmd_c->redir)
		{
			r_tmp = cmd_c->redir;
			cmd_c->redir = cmd_c->redir->next;
			free(r_tmp->str);
			free(r_tmp);
		}
		c_tmp = cmd_c->next;
		free(cmd_c);
		cmd_c = c_tmp;
	}
}

static	void	close_fd(t_cmd_info *cmd_arr)
{
	while (cmd_arr)
	{
		if (cmd_arr->in_fd)
			close(cmd_arr->in_fd);
		if (cmd_arr->out_fd)
			close(cmd_arr->out_fd);
		cmd_arr = cmd_arr->next;
	}
}

static int	init_main(int argc, char **argv, t_env_manager *env_manager)
{
	(void)argv;
	(void)argc;
	ft_memset(env_manager, 0, sizeof(t_env_manager));
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char			*line;
	t_cmd_info		*cmd_arr;
	t_env_manager	env_manager;

	// atexit(f);
	init_main(argc, argv, &env_manager);
	if (env_arr_to_list(&env_manager, envp))
		return (1);
	while (1)
	{
		set_signal();
		heredoc_unlink();
		line = readline("minishell > ");
		ctrl_d(&env_manager, line);
		cmd_arr = parsing_allparts(line, &env_manager);
		if (cmd_arr)
			parsing_command(cmd_arr, expand_env("PATH", 0, &env_manager));
		if (cmd_arr)
			ft_execution(cmd_arr, &env_manager);
		if (*line != 0)
			add_history(line);
		close_fd(cmd_arr);
		free_eveything(&line, &cmd_arr);
		// system("leaks --list -- minishell");
	}
	return (!free_env(&env_manager));
}
