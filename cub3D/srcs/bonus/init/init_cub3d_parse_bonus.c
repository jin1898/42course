/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d_parse_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:01:19 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/27 13:37:25 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

static int	_omission_check(t_check_parse *var)
{
	if (var->ceiling == 0 || var->east == 0 || var->north == 0
		|| var->floor == 0 || var->map == 0 || var->south == 0
		|| var->west == 0)
		return (FAILURE);
	return (SUCCESS);
}

int	init_cub3d_parse(t_game *game)
{
	char	*temp;

	game->fd = open(game->argv[1], O_RDONLY);
	if (game->fd == -1)
		return (FAILURE);
	while (1)
	{
		game->str = get_next_line(game->fd);
		if (game->str == NULL)
			break ;
		temp = game->str;
		game->str = ft_strtrim(temp, "\n");
		free(temp);
		if (game->str == NULL)
			break ;
		if (line_validation(game) == FAILURE)
		{
			close(game->fd);
			free(game->str);
			return (FAILURE);
		}
		free(game->str);
	}
	close(game->fd);
	return (_omission_check(&(game->check_parse)));
}
