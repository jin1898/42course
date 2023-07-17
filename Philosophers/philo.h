/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:35:16 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/07/10 20:10:10 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_allinfo
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				death_flag;
	int				eating_flag;
	int				start_time;
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
	int					eat_count;
	struct s_allinfo	*info;
	int					death_time;
}	t_philo;

long long	ft_atoi(const char *str);
#endif
