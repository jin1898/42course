/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DFS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:22:54 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/03/31 11:11:45 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h> //지워야함!!!!!!!!!!!!!!!!!!

void	ft_dfs(t_dfs *dfs, t_gi *gp, int location)
{
	int	i;

	i = -1;
	dfs->cp_str_line[location] = '2';
	printf("location:%d/dfs->startpoint:%d  i : %d  -     ", location, dfs->start_point,i);
	printf("gp->str_line[location] : %c\n" ,gp->str_line[location]);
	if (gp->str_line[location] == 'C')
		gp->total_col--;
	if (gp->str_line[location] == 'E')
	{
		dfs->found_way = 1;
		return ;
	}
	while (i < 4 && (!(dfs->found_way == 1 && gp->total_col == 0)) && gp->str_line[location] != 'E')
	{
		i++;
		dfs->start_point += dfs->move[i];

		if (gp->str_line[dfs->start_point] != '1' && dfs->cp_str_line[dfs->start_point] != '2')
			ft_dfs(dfs, gp, dfs->start_point);
		if (gp->str_line[dfs->start_point] == 'E')
			dfs->start_point -= dfs->move[i];
		if ((dfs->found_way != 1 && gp->total_col != 0) || gp->total_col != 0)
			dfs->cp_str_line[location] = '0';
		if (dfs->found_way == 1 && gp->total_col == 0)
			return ;
	}

	if (dfs->found_way == 1 && gp->total_col == 0)
		return ;
}
