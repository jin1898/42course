/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:08:07 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/05/02 21:23:19 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	unsigned char	*s1_c;
	unsigned char	*s2_c;
	int				i;

	i = 0;
	s1_c = (unsigned char *)s1;
	s2_c = (unsigned char *)s2;
	while (i < n && *s1_c == *s2_c)
	{
		if (*s1_c == '\0' || i == (n - 1))
			return (0);
		i++;
		s1_c++;
		s2_c++;
	}
	return (*s1_c - *s2_c);
}

int	ft_strcmp2(char *s1, char *s2, int a)
{
	unsigned char	*s1_c;
	unsigned char	*s2_c;
	int				i;

	i = 0;
	s1_c = (unsigned char *)s1;
	s2_c = (unsigned char *)s2;
	while (*s1_c == *s2_c)
	{
		if (*s1_c == '\n')
			return (0);
		i++;
		s1_c++;
		s2_c++;
	}
	if (*s1_c == '\n' && i == a)
		return (0);
	return (*s1_c - *s2_c);
}

void	excute_cmd(int idx, char **argv, t_db *db, char **envp)
{
	char	**cmd_s;
	char	*cmd;

	cmd_s = ft_split(argv[2 + db->h_flag + idx], ' ');
	cmd = find_cmd(db->path, cmd_s[0], db);
	if (cmd == NULL)
	{
		write(2, "Command not found: ", ft_strlen("Command not found: "));
		write(2, cmd_s[0], ft_strlen(cmd_s[0]));
		write(2, "\n", sizeof(char));
		exit(1);
	}
	execve(cmd, cmd_s, envp);
}

char	*find_cmd(char	**path, char *cmd, t_db *db)
{
	char	*tmp2;
	char	*ret;
	int		i;

	i = 0;
	while (path[i] != NULL)
	{
		ret = ft_substr(path[i], 0, ft_strlen(path[i]));
		tmp2 = ft_strjoin(ret, "/", ft_strlen(path[i]), ft_strlen("/"));
		ret = ft_strjoin(tmp2, cmd, ft_strlen(tmp2), ft_strlen(cmd));
		if (access(ret, X_OK) == 0)
			return (ret);
		i++;
		free(ret);
	}
	db->error_flag = 1;
	db->cmd = cmd;
	return (NULL);
}

void	close_and_wait(t_db	*db)
{
	int	i;

	i = 0;
	while (i < (db->cmdnum - 1) * 2)
	{
		close(db->pipebox[i]);
		i++;
	}
	while (wait(0) > 0)
		;
}
