/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:08:07 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/04/30 20:25:34 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	char	tmp[1000];

	cmd_s = ft_split(argv[2 + db->h_flag + idx], ' ');
	cmd = find_cmd(db->path, cmd_s[0]);
	if (cmd == NULL)
	{
		write(2, "Command not found: ", ft_strlen("Command not found: "));
		write(2, cmd_s[0], ft_strlen(cmd_s[0]));
		write(2, "\n", sizeof(char));
		exit(1);
	}


	write(2, "\n----tmp----\n",ft_strlen("\n----tmp----\n"));
	sprintf(tmp, "cmd_s(%s),cmd(%s)\n\na : %d\n",*cmd_s,cmd,execve(cmd, cmd_s, envp));
	write(2, tmp, 50);
	write(2, "\n----tmp----\n",ft_strlen("\n----tmp----\n"));
}

char	*find_cmd(char	**path, char *cmd)
{
	char	*tmp2;
	char	*ret;

	while (*path != NULL)
	{
		tmp2 = ft_strjoin(*path, "/", ft_strlen(*path), ft_strlen("/"));
		ret = ft_strjoin(tmp2, cmd, ft_strlen(tmp2), ft_strlen(cmd));
		if (access(ret, X_OK) == 0)
			return (ret);
		free(ret);
		path++;
	}
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
	waitpid(-1, NULL, 0);
}
