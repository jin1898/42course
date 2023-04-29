/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:41:03 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/04/29 10:08:18 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
			free_main_arg_and_path(db);
			error_message("pipe");
		}
			printf("db->pipebox1[%d] pipebox2[%d]\n",db->pipebox[0],db->pipebox[1]);
		i++;
	}
}

void	free_main_arg_and_path(t_db *db)
{
	int	i;

	close(db->infilenum);
	close(db->outfilenum);
	if (db->h_flag == 1)
		unlink(".heredoc_tmp");
	free(db->pipebox);
	i = 0;
	while (db->path[i] != NULL)
	{
		free(db->path[i]);
		i++;
	}
	free(db->path);
}
