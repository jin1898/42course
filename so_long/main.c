/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:55:44 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/03/10 17:21:22 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mlx.h>

int	main(void)
{
	void *mlx;
	void *win;
	void *img;
	void *img2;
	void *img3;
	void *img4;
	void *img5;
	// void *img6;
	// void *img7;
	int img_width;
	int img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "my_mlx");
	img = mlx_xpm_file_to_image(mlx, "./images/Actions.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, "./images/Spritesheet.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, "./images/Grass_tiles.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx, "./images/Grass_tiles2.xpm", &img_width, &img_height);
	img5 = mlx_xpm_file_to_image(mlx, "./images/Grass_tiles3.xpm", &img_width, &img_height);
	// img6 = mlx_xpm_file_to_image(mlx, "./images/rune.xpm", &img_width, &img_height);
	// img7 = mlx_xpm_file_to_image(mlx, "./images/rune_light.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_put_image_to_window(mlx, win, img2, 64, 0);
	mlx_put_image_to_window(mlx, win, img3, 128, 0);
	mlx_put_image_to_window(mlx, win, img4, 192, 64);
	mlx_put_image_to_window(mlx, win, img5, 0, 64);
	// mlx_put_image_to_window(mlx, win, img6, 64, 64);
	// mlx_put_image_to_window(mlx, win, img7, 128, 64);
	mlx_loop(mlx);
	return (0);
}