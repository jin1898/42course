/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:35:16 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/07/21 14:09:39 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_allinfo
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				death_flag;
	int				eating_flag;
	long int		start_time;
	int				ready; //모든 스레드의준비가 된상태에서 행동을 시작해야함. 준비가 될때까지 기다리기위함.
	struct s_philo	*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	infofix;
}	t_allinfo;

typedef struct s_philo
{
	pthread_t			p_thread;
	int					name;
	int					right_fork;
	int					left_fork;
	long int			p_starttime;
	long int 			p_startetingtime;
	int					eat_count;
	struct s_allinfo	*info;
	//int				death_time;// 이거 필요없는것같은뎅 나중에 지우자
	pthread_mutex_t		lf;
	pthread_mutex_t		rf;
}	t_philo;

int			ft_usleep(int goal_time, int num);
int			check_death(t_philo *philo);
void		ft_sleep_think(t_philo *philo);
long int	ft_current_time(void);
void		ft_monitor(t_allinfo *info);
void		ft_distryeverything(t_allinfo *info);
long long	ft_atoi(const char *str);
int			check_error_num(int ac, char **av);
int			init_each_philo(t_allinfo *info);
int			init_everything(t_allinfo *info, char**av);
int			ft_printf(t_philo *philo, char *str);
#endif
