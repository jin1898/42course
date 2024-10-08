/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vector_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:21:33 by jeekpark          #+#    #+#             */
/*   Updated: 2023/09/27 13:37:25 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

t_vector	rotate_vector(t_vector vector, double degree)
{
	t_vector	res;
	double		rad;

	rad = deg_to_rad(degree);
	res.x = vector.x * cos(rad) - vector.y * sin(rad);
	res.y = vector.x * sin(rad) + vector.y * cos(rad);
	return (res);
}
