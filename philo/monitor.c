/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:20:02 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/08/01 15:06:51 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	did_everyone_eat(t_allinfo *info)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < info->philo_num)
	{
		pthread_mutex_lock(&info->eat_count);
		if (info->philo[i].eat_count >= info->must_eat)
		{
			count++;
		}
		pthread_mutex_unlock(&info->eat_count);
		i++;
	}
	if (count == info->philo_num)
		return (1);
	return (0);
}

static void	everyone_has_finished_eating(t_allinfo *info)
{
	pthread_mutex_lock(&info->print);
	pthread_mutex_lock(&info->death_flag_m);
	info->death_flag = 1;
	printf("모두 밥을 다먹었습니당\n");
	pthread_mutex_unlock(&info->death_flag_m);
	pthread_mutex_unlock(&info->print);
}

void	ft_monitor(t_allinfo *info)
{
	int	i;

	while (!info->death_flag)
	{
		if (info->must_eat > 0)
		{
			if (did_everyone_eat(info))
			{
				everyone_has_finished_eating(info);
				break ;
			}
		}
		i = 0;
		while (i < info->philo_num)
		{
			if (check_death(&info->philo[i]))
				break ;
			i++;
		}
		if (i != info->philo_num)
			break ;
	}
	ft_distryeverything(info);
}

int	lower_bound(int time, int num)
{
	if (num % 2 == 1)
	{
		if (time < 600)
			time = 600;
	}
	else
	{
		if (time < 70)
			time = 70;
	}
	return (time);
}

int	ft_usleep(int goal_time, int num)
{
	int				must_spend_time;
	int				start_time;
	int				end_time;
	struct timeval	start;
	struct timeval	end;

	goal_time *= 1000;
	gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	start_time = start.tv_sec * 1000000 + start.tv_usec;
	end_time = end.tv_sec * 1000000 + end.tv_usec;
	while (goal_time >= end_time - start_time)
	{
		end_time = end.tv_sec * 1000000 + end.tv_usec;
		must_spend_time = (goal_time - (end_time - start_time)) * 3 / 4;
		must_spend_time = lower_bound(must_spend_time, num);
		usleep(must_spend_time);
		gettimeofday(&end, NULL);
	}
	return (0);
}
