/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:25:03 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/05/02 20:14:15 by jsunwoo          ###   ########.fr       */
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

void	p_error_2(t_db *db)
{
	write(2, "Command not found: ", ft_strlen("Command not found: "));
	write(2, db->cmd, ft_strlen(db->cmd));
	write(2, "\n", sizeof(char));
}
