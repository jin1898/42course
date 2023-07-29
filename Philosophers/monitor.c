/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:20:02 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/07/29 20:27:13 by sunwoo-jin       ###   ########.fr       */
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
		pthread_mutex_lock(&info->infofix);
		pthread_mutex_lock(&info->eat_count);
		if (info->philo[i].eat_count >= info->must_eat)
		{
			// pthread_mutex_unlock(&info->eat_count);
			// pthread_mutex_unlock(&info->infofix);
			count++;
		}
		pthread_mutex_unlock(&info->eat_count);
		pthread_mutex_unlock(&info->infofix);
		i++;
	}
	if (count == info->philo_num)
		return (1);
	return (0);
}

void	ft_monitor(t_allinfo *info)
{
	int	i;

	while (!info->death_flag)
	{
		if (info->must_eat > 0)
			if (did_everyone_eat(info))
			{
				pthread_mutex_lock(&info->print);
				pthread_mutex_lock(&info->death_flag_m);
				info->death_flag = 1;
				printf("모두 밥을 다먹었습니당\n");
				pthread_mutex_unlock(&info->death_flag_m);
				pthread_mutex_unlock(&info->print);
				break ;
			}
		i = 0;
		while (i < info->philo_num)
		{
			if (check_death(&info->philo[i]))
				break ;
			i++;
		}
		if (i != info->philo_num)
			break;
	}
	// long long	now_time;

	// now_time = ft_current_time();
	// pthread_mutex_lock(&info->print);
	// printf("%lld %d %s", (now_time - info->philo[i].p_starttime), info->philo->name, "The philosopher has died\n");
	// pthread_mutex_unlock(&info->print);
	ft_distryeverything(info);
	
	//먹어야하는 횟수가 있을때
		//모두가 먹어야하는 횟수만큼 먹었는지 확인하기 
		//모두가 먹었고 죽지 않았을경우 계속하기 
	// if (info->must_eat > 0)
	// {
	// 	while (!did_everyone_eat(info) || !info->death_flag)
	// 		continue ;
	// 	ft_distryeverything(info);
	// }
	// else
	// {
	// 	while (!info->death_flag)
	// 	{
	// 		continue ;
	// 		if (info->start_time >= info->time_to_die)
	// 		{
	// 			printf("error! Timeout\n");
	// 			break ;
	// 		}
	// 	}
	// 	ft_distryeverything(info);
	// }
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
{//마이크로초로 사용할꺼임
	int				must_spend_time;
	int				start_time;
	int				end_time;
	struct timeval	start;
	struct timeval	end;

	goal_time *= 1000; //마이크로초로 변환
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

// int	ft_usleep(int goal_time, t_philo *philo)
// {
// 	int	remain_time;

// 	goal_time *= 1000;
// 	remain_time = philo->info->start_time - philo->p_startetingtime;
// 	while (philo->p_startetingtime <= goal_time)
// 	{
// 		usleep(12 * remain_time);
// 	}
// 	return (0);
// }