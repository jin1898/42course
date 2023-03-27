/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:02:40 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/03/20 17:54:21 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_gimgi	img_init(void *mlx)
{
	t_gimgi	img;
	int		width;
	int		height;

	img.floor = mlx_xpm_file_to_image(mlx, "./images/land.xpm", \
	&width, &height);
	img.wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &width, &height);
	img.character = mlx_xpm_file_to_image(mlx, "./images/chara.xpm", \
	&width, &height);
	img.treasure = mlx_xpm_file_to_image(mlx, "./images/chest.xpm", \
	&width, &height);
	img.exit = mlx_xpm_file_to_image(mlx, "./images/rune.xpm", &width, &height);
	return (img);
}

void	put_img(t_gi *gp, int w, int h)
{
	if (gp->str_line[h * gp->width + w] == '1')
		mlx_put_image_to_window(gp->mlx, gp->window, gp->img.wall, \
		w * 64, h * 64);
	else if (gp->str_line[h * gp->width + w] == 'C')
		mlx_put_image_to_window(gp->mlx, gp->window, gp->img.treasure, \
		w * 64, h * 64);
	else if (gp->str_line[h * gp->width + w] == 'P')
		mlx_put_image_to_window(gp->mlx, gp->window, gp->img.character, \
		w * 64, h * 64);

	else if (gp->str_line[h * gp->width + w] == 'E')
		mlx_put_image_to_window(gp->mlx, gp->window, gp->img.exit, \
		w * 64, h * 64);
	else
		mlx_put_image_to_window(gp->mlx, gp->window, \
		gp->img.floor, w * 64, h * 64);
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
