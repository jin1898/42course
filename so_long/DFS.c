/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DFS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:22:54 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/03/31 09:18:45 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h> //지워야함!!!!!!!!!!!!!!!!!!

void	ft_dfs(t_dfs *dfs, t_gi *gp, int location)
{
	int	i;

	dfs->cp_str_line[location] = '2';
	printf("location:%d/dfs->startpoint:%d\n", location, dfs->start_point);
	i = 0;
	if (gp->str_line[location] == 'C')
		gp->total_col--;
	if (gp->str_line[location] == 'E')
	{
		dfs->found_way = 1;
		return ;
	}
	while (i < 4 && (!(dfs->found_way == 1 && gp->total_col == 0)) && dfs->found_way != 1)
	{
		i++;
		dfs->start_point += dfs->move[i];
		if (gp->str_line[dfs->start_point] != '1')
			ft_dfs(dfs, gp, dfs->start_point);
	}
	if ((dfs->found_way != 1 && gp->total_col != 0) || gp->total_col != 0)
	{
		dfs->cp_str_line[location] = '0';
		dfs->found_way = 0;
		dfs->start_point -= dfs->move[i];
	}
	if (dfs->found_way == 1 && gp->total_col == 0)
		return ;
}
