/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:02:40 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/03/31 17:25:17 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_gimgi	img_init(void *mlx)
{
	t_gimgi	img;
	int		width;
	int		height;

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
	while (height < gp->height)
	{
		width = 0;
		while (width < gp->width)
		{
			put_img(gp, width, height);
			width++;
		}
		height++;
	}
}
