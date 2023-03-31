/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DFS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:22:54 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/03/31 13:45:50 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h> //지워야함!!!!!!!!!!!!!!!!!!

// void	ft_dfs(t_dfs *dfs, t_gi *gp, int location)
// {
// 	int	i;

// 	i = -1;
// 	//dfs->cp_str_line[location] = '2';
// 	printf("location:%d/dfs->startpoint:%d  i : %d  -     ", location, dfs->start_point,i);
// 	printf("gp->str_line[location] : %c\n" ,gp->str_line[location]);
// 	if (dfs->found_way == 1 && gp->total_col == 0)
// 		return ;
// 	if (gp->str_line[location] == 'C')
// 		gp->total_col--;
// 	if (gp->str_line[location] == 'E')
// 	{
// 		dfs->found_way = 1;
// 		return ;
// 	}
// 	while (i < 4 && (!(dfs->found_way == 1 && gp->total_col == 0)) && gp->str_line[location] != 'E')
// 	{
// 		i++;
// 		dfs->start_point += dfs->move[i];
// 		if (gp->str_line[dfs->start_point] != '1' && dfs->cp_str_line[dfs->start_point] != '2')
// 			ft_dfs(dfs, gp, dfs->start_point);
// 		if (gp->str_line[dfs->start_point] == 'E')
// 			dfs->start_point -= dfs->move[i];
// 		if ((dfs->found_way != 1 && gp->total_col != 0) || gp->total_col != 0)
// 			dfs->cp_str_line[location] = '0';


// 	}
// }

void	ft_dfs(t_dfs *dfs, t_gi *gp, int location)
{
	int	i;

	dfs->a = count_col(dfs->cp_col_line);
	i = 0;
	//dfs->cp_str_line[location] = '2';
	printf("location:%d/dfs->startpoint:%d  i : %d a : %d -     ", location, dfs->start_point,i,dfs->a);
	printf("gp->str_line[location] : %c\n" ,gp->str_line[location]);

	if (dfs->found_way == 1 && gp->total_col == dfs->a)
		return ;
	if (gp->str_line[location] == 'E')
	{
		dfs->found_way = 1;
		return ;
	}
	if (gp->str_line[location] == 'C')
	{
		dfs->cp_col_line[location] = '1';
	}
	while (i < 4)
	{
		if (gp->str_line[location] != '1' && dfs->cp_str_line[location] != '2')
		{
			dfs->cp_str_line[location] = '2';
			ft_dfs(dfs, gp, location + dfs->move[i]);
			dfs->cp_str_line[location] = '0';
		}
		i++;
	}
}


int	count_col(char *str)
{
	int	i;
	int	col;

	i = 0;
	col = 0;
	while (str[i])
	{
		if (str[i] == '1')
			col++;
		i++;
	}
	return (col);
}

void    *ft_calloc(size_t count, size_t size)
{
        size_t  total;
        char    *malloc_name;
        size_t  count1;

        count1 = 0;
        total = count * size;
        if (count != 0 && size != 0)
        {
                if (total / count != size)
                        return (0);
        }
        malloc_name = malloc(total);
        if (malloc_name == NULL)
                return (NULL);
        while (count1 < total)
        {
                malloc_name[count1] = 0;
                count1++;
        }
        return (malloc_name);
}