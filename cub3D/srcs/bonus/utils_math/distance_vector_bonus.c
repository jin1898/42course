/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_vector_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:04:27 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/09/27 13:37:25 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

double	distance_vector(t_vector v1, t_vector v2)
{
	t_vector	pythagoras;
	double		distance_sq;

	pythagoras = substract_vector(v1, v2);
	distance_sq = pow(pythagoras.x, 2) + pow(pythagoras.y, 2);
	return (sqrt(distance_sq));
}
