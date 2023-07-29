/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:28:34 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/07/29 19:28:37 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_one_end(char **av)
{
	int	time_2_die;

	time_2_die = ft_atoi(av[2]);
	printf("%d %d has taken a fork\n", 0, 1);
	usleep(time_2_die * 1000);
	printf("%d %d died\n", (time_2_die + 1), 1);
}