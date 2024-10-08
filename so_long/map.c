/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:33:36 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/04/04 16:34:34 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"
#include <stdio.h>

void	read_map(char *map, t_gi *gp)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd <= 0)
		ft_exit_print("ERROR\nFailed to read file.\n");
	line = get_next_line(fd);
	if (!line)
		ft_exit_print("ERROR\nThe file is empty.");
	gp->width = ft_strlen(line) - 1;
	gp->height = 0;
	gp->step_cnt = 0;
	gp->str_line = ft_mod_strdup(line);
	free(line);
	while (line)
	{
		gp->height++;
		line = get_next_line(fd);
		if (line)
			gp->str_line = ft_mode_strjoin(gp->str_line, line);
	}
	close(fd);
}

void	check_map(t_gi *gp)
{
	if (gp->height * gp->width != ft_strlen(gp->str_line))
		ft_exit_print("ERROR\nThe map is not shaped correctly.\n");
	map_check_wall(gp);
	gp->total_col = 0;
	gp->col_cnt = 0;
	map_check_params(gp, -1);
}

void	map_check_wall(t_gi *gp)
{
	int		i;

	i = 0;
	while (i < ft_strlen(gp->str_line))
	{
		if (i < gp->width)
		{
			if (gp->str_line[i] != '1')
				ft_exit_print("ERROR\nThe map is not walled.(top)\n");
		}
		else if (i % gp->width == 0 || i % gp->width == gp->width - 1)
		{
			if (gp->str_line[i] != '1')
				ft_exit_print("ERROR\nMap is not walled (side)\n");
		}
		else if (i > ft_strlen(gp->str_line) - gp->width)
		{
			if (gp->str_line[i] != '1')
				ft_exit_print("ERROR\nMap is not walled (bottom)\n");
		}
		i++;
	}
}

void	map_check_params(t_gi *gp, int i)
{
	int	exit_count;
	int	startpoint_count;

	exit_count = 0;
	startpoint_count = 0;
	while (i++ < (ft_strlen(gp->str_line) - 1))
	{
		if (gp->str_line[i] == 'E')
			exit_count++;
		else if (gp->str_line[i] == 'P')
			startpoint_count++;
		else if (gp->str_line[i] == 'C')
			gp->total_col++;
		else if (gp->str_line[i] != 'E' && gp->str_line[i] != 'P'\
		&& gp->str_line[i] != 'C' && gp->str_line[i] != '0' \
		&& gp->str_line[i] != '1')
			ft_exit_print("ERORR\nThere's an unknown character in it!");
	}
	if (exit_count != 1)
		ft_exit_print("ERROR\nOnly one exit must exist!\n");
	if (gp->total_col == 0)
		ft_exit_print("ERROR\nNo collectible found.\n");
	if (startpoint_count != 1)
		ft_exit_print("ERROR\nYou must have one starting point.\n");
}

int	clear_game(t_gi *gp)
{
	gp->step_cnt++;
	write(1, "Congratulations! You have [", 27);
	ft_putnbr_fd(gp->step_cnt, 1);
	write(1, "] steps!\n", 10);
	exit(0);
}
