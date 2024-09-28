/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:06:21 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/27 13:52:27 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (init_cub3d(&game, argc, argv) == FAILURE)
	{
		printf("Error\nInit failed\n");
		exit_game(&game);
		return (EXIT_FAILURE);
	}
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
