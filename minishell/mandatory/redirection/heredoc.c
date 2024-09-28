/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:16:18 by hyseong           #+#    #+#             */
/*   Updated: 2023/07/25 21:07:43 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

static int	print_prev_dollar(int fd, int *cur_i, char *str)
{
	int	prev_i;

	prev_i = *cur_i;
	if (!str || !str[*cur_i])
		return (1);
	while (str[*cur_i])
	{
		if (str[*cur_i] == '$')
			break ;
		(*cur_i)++;
	}
	return (write(fd, str + prev_i, *cur_i - prev_i) && 0);
}

static int	ft_check_first_letter(int *cur_i, char *str)
{
	if (ft_isdigit(str[*cur_i]) && str[*cur_i + 1])
	{
		(*cur_i)++;
		return (1);
	}
	return (0);
}

static int	print_env_expand(int fd, int *cur_i, char *str, \
t_env_manager *env_manager)
{
	int		prev_i;
	char	*env_key;
	t_env	*env;

	prev_i = *cur_i;
	if (!str || !str[*cur_i])
		return (1);
	(*cur_i)++;
	if (!str[*cur_i])
		return (write(fd, str + prev_i, *cur_i - prev_i) || 1);
	if (str[(*cur_i)] == '?')
		return (ft_printf(fd, "%d", g_exit_status) && (*cur_i)++ && 0);
	if (ft_check_first_letter(cur_i, str))
		return (0);
	if ((str[*cur_i] != '_' && !ft_isalnum(str[*cur_i])))
		return (write(fd, str + prev_i, *cur_i - prev_i) && 0);
	while (str[++(*cur_i)])
		if (str[*cur_i] != '_' && !ft_isalnum(str[*cur_i]))
			break ;
	env_key = ft_substr(str + prev_i, 1, *cur_i - prev_i - 1);
	env = get_env(env_manager->head, env_key);
	if (!env || !env->value || !*env->value)
		return (ft_free_util((void **)&env_key));
	return (ft_free_util((void **)&env_key) || \
		(write(fd, env->value, ft_strlen(env->value)) && 0));
}

static int	print_with_expand(int fd, char *str, t_env_manager *env_manager)
{
	int		i;

	i = 0;
	while (1)
		if (print_prev_dollar(fd, &i, str) || \
				print_env_expand(fd, &i, str, env_manager))
			return (0);
}

void	heredoc_child_check(char *delimiter, int fd, t_env_manager *env_manager)
{
	char	*str;

	set_heredoc_signal();
	while (fd > 0)
	{
		str = readline("> ");
		if (!str)
			exit(0);
		if (!ft_strncmp(str, delimiter, ft_strlen(delimiter) + 1))
		{
			ft_free_util((void **)&str);
			exit(0);
		}
		print_with_expand(fd, str, env_manager);
		ft_putstr_fd("\n", fd);
		ft_free_util((void **)&str);
	}
	exit(1);
}
