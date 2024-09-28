/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseong <hyseong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:16:13 by hyseong           #+#    #+#             */
/*   Updated: 2023/07/21 17:16:14 by hyseong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_unlink(void)
{
	DIR				*directory;
	struct dirent	*entry;
	char			*comma_pos;
	char			*join;

	directory = opendir("/tmp");
	while (1)
	{
		entry = readdir(directory);
		if (!entry)
			break ;
		comma_pos = ft_strrchr(entry->d_name, '.');
		if (comma_pos && ft_strncmp(comma_pos, ".mine", 6) == 0)
		{
			join = ft_strjoin("/tmp/", entry->d_name);
			unlink(join);
			ft_free_util((void **)&join);
		}
	}
	closedir(directory);
}

char	*get_heredoc_filename(int i)
{
	char	*temp;
	char	*result;
	char	*filenum;

	filenum = ft_itoa(i);
	temp = ft_strjoin(filenum, ".mine");
	ft_free_util((void **)&filenum);
	result = ft_strjoin("/tmp/", temp);
	ft_free_util((void **)&temp);
	if (!result)
		return (NULL);
	return (result);
}

int	new_heredoc_open(int i)
{
	int		fd;
	char	*result;

	result = get_heredoc_filename(i);
	if (!result)
		return (-1);
	if (!access(result, F_OK))
		unlink(result);
	fd = open(result, O_CREAT | O_RDWR | O_TRUNC, 0644);
	free(result);
	return (fd);
}

int	heredoc_open(int i)
{
	int		fd;
	char	*result;

	result = get_heredoc_filename(i);
	if (!result)
		return (-1);
	fd = open(result, O_RDWR, 0644);
	free(result);
	return (fd);
}
