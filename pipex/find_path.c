/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:50:31 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/04/24 20:43:58 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	find_path(char **envp, t_db *db)
{
	int	a;

	while (*envp)
	{
		if (!(ft_strcmp(envp, "PATH")))
			break ;
		envp++;
	}
	db->path = *envp + 5;
	a = ft_split(envp, ':');
	if (!a)
		return (0);
}

char	**ft_split(char **s1, char split_word)
{
	char	**s1_c;
	int		box_count;
	char	**ret;
	char	**ret2;

	s1_c = s1;
	while (*s1_c)
	{
		while (split_word == *s1_c && split_word != '\0')
			s1_c++;
		box_count++;
		while (split_word != *s1_c && split_word != '\0')
			s1_c++;
	}
	ret = malloc(sizeof(char) * box_count + 1);
	if (!ret)
		return (0);
	ret2 = shape_word(ret, s1, split_word);
	if (ret2 != &ret[box_count])
		free_arr(&ret, ret2);
	return (ret);
}

char	**shape_word(char **ret, char **s1, char split_word)
{
	char	*startpoint;
	char	**ret_p;
	int		i;

	while (*s1)
	{
		while (split_word == *s1 && split_word != '\0')
			s1++;
		if (split_word != '\0')
			return (0);
		startpoint = s1;
		while (split_word != *s1 && split_word != '\0')
			s1++;
		ret_p = malloc(sizeof(char) * (startpoint - s1) + 1);
		ret_p[startpoint - s1] = 0;
		i = -1;
		while (++i < (startpoint - s1))
			*ret_p++ = *startpoint++;
		*ret_p = '\0';
		ret++;
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
