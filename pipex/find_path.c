/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:50:31 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/04/30 02:10:28 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	printf("1 %p\n",db->path);
	// int i = 0;
	// while(db->path[i])
	// {
	// 	printf("db->path %s\n",db->path[i]);
	// 	i++;
	// }
	if (!db->path)
		error_message("Environment");
	printf("2 %p\n",db->path);
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
	ret[box_count] = NULL;
	if (!ret)
		return (0);
	ret2 = shape_word(ret, s1, split_word);
	if (ret2 != ret)
		free_arr(&ret, ret2);
	return (ret2);
}

char	**shape_word(char **ret, char *s1, char split_word)
{
	char	**ret_p;
	int		start;
	int		end;
	int		i;
	int		e;

	i = 0;
	start = 0;
	e = 0;
	ret_p = ret;
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
		*ret_p = ft_substr(s1, start, (end - start));
		start = i;
		ret[e++] = *ret_p;
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
