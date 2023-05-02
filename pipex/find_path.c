/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:50:31 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/05/01 20:39:58 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	find_path(char **envp, t_db *db)
{
	char	*a;

	while (*envp)
	{
		if (!(ft_strncmp(*envp, "PATH", 4)))
			break ;
		envp++;
	}
	a = *envp + 5;
	if (!a)
		return (0);
	db->path = ft_split(a, ':');
	if (!db->path)
		error_message("Environment");
	return (1);
}

char	**ft_split(char *s1, char split_word)
{
	char	*s1_c;
	int		box_count;
	char	**ret;
	char	**ret2;

	box_count = 0;
	s1_c = s1;
	while (*s1_c != '\0')
	{
		while (split_word == *s1_c && *s1_c != '\0')
			s1_c++;
		if (*s1_c == '\0')
			break ;
		box_count++;
		while (split_word != *s1_c && *s1_c != '\0')
			s1_c++;
	}
	ret = malloc(sizeof(char *) * (box_count + 1));
	if (!ret)
		return (0);
	ret[box_count] = NULL;
	ret2 = shape_word(ret, s1, split_word);
	if (ret2 != ret)
		free_arr(&ret, ret2);
	return (ret2);
}

char	**shape_word(char **ret, char *s1, char split_word)
{
	char	*ret_p;
	int		start;
	int		end;
	int		i;
	int		i2;

	i = 0;
	start = 0;
	i2 = 0;
	while (s1 != NULL && s1[i])
	{
		while (split_word == s1[i] && s1[i++] != '\0')
			start++;
		end = start;
		while (split_word != s1[i] && s1[i] != '\0')
		{
			i++;
			end++;
		}
		ret_p = ft_substr(s1, start, (end - start));
		start = i;
		ret[i2++] = ret_p;
		ret_p = NULL;
	}
	return (ret);
}

void	free_arr(char ***ret, char **ret2)
{
	char	**ret_p;

	ret_p = *ret;
	while (ret_p < ret2)
	{
		free(*ret_p);
		ret_p++;
	}
	free(*ret);
	ret = NULL;
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
