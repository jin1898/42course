/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:15:41 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/03/31 17:25:50 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(t_gi *gp)
{
	mlx_destroy_window(gp->mlx, gp->window);
	exit(0);
}

void	move_w(t_gi *gp)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(gp->str_line))
	{
		if (gp->str_line[i] == 'P')
			break ;
	}
	if (gp->str_line[i - gp->width] == 'C')
		gp->col_cnt++;
	if (gp->str_line[i - gp->width] == 'E' && gp->total_col == gp->col_cnt)
		clear_game(gp);
	else if (gp->str_line[i - gp->width] != '1' && \
	gp->str_line[i - gp->width] != 'E')
	{
		gp->str_line[i] = '0';
		gp->str_line[i - gp->width] = 'P';
		gp->step_cnt++;
		printf("%d\n", gp->step_cnt);
		setting_img(gp);
	}
}

void	move_a(t_gi *gp)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(gp->str_line))
	{
		if (gp->str_line[i] == 'P')
			break ;
	}
	if (gp->str_line[i - 1] == 'C')
		gp->col_cnt++;
	if (gp->str_line[i - 1] == 'E' && gp->total_col == gp->col_cnt)
		clear_game(gp);
	else if (gp->str_line[i - 1] != '1' && gp->str_line[i - 1] != 'E')
	{
		gp->str_line[i] = '0';
		gp->str_line[i - 1] = 'P';
		gp->step_cnt++;
		printf("%d\n", gp->step_cnt);
		setting_img(gp);
	}
}

void	move_s(t_gi *gp)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(gp->str_line))
	{
		if (gp->str_line[i] == 'P')
			break ;
	}
	if (gp->str_line[i + gp->width] == 'C')
		gp->col_cnt++;
	if (gp->str_line[i + gp->width] == 'E' && gp->total_col == gp->col_cnt)
		clear_game(gp);
	else if (gp->str_line[i + gp->width] != '1' && \
	gp->str_line[i + gp->width] != 'E')
	{
		gp->str_line[i] = '0';
		gp->str_line[i + gp->width] = 'P';
		gp->step_cnt++;
		printf("%d\n", gp->step_cnt);
		setting_img(gp);
	}
}

void	move_d(t_gi *gp)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(gp->str_line))
	{
		if (gp->str_line[i] == 'P')
			break ;
	}
	if (gp->str_line[i + 1] == 'C')
		gp->col_cnt++;
	if (gp->str_line[i + 1] == 'E' && gp->total_col == gp->col_cnt)
		clear_game(gp);
	else if (gp->str_line[i + 1] != '1' && gp->str_line[i + 1] != 'E')
	{
		gp->str_line[i] = '0';
		gp->str_line[i + 1] = 'P';
		gp->step_cnt++;
		printf("%d\n", gp->step_cnt);
		setting_img(gp);
	}
}
