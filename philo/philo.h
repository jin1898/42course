/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:35:16 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/08/03 18:43:29 by jsunwoo          ###   ########.fr       */
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
	long int		start_time;
	int				ready;
	int				*fork;
	struct s_philo	*philo;
	pthread_mutex_t	*fork_m;
	pthread_mutex_t	print;
	pthread_mutex_t	death_flag_m;
	pthread_mutex_t	p_startetingtime; //check_death 와 ft_doac에서 startetingtime을 모두 사용하기 때문에 필요함.
	pthread_mutex_t	eat_count;
}	t_allinfo;

typedef struct s_philo
{
	pthread_t			p_thread;
	int					name;
	int					right_fork;
	int					left_fork;
	long int			p_starttime;
	long int			p_startetingtime;
	int					eat_count;
	t_allinfo			*info;
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
void		ft_print_one_end(char **av);
void		ft_eat(t_philo *philo);
#endif
