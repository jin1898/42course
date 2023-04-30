/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:25:03 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/04/30 11:54:55 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_everything(t_db *db)
{
	int	i;
	printf("here1\n");
	close(db->infilenum);
	close(db->outfilenum);
	if (db->h_flag == 1)
		unlink(".heredoc_tmp");
	printf("here2\n");
	free(db->pipebox);
	i = 0;
	printf("here3\n");
	printf("3 %p\n",db->path);
	while (db->path[i] != NULL)
	{
		printf("%d\n",i);
		free(db->path[i]);
		i++;
	}
	printf("1");
	printf("1 %p\n",db->path);
	// free(db->path);aaa
	printf("\n2");
}
