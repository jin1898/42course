/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:56:35 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/07/10 20:11:30 by jsunwoo          ###   ########.fr       */
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
	info->philo[0].right_fork = info->philo_num;
	info->philo[0].left_fork = 1;
	while (++i < info->philo_num)
	{
		info->philo[i].name = (i + 1);
		if (i != 0)
		{
			info->philo[i].right_fork = i;
			info->philo[i].left_fork = (i + 1);
		}
		info->philo[i].eat_count = 0;
		info->philo[i]. death_time = 0;
		info->philo[i]. info = info;
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
	info->fork = malloc(sizeof(pthread_mutex_t) * info->philo_num);
	if (!info->fork)
		return (1);
	info->death_flag = 0;
	i = -1;
	while (++i < info->philo_num)
		if (pthread_mutex_init(info->fork, NULL) != 0)
			return (1);
	if (pthread_mutex_init(&info->print, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&info->infofix, NULL) != 0)
		return (1);
	if (init_each_philo(info))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_allinfo	info;

	if (check_error_num(ac, av)) // 인자갯수, 음수, int오버플로우 일경우 에러로인지
		return (1);
	if (init_everything(&info, av)) // 필요 구조체들 모두 초기화하기
		return (1);
	
	printf("please check the result\n");
	return (0);
}
