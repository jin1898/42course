/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:08:03 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/04/03 00:28:56 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include "./mlx/mlx.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>

# define KEY_PRESS		2
# define KEY_RELEASE	3
# define KEY_EXIT		17

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_ESC		53

typedef struct s_game_image_information
{
	void	*character;
	void	*treasure;
	void	*floor;
	void	*exit;
	void	*wall;
}t_gimgi;

typedef struct s_game_information
{
	void	*mlx;
	void	*window;
	t_gimgi	img;
	int		width;
	int		height;
	char	*str_line;
	int		total_col;
	int		col_cnt;
	int		step_cnt;
}t_gi;

typedef struct s_dfs
{
	char	*cp_str_line;
	char	*cp_col_line;
	int		start_point;
	int		move[4];
	int		found_way;
	int		a;
}t_dfs;

int		end_game(void);
void	read_map(char *map, t_gi *gp);
char	*ft_mod_strdup(char *s);
char	*ft_mode_strjoin(char *s1, char *s2);
void	check_map(t_gi *gp);
t_gimgi	img_init(void *mlx);
t_gimgi	img_init3(void *mlx);
void	put_img(t_gi *gp, int w, int h);
void	setting_img(t_gi *game);
void	map_check_params(t_gi *gp);
void	map_check_wall(t_gi *gp);
int		clear_game(t_gi *gp);

void	move_w(t_gi *gp);
void	move_a(t_gi *gp);
void	move_s(t_gi *gp);
void	move_d(t_gi *gp);

int		ft_strlen(char *s);
int		ft_strlcpy(char *dst, char *src, int len);
int		count_col(char *str);

void	ft_dfs(t_dfs *dfs, t_gi *gp, int step);
void	ft_exit_print(char *str);
void	init_dfs(t_dfs *dfs, t_gi *gp, int i);
void	ft_putnbr_fd(int n, int fd);
void 	print_DFS(t_gi *gp, t_dfs *dfs, int location,int i,int plant);
#endif
