/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:25:03 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/05/01 23:07:30 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_everything(t_db *db)
{
	int	i;

	close(db->infilenum);
	close(db->outfilenum);
	if (db->h_flag == 1)
		unlink(".heredoc_tmp");
	free(db->pipebox);
	i = 0;
	if (!db->path)
		return ;
	while (db->path[i] != NULL)
	{
		free(db->path[i]);
		i++;
	}
	free(db->path);
}

void	excute_cmd2(int idx, char **argv, t_db *db)
{
	char	**cmd_s;
	char	*cmd;
	int		i;

	i = 0;
	cmd_s = ft_split(argv[2 + db->h_flag + idx], ' ');
	cmd = find_cmd(db->path, cmd_s[0], db);
	// if (cmd == NULL)
	// {
	// 	write(2, "Command not found: ", ft_strlen("Command not found: "));
	// 	write(2, cmd_s[0], ft_strlen(cmd_s[0]));
	// 	write(2, "\n", sizeof(char));
	// 	exit (1); //1111111111111111111
	// }
	while (cmd_s[i])
	{
		free(cmd_s[i]);
		i++;
	}
	free(cmd_s);
	free(cmd);
}

void	check_cmd(char **argv, int argc, t_db *db)
{
	int	i;

	db->cmdnum = argc -3 - db->h_flag;
	i = 0;
	if (db->h_flag == 1)
	{
		while (i < db->cmdnum)
		{
			excute_cmd2(i, argv, db);
			i++;
		}
	}
	i = 0;
	while (db->path[i] != NULL)
	{
		free(db->path[i]);
		i++;
	}
	free(db->path);
	db->path = 0;
}

void	p_error_2(t_db *db)
{
	write(2, "Command not found: ", ft_strlen("Command not found: "));
	write(2, db->cmd, ft_strlen(db->cmd));
	write(2, "\n", sizeof(char));
}
