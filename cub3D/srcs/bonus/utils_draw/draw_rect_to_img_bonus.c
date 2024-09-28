/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect_to_img_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:06:04 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/27 13:37:25 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

void	draw_rect_to_img(t_component *component,
	t_pixel first, t_pixel second, int color)
{
	int	x;
	int	y;

	x = first.x;
	while (x < second.x)
	{
		y = first.y;
		while (y < second.y)
		{
			draw_pixel_to_img(component, set_pixel(x, y), color);
			y++;
		}
		x++;
	}
}
