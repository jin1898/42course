/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:02:40 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/04/01 16:43:11 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_gimgi	img_init(void *mlx)
{
	t_gimgi	img;
	int		width;
	int		height;
//이미지를 읽기 위해서는 XMP 또는 PNG 형식이 필요합니다. 파일에서 이미지 객체로 읽기 위해서는 mlx_xpm_file_to_image 및 mlx_png_file_to_image 함수를 호출해야 합니다. 그러나 mlx_png_file_to_image 함수는 현재 메모리 누수(memory leak)가 발생할 수 있습니다. 두 함수는 완전히 동일한 매개변수를 받으며 사용법이 동일합니다.
	img.floor = mlx_xpm_file_to_image(mlx, "./images/tile00.xpm", \
	&width, &height);
	img.wall = mlx_xpm_file_to_image(mlx, "./images/stone.xpm", \
	&width, &height);
	img.character = mlx_xpm_file_to_image(mlx, "./images/player_S00.xpm", \
	&width, &height);
	img.treasure = mlx_xpm_file_to_image(mlx, "./images/ball.xpm", \
	&width, &height);
	img.exit = mlx_xpm_file_to_image(mlx, "./images/ladder.xpm", \
	&width, &height);
	return (img);
}

void	put_img(t_gi *gp, int w, int h)
{
	if (gp->str_line[h * gp->width + w] == '0')
		mlx_put_image_to_window(gp->mlx, gp->window, \
		gp->img.floor, w * 64, h * 64);
	else if (gp->str_line[h * gp->width + w] == '1')
		mlx_put_image_to_window(gp->mlx, gp->window, gp->img.wall, \
		w * 64, h * 64);
	else if (gp->str_line[h * gp->width + w] == 'E')
		mlx_put_image_to_window(gp->mlx, gp->window, gp->img.exit, \
		w * 64, h * 64);
	else if (gp->str_line[h * gp->width + w] == 'C')
		mlx_put_image_to_window(gp->mlx, gp->window, gp->img.treasure, \
		w * 64, h * 64);
	else if (gp->str_line[h * gp->width + w] == 'P')
		mlx_put_image_to_window(gp->mlx, gp->window, gp->img.character, \
		w * 64, h * 64);
}

void	setting_img(t_gi *gp)
{
	int		height;
	int		width;

	height = 0;
	while (height < gp->height) //네모를 그리면 1번째줄 제일 왼쪽 모서리 부터 그림!
	{
		width = 0;
		while (width < gp->width) //왼쪽부터 그림그림!
		{
			put_img(gp, width, height);
			width++;
		}
		height++;
	}
}
