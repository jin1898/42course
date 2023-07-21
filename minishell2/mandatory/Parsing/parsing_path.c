/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:51:07 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/07/21 21:03:08 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**ft_free(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	return (0);
}

static void	access_change(int *i, char **s_path, char **argv)
{
	char	*temp;
	char	*temp1;

	while (s_path[++(*i)])
	{
		temp = ft_strjoin(s_path[*i], "/");
		temp1 = ft_strjoin(temp, argv[0]);
		free(temp);
		if (access(temp1, X_OK | F_OK) == 0)
		{
			free(argv[0]);
			argv[0] = temp1;
			break ;
		}
		else
			free(temp1);
	}
}

static int	check_builtin(char **argv)
{
	if (ft_strncmp(argv[0], "cd", 3) == 0)
		return (0);
	else if (ft_strncmp(argv[0], "echo", 5) == 0)
		return (0);
	else if (ft_strncmp(argv[0], "env", 4) == 0)
		return (0);
	else if (ft_strncmp(argv[0], "exit", 5) == 0)
		return (0);
	else if (ft_strncmp(argv[0], "export", 7) == 0)
		return (0);
	else if (ft_strncmp(argv[0], "pwd", 4) == 0)
		return (0);
	else if (ft_strncmp(argv[0], "unset", 6) == 0)
		return (0);
	else
		return (1);
}

void	put_path(char **argv, char *path)
{
	char	**s_path;
	int		i;

	i = -1;
	if (argv[0] && !*argv[0])
		return ;
	if (*argv && check_builtin(argv))
	{
		s_path = ft_split(path, ':');
		access_change(&i, s_path, argv);
		ft_free(s_path);
	}
}
