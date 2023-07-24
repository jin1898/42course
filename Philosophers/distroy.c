/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:15:01 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/07/24 16:39:27 by sunwoo-jin       ###   ########.fr       */
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
	pthread_mutex_destroy(info->fork_m);
	pthread_mutex_destroy(&info->print);
	pthread_mutex_destroy(&info->infofix);
	pthread_mutex_destroy(&info->death_flag_m);
	pthread_mutex_destroy(&info->check_death);
	free(info->philo);
	free(info->fork_m);
}
//뮤텍스할당했는데 실패시 앞에뮤텍스 디스트로이해야한다. 