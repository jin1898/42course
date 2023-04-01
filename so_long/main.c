/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:55:44 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/04/01 19:33:52 by jsunwoo          ###   ########.fr       */
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

void	check_map_way(t_gi *gp)
{
	t_dfs	*dfs;

	dfs = malloc(sizeof(t_dfs));
	if (!dfs)
		end_game(gp);
	init_dfs(dfs, gp, 0);
	ft_dfs(dfs, gp, dfs->start_point);
	if (!(dfs->a == gp->total_col && dfs->found_way == 1))
		ft_exit_print("ERROR\n There's no way out!\n");
}

int	main(int ac, char *av[])
{
	t_gi	*gp;

	if (ac != 2)
		ft_exit_print("ERROR \n Where is map?\n");
	gp = malloc(sizeof(t_gi));
	gp->mlx = mlx_init(); // mlx_init 함수를 호출하여 그래픽 시스템과의 연결을 설정해야 합니다. mlx_init 함수는 void * 형식의 포인터를 반환하며, 이는 현재 MLX 인스턴스의 위치를 저장합니다. 
	gp->img = img_init(gp->mlx);
	read_map(av[1], gp); // 나는 1자로 맵을 읽어올것이다.
	check_map(gp); // 맵이 예쁘게 들어왔는지!, 벽이 모두있는지!, 들어가야할 인자값들도 다들어갔는지 확인
	check_map_way(gp); //DFS
	gp->window = mlx_new_window(gp->mlx, \
	gp->width * 64, gp->height * 64, "so_long"); // 이제 출력창 크기설정 및 윈도우 띄우기
	setting_img(gp); // 그래프에 순차적인 위치별로 그림을 넣어줌.
	mlx_hook(gp->window, KEY_PRESS, 0, &press_key, gp); //이벤트를 설정하는 함수,버튼을 누를때  press_key함수의 이벤트가 나오도록 설정함 (MiniLibX의 모든 훅은 이벤트가 트리거될 때마다 호출되는 함수입니다.)
	mlx_hook(gp->window, KEY_EXIT, 0, &end_game, gp);//이벤트를 설정하는 함수,버튼을 누를때  press_key함수의 이벤트가 나오도록 설정함 (MiniLibX의 모든 훅은 이벤트가 트리거될 때마다 호출되는 함수입니다.)
	mlx_loop(gp->mlx);
	return (0);
}
