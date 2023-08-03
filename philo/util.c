/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:29:08 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/08/03 17:42:31 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_atoi(const char *str)
{
	int			i;
	long long	result;
	int			n;

	i = 0;
	result = 0;
	n = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		n *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * n);
}

long int	ft_current_time(void) //리턴값 인인트트랑  바바이이트트사사이이즈즈가가같같음 long int와 long long int가 다른거고 int는 long int와 마찬가지로 범위는 같다.
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

int	ft_printf(t_philo *philo, char *str)
{
	long long	now_time;
	int			internal_death_flag;

	pthread_mutex_lock(&philo->info->print);
	pthread_mutex_lock(&philo->info->death_flag_m);
	internal_death_flag = philo->info->death_flag;
	pthread_mutex_unlock(&philo->info->death_flag_m);
	if (!internal_death_flag)
	{
		now_time = ft_current_time();
		printf("%lld %d %s", (now_time - philo->p_starttime), philo->name, str);
		usleep(5);//락을 걸었는데 printf의 순서가 꼬일리가없다.
		pthread_mutex_unlock(&philo->info->print);
	}
	else
	{
		pthread_mutex_unlock(&philo->info->print);
		return (1);
	}
	return (0);
}
