/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DFS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:22:54 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/04/01 17:49:26 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_dfs(t_dfs *dfs, t_gi *gp, int location)
{
	int	i;

	dfs->a = count_col(dfs->cp_col_line); // 콜렉터블 체크 맵에 현재 몇개의 콜랙터가 있는지 확인 (종료조건을 위해서)
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
		if (gp->str_line[location] != '1' && dfs->cp_str_line[location] != '2')// '1'(벽)과 '2'(갔던길)이 아닐때만 계속해서 이동
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

void	ft_exit_print(char *str)
{
	write(1, str, ft_strlen(str));
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

	dfs->start_point = 0; //p가 start_point
	line_len = ft_strlen(gp->str_line); // 원본 맵 길이 재기
	dfs->cp_str_line = malloc(sizeof(char) * line_len);
	if (!dfs->cp_str_line)
		exit(1);
	dfs->cp_str_line = ft_mod_strdup(gp->str_line); //원본맵 복사해오기(출구전용)
	while (dfs->cp_str_line[dfs->start_point] != 'P')
		dfs->start_point++;
	dfs->move[0] = -1; //왼쪽
	dfs->move[1] = 1;//오른쪽
	dfs->move[2] = gp->width; //위
	dfs->move[3] = -gp->width; // 아래
	dfs->found_way = 0; //출구로 나갈 수 있나? 체크 하기위한 플레그
	dfs->cp_col_line = ft_mod_strdup(gp->str_line); //원본맵 복사해오기(콜렉터블 전용)
	if (!dfs->cp_col_line)
		exit(1);
	while (dfs->cp_col_line[i]) //c를 찾으면 1로 바꿀꺼라서 모두 0으로 표시 (이렇게 위치적으로 표기하면 중복 표기 위험성이 사라짐)
	{
		dfs->cp_col_line[i] = '0';
		i++;
	}
	// if (!dfs->cp_str_line)
	// 	end_game(gp);
}
