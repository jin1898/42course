/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:15:01 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/08/03 18:35:26 by jsunwoo          ###   ########.fr       */
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
		pthread_mutex_destroy(&info->fork_m[i]);
		i++;
	}
	free(info->fork);
	pthread_mutex_destroy(info->fork_m);
	pthread_mutex_destroy(&info->print);
	pthread_mutex_destroy(&info->death_flag_m);
	free(info->philo);
	free(info->fork_m);
}
