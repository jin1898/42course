/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:56:35 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/08/03 17:20:17 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep_think(t_philo *philo)
{
	if (ft_printf(philo, " is sleeping\n"))
		return ;
	ft_usleep(philo->info->time_to_sleep, philo->name);
	if (ft_printf(philo, " is thinking\n"))
		return ;
}

void	*ft_action(void *v_philo)
{
	t_philo	*philo;

	philo = (t_philo *)v_philo;
	while (!philo->info->ready)
		continue ;
	if (philo->name % 2 == 0)
		usleep(100 * philo->info->philo_num);
	pthread_mutex_lock(&philo->info->death_flag_m);
	while (!philo->info->death_flag)
	{
		pthread_mutex_unlock(&philo->info->death_flag_m);
		ft_eat(philo);
		ft_sleep_think(philo);
		pthread_mutex_lock(&philo->info->death_flag_m);
	}
	pthread_mutex_unlock(&philo->info->death_flag_m);
	return (0);
}

int	take_action(t_allinfo *info)
{
	int		i;
	int		check;

	info->start_time = ft_current_time();
	i = 0;
	while (i < info->philo_num)
		info->philo[i++].p_starttime = info->start_time;
	info->ready = 1;
	i = 0;
	while (i < info->philo_num)
	{
		info->philo[i].p_thread = 0;
		info->philo[i].p_startetingtime = info->philo[i].p_starttime;
		check = pthread_create(&info->philo[i].p_thread, \
		NULL, ft_action, &info->philo[i]);
		i++;
		if (check == -1)
			return (1);
	}
	ft_monitor(info);
	return (0);
}

int	main(int ac, char **av)
{
	t_allinfo	info;

	if (check_error_num(ac, av))
		return (1);
	if (ft_atoi(av[1]) == 1)
	{
		ft_print_one_end(av);
		return (0);
	}
	if (init_everything(&info, av))
		return (1);
	else if (take_action(&info))
		return (1);
	return (0);
}
