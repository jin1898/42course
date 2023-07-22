/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:15:01 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/07/21 14:20:37 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_distryeverything(t_allinfo *info)
{
	int	i;

	i = 0;
	while (i < info->philo_num)
	{
		pthread_join(info->philo[i].p_thread, NULL);
		i++;
	}
	i = 0;
	while (i < info->philo_num)
	{
		pthread_mutex_destroy(&info->philo[i].lf);
		i++;
	}
	pthread_mutex_destroy(info->fork);
	pthread_mutex_destroy(&info->print);
	pthread_mutex_destroy(&info->infofix);
	free(info->philo);
	free(info->fork);
}
