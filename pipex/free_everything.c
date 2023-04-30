/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:25:03 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/04/30 16:18:56 by jsunwoo          ###   ########.fr       */
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
	system("leaks -q pipex");
	for(int c = 0; db->path[c] != NULL; c++)
		printf("top!!!!!!!db->path[%d]주소값:[%p] %s\n",c,&db->path[c], db->path[c]);

	while (db->path[i] != NULL)
	{
		printf("&&db->path[%d]주소값:[%p]\n",i,&db->path[i]);
		free(db->path[i]);
		printf("db->path[%d]주소값:[%p]\n",i,db->path[i]);
		i++;
	}
	printf("1");
	printf("1 %p\n",db->path);
	// free(db->path);aaa
	printf("2\n");
}
