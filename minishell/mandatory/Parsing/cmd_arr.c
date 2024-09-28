/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:12:50 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/07/21 20:21:03 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

char	*connect_list(t_list *list)
{
	char	*text;
	t_list	*cur;
	int		len;

	len = 0;
	cur = list;
	while (cur)
	{
		len += ft_strlen((char *)(cur->content));
		cur = cur->next;
	}
	text = malloc(sizeof(char) * (len + 1));
	ft_bzero(text, sizeof(char) * (len + 1));
	cur = list;
	while (cur)
	{
		ft_strlcat(text, (char *)(cur->content), len + 1);
		cur = cur->next;
	}
	return (text);
}

int	check_mbgos(char *str, t_value *value, t_env_manager *env_lst)
{
	char	c;
	char	*s;
	int		i;
	int		word;

	c = ' ';
	s = str;
	i = 0;
	value->mbgos = 0;
	word = 0;
	if (str[i] == '$')
	{
		value->mbgos = 1;
		s = expand_env(str + 1, &value->str_i, env_lst);
	}
	value->s_c = s;
	while (*s)
	{
		if (*s != c && (*(s + 1) == '\0' || *(s + 1) == c))
			word++;
		s++;
	}
	if (value->mbgos == 1)
		free(value->s_c);
	return (word);
}

char	**split_token(char **a)
{
	t_list	*split;
	t_list	*s_cpy;
	int		count;
	char	**result;

	split = first_parsing_by_space(a[0]);
	s_cpy = split;
	count = 0;
	while (s_cpy)
	{
		count++;
		s_cpy = s_cpy->next;
	}
	result = malloc(sizeof(char *) * count);
	s_cpy = split;
	count = 0;
	while (s_cpy)
	{
		result[count] = s_cpy->content;
		count++;
		s_cpy = s_cpy->next;
	}
	return (result);
}
