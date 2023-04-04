/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:55:44 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/04/04 16:15:26 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_gimgi	img_init2(void *mlx)
{
	t_gimgi	imgbox;
	int		width;
	int		height;

	imgbox.floor = mlx_xpm_file_to_image(mlx, "./images/tile00.xpm", \
	&width, &height);
	imgbox.wall = mlx_xpm_file_to_image(mlx, "./images/stome.xpm", \
	&width, &height);
	imgbox.character = mlx_xpm_file_to_image(mlx, "./images/player_S00.xpm", \
	&width, &height);
	imgbox.treasure = mlx_xpm_file_to_image(mlx, "./images/ball.xpm", \
	&width, &height);
	imgbox.exit = mlx_xpm_file_to_image(mlx, "./images/ladder.xpm", \
	&width, &height);
	return (imgbox);
}

int	press_key(int key_number, t_gi *gp)
{
	if (key_number == KEY_ESC)
		end_game();
	if (key_number == KEY_W)
		move_w(gp);
	if (key_number == KEY_A)
		move_a(gp);
	if (key_number == KEY_S)
		move_s(gp);
	if (key_number == KEY_D)
		move_d(gp);
	return (0);
}

void	check_map_way(t_gi *gp)
{
	t_dfs	*dfs;

	dfs = malloc(sizeof(t_dfs));
	if (!dfs)
		end_game();
	init_dfs(dfs, gp, 0);
	ft_dfs(dfs, gp, dfs->start_point);
	free(dfs->cp_str_line);
	free(dfs->cp_col_line);
	if (!(dfs->a == gp->total_col && dfs->found_way == 1))
		ft_exit_print("ERROR\nThere's no way out!\n");
	free(dfs);
}

int	main(int ac, char *av[])
{
	t_gi	*gp;

	if (ac != 2)
		ft_exit_print("ERROR\nWhere is map?\n");
	gp = malloc(sizeof(t_gi));
	if (!gp)
		exit(1);
	read_map(av[1], gp);
	check_map(gp);
	check_map_way(gp);
	gp->mlx = mlx_init();
	gp->img = img_init(gp->mlx);
	gp->window = mlx_new_window(gp->mlx, gp->width * 64, \
	gp->height * 64, "so_long");
	setting_img(gp);
	mlx_hook(gp->window, KEY_PRESS, 0, &press_key, gp);
	mlx_hook(gp->window, KEY_EXIT, 0, &end_game, gp);
	mlx_loop(gp->mlx);
	return (0);
}
