/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:14:20 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/08/03 18:41:26 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_doac(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->p_startetingtime);
	philo->p_startetingtime = ft_current_time();
	pthread_mutex_unlock(&philo->info->p_startetingtime);
	ft_usleep(philo->info->time_to_eat, philo->name);
	pthread_mutex_lock(&philo->info->eat_count);
	philo->eat_count += 1;
	pthread_mutex_unlock(&philo->info->eat_count);
	pthread_mutex_unlock(&philo->info->fork_m[philo->right_fork]);
	pthread_mutex_unlock(&philo->info->fork_m[philo->left_fork]);
}

static int	ft_print_result(t_philo *philo, char *str)
{
	if (ft_printf(philo, str))
	{
		pthread_mutex_unlock(&philo->info->fork_m[philo->left_fork]);//스테이를 사용하면 장점이있다.(스테이터스 : 혼자있을때 이중으로 락이걸리지않음으로 탈출이 가능하다.) 스테이터스 = 플래그처럼
		pthread_mutex_unlock(&philo->info->fork_m[philo->right_fork]);
		return (1);
	}
	return (0);
}

static int	ft_pright_fork(t_philo *philo)
{
	if (ft_printf(philo, " has taken a fork\n"))
	{
		pthread_mutex_unlock(&philo->info->fork_m[philo->right_fork]);
		return (1);
	}
	return (0);
}

void	ft_eat(t_philo *philo)
{
	if (philo->info->philo_num % 2 == 0)
	{
		pthread_mutex_lock(&philo->info->fork_m[philo->right_fork]);
		if (ft_pright_fork(philo))
			return ;
		pthread_mutex_lock(&philo->info->fork_m[philo->left_fork]);
		if (ft_print_result(philo, " has taken a fork\n"))
			return ;
	}
	else
	{
		pthread_mutex_lock(&philo->info->fork_m[philo->left_fork]);
		if (ft_printf(philo, " has taken a fork1\n"))
		{
			pthread_mutex_unlock(&philo->info->fork_m[philo->left_fork]);
			return ;
		}
		pthread_mutex_lock(&philo->info->fork_m[philo->right_fork]);
		if (ft_print_result(philo, " has taken a fork\n"))
			return ;
	}
	if (ft_print_result(philo, " is eating\n"))
		return ;
	ft_doac(philo);
}
