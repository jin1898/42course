/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_overall_structure.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:38:10 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/07/21 21:14:45 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

static int	ft_slice_count(char *str, char sep, int *sep_idx)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == sep)
		{
			*sep_idx = i;
			break ;
		}
		i++;
	}
	return (i);
}

char	**ft_slice(char *str, char sep)
{
	char	**strs;
	size_t	i;
	int		sep_idx;
	size_t	str_len;

	sep_idx = 0;
	str_len = ft_strlen(str);
	i = ft_slice_count(str, sep, &sep_idx);
	if (i == str_len)
		return (0);
	strs = (char **)malloc(sizeof(char *) * 3);
	if (!strs)
		return (NULL);
	strs[2] = 0;
	strs[0] = (char *)malloc(sizeof(char) * (sep_idx));
	strs[1] = (char *)malloc(sizeof(char) * (str_len - sep_idx + 1));
	ft_strlcpy(strs[0], str, sep_idx + 1);
	ft_strlcpy(strs[1], str + sep_idx + 1, str_len - sep_idx);
	return (strs);
}

t_cmd_info	*parsing_allparts(char *line, t_env_manager *env_lst)
{
	int			pipe_num;
	t_list		*token_list;
	t_cmd_info	*cmd_info_arr;
	t_cmd_info	*temp;

	token_list = splitting_values_into_tokens(line);
	if (token_list == NULL)
		return (NULL);
	pipe_num = get_pipnum(token_list);
	cmd_info_arr = cmd_arr_init(&token_list, pipe_num);
	if (cmd_info_arr == NULL)
	{
		free_list1(&token_list);
		return (NULL);
	}
	fill_cmd_info_arr(cmd_info_arr, token_list, env_lst);
	free_list1(&token_list);
	temp = cmd_info_arr;
	while (temp)
	{
		temp->pipe_num = pipe_num;
		temp = temp->next;
	}
	return (cmd_info_arr);
}
