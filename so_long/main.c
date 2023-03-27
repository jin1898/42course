/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:55:44 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/03/20 16:34:33 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_gimgi	img_init(void *mlx)
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
		end_game(gp);
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

int	main(int ac, char *av[])
{
	t_gi	*gp; //game pointer

	if (ac != 2)
	{
		write(1, "Where is map?\n", 14);
		exit(1);
	}
	gp = malloc(sizeof(gp));
	gp->mlx = mlx_init();
	gp->img = img_init(gp->mlx);
	read_map(av[1], gp);
	check_map(gp);
	gp->window = mlx_new_window(gp->mlx, gp->width * 64, \
	gp->height * 64, "so_long");
	setting_img(gp);
	mlx_hook(gp->window, KEY_PRESS, 0, &press_key, gp);
	mlx_hook(gp->window, KEY_EXIT, 0, &end_game, gp);
	mlx_loop(gp->mlx);
	return (0);
}
