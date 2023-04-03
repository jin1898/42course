/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:22:54 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/04/03 17:27:05 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int plant = 0;

void	ft_dfs(t_dfs *dfs, t_gi *gp, int location)
{
	int	i;

	dfs->a = count_col(dfs->cp_col_line);
	i = 0;
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
		//print_DFS(gp,dfs,location,i,plant);
		plant++;
		if (gp->str_line[location + dfs->move[i]] != '1' && dfs->cp_str_line[location + dfs->move[i]] != '2')
		{
			dfs->cp_str_line[location] = '2';
			ft_dfs(dfs, gp, location + dfs->move[i]);
		}
		//dfs->cp_str_line[location] = '0';
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

void	ft_exit_print(char *str)
{
	write(1, str, ft_strlen(str));//ft_putstr_fd 스텐다드 앙
	exit(1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	num;

	if (n == -2147483648)
	{
		ft_putnbr_fd(n / 10, fd);
		write(fd, "8", 1);
		return ;
	}
	else if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		num = '0' + n % 10;
	}
	else
		num = n + '0';
	write(fd, &num, 1);
}

void	init_dfs(t_dfs *dfs, t_gi *gp, int i)
{
	int	line_len;

	dfs->start_point = 0;
	line_len = ft_strlen(gp->str_line);
	dfs->cp_str_line = ft_mod_strdup(gp->str_line);
	while (dfs->cp_str_line[dfs->start_point] != 'P')
		dfs->start_point++;
	dfs->move[0] = -1;
	dfs->move[1] = 1;
	dfs->move[2] = gp->width;
	dfs->move[3] = -gp->width;
	dfs->found_way = 0;
	dfs->cp_col_line = ft_mod_strdup(gp->str_line);
	if (!dfs->cp_col_line)
		exit(1);
	while (dfs->cp_col_line[i])
	{
		dfs->cp_col_line[i] = '0';
		i++;
	}
}
