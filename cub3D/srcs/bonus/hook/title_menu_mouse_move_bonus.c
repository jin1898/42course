/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title_menu_mouse_move_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:31:15 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/27 13:37:25 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

int	title_menu_mouse_move(int x, int y, t_game *game)
{
	game->mouse_cursor.x = x;
	game->mouse_cursor.y = y;
	return (SUCCESS);
}
