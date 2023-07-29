/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:56:35 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/07/29 20:20:43 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	if (philo->info->philo_num % 2 == 0)
	{
		pthread_mutex_lock(&philo->info->fork_m[philo->right_fork]);
		if (ft_printf(philo, " has taken a fork\n"))
		{
			pthread_mutex_unlock(&philo->info->fork_m[philo->right_fork]);
			return ;
		}
		pthread_mutex_lock(&philo->info->fork_m[philo->left_fork]);
		if (ft_printf(philo, " has taken a fork\n"))
		{
			pthread_mutex_unlock(&philo->info->fork_m[philo->left_fork]);
			pthread_mutex_unlock(&philo->info->fork_m[philo->right_fork]);
			return ;
		}
	}
	else
	{
		pthread_mutex_lock(&philo->info->fork_m[philo->left_fork]);
		if (ft_printf(philo, " has taken a fork1\n"))
		{
			return ;
		}
		pthread_mutex_lock(&philo->info->fork_m[philo->right_fork]);
		if (ft_printf(philo, " has taken a fork2\n"))
		{
			pthread_mutex_unlock(&philo->info->fork_m[philo->right_fork]);
			pthread_mutex_unlock(&philo->info->fork_m[philo->right_fork]);
			return ;
		}
	}
	if (ft_printf(philo, " is eating\n"))
	{
		pthread_mutex_unlock(&philo->info->fork_m[philo->left_fork]);
		pthread_mutex_unlock(&philo->info->fork_m[philo->right_fork]);
		return ;
	}
	pthread_mutex_lock(&philo->info->infofix);
	pthread_mutex_lock(&philo->info->p_startetingtime);
	philo->p_startetingtime = ft_current_time();
	pthread_mutex_unlock(&philo->info->p_startetingtime);
	pthread_mutex_unlock(&philo->info->infofix);
	ft_usleep(philo->info->time_to_eat, philo->name);
	pthread_mutex_lock(&philo->info->infofix);
	pthread_mutex_lock(&philo->info->eat_count);
	philo->eat_count += 1;
	pthread_mutex_unlock(&philo->info->eat_count);
	pthread_mutex_unlock(&philo->info->infofix);
	pthread_mutex_unlock(&philo->info->fork_m[philo->right_fork]);
	pthread_mutex_unlock(&philo->info->fork_m[philo->left_fork]);
}

void	ft_sleep_think(t_philo *philo)
{
	// if (check_death(philo))
	// 	return ;
	if (ft_printf(philo, " is sleeping\n"))
		return ;
	ft_usleep(philo->info->time_to_sleep, philo->name);
	// if (check_death(philo))
	// 	return ;
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
		pthread_mutex_lock(&philo->info->death_flag_m); //준호님이 이게 필요하다하셨는데 왜인지 모르겠음 그때 듣기로는 잠궜는데 풀것이 없다고하셨음
	}
	pthread_mutex_unlock(&philo->info->death_flag_m); //준호님이 이게 필요하다하셨는데 왜인지 모르겠음 그때 듣기로는 잠궜는데 풀것이 없다고하셨음
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

	if (check_error_num(ac, av)) // 인자갯수, 음수, int오버플로우 일경우 에러로인지
		return (1);
	if (ft_atoi(av[1]) == 1)
	{
		ft_print_one_end(av);
		return (0);
	}
	if (init_everything(&info, av)) // 필요 구조체들 모두 초기화하기
		return (1);
	else if (take_action(&info))// exec_simul, exec_philoes_and_monitor
		return (1);
	return (0);
}

//필로소퍼 비주얼라이저 스는거 추천(밀리는 곳을시각적으로 볼수있어서 고치기좋음) / 문자열서브젝트대로 바꾸기 (문자가 다르면 fail요소임) 
//컨텍트 스위칭 문맥교환 때문에 usleep을 10ms정도, 크게줘라 1000정도
//데이터레이스 
//문맥교환, 쓰레드와 프로세스 차이, 쓰레드와 프로세스의 문맥교환차이
//usleep while돌아야하는데 sleep eat시간만큼 돌기 스레드가 죽었거나 그만큼 시간을 보냈는지 확인(시간다보냈으면 조용히나오기) 
//while문들어가기직전에 시간갖고  time구조체에 넣기 
//마이크로초로 계산하고 출력시에만 밀리초로 표현하기 (안그러면 밀림), usleep을 하는 중간에 죽는지체크해야함 100마이크로 마다 죽음체크해야함.죽음을 10ms마다 체크가능하면서 usleep최대한 크게 줄수있는 범위출력을 찾아야함.

//exam rank 03 va_arg man

//내가 해야할일들.. 단위 통일 > usleep으로 죽음 확인 > 죽었을시 동작을 그만두게 흘려내보낼수있는지 확인 >
//문자열 서브젝트 바꾸기 
//./philo 3 310 200 100  ./philo 4 310 200 100  죽어야하는데 안죽음 (즉 뮤텍스관리가 안되고있음.)