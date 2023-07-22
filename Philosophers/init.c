/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:23:18 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/07/22 21:40:51 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_error_num(int ac, char **av)
{
	int			i;
	long long	a;

	if (ac < 5 || ac > 6)
		return (1);
	i = 0;
	while (av[++i])
	{
		a = ft_atoi(av[i]);
		if (a <= 0 || a > 2147483647)
			return (1);
	}
	return (0);
}

int	init_each_philo(t_allinfo *info)
{
	int	i;

	info->philo = malloc(sizeof(t_philo) * info->philo_num);
	if (!info->philo)
		return (1);
	i = -1;
	// info->philo[0].right_fork = info->philo_num;
	// info->philo[0].left_fork = 1;
	info->ready = 0;
	info->eating_flag = 0;
	while (++i < info->philo_num)
	{
		if (i != info->philo_num - 1)
		{
			info->philo[i].name = (i + 1);
			info->philo[i].right_fork = i;
			info->philo[i].left_fork = (i + 1);
		}
		else
		{
			info->philo[i].name = (i + 1);
			info->philo[i].right_fork = i;
			info->philo[i].left_fork = 0;
		}
		info->philo[i].eat_count = 0;
		info->philo[i].p_startetingtime = 0;
		info->philo[i].info = info;
	}
	return (0);
}

int	init_everything(t_allinfo *info, char**av)
{
	int	i;

	info->philo_num = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		info->must_eat = ft_atoi(av[5]);
	else
		info->must_eat = -1;
	info->fork_m = malloc(sizeof(pthread_mutex_t) * info->philo_num);
	info->fork = malloc(sizeof(int) * info->philo_num);
	if (!info->fork)
		return (1);
	info->death_flag = 0;
	i = -1;
	while (++i < info->philo_num)
		if (pthread_mutex_init(&info->fork_m[i], NULL) != 0)
			return (1);
	if (pthread_mutex_init(&info->print, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&info->infofix, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&info->death_flag_m, NULL) != 0)
		return (1);
	if (init_each_philo(info))
		return (1);
	return (0);
}

int	check_death(t_philo *philo)
{
	long int	howlongtime;
	long long	now_time;

	howlongtime = ft_current_time() - philo->p_startetingtime;
	pthread_mutex_lock(&philo->info->death_flag_m);
	if (howlongtime > philo->info->time_to_die)
	{
		philo->info->death_flag = 1;
		pthread_mutex_lock(&philo->info->print);
		now_time = ft_current_time();
		printf("%lld %d %s", (now_time - philo->p_starttime), philo->name, " died\n");
		pthread_mutex_unlock(&philo->info->print);
		pthread_mutex_unlock(&philo->info->death_flag_m);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->death_flag_m);
	return (0);
}
