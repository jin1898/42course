/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DFS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:22:54 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/03/30 17:59:03 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h> //지워야함!!!!!!!!!!!!!!!!!!

void	ft_dfs(t_dfs *dfs, t_gi *gp, int location)
{
	int	i;

	dfs->cp_str_line[location] = 1;
	printf("location:%d/dfs->startpoint:%d\n", location, dfs->start_point);
	i = 0;
	if (gp->str_line[dfs->start_point] == 'C')
		gp->col_cnt--;
	if (gp->str_line[dfs->start_point] == 'E')
	{
		dfs->found_way = 1;
		return ;
	}
	while (i < 4)
	{
		dfs->start_point = dfs->move[i] + location;
		if (gp->str_line[dfs->start_point] != '1')
			ft_dfs(dfs, gp, dfs->start_point);
	}
}
