/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:25:03 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/04/30 19:35:48 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_everything(t_db *db)
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
	system("leaks -q pipex");
}
