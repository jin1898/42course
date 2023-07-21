/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:37:25 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/07/21 20:37:44 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	second_parsing_by_metacharacters(t_list **token_list, char *str)
{
	char	*buff;
	int		str_i;
	int		buf_i;
	int		quote_flag;

	str_i = 0;
	buf_i = 0;
	quote_flag = 0;
	buff = malloc(sizeof(char) * (ft_strlen(str) + 1));
	ft_bzero(buff, sizeof(char) * (ft_strlen(str) + 1));
	while (str[str_i])
	{
		if (buf_i && !quote_flag && check_new_token(str, str_i, buff))
			create_buff_put_end_of_list(buff, &buf_i, token_list);
		if (!quote_flag && (str[str_i] == '\'' || str[str_i] == '\"'))
			quote_flag = str[str_i];
		else if (quote_flag == str[str_i])
			quote_flag = 0;
		buff[buf_i] = str[str_i];
		buf_i++;
		str_i++;
	}
	create_buff_put_end_of_list(buff, &buf_i, token_list);
	ft_free_util((void **)&buff);
}

void	create_buff_put_end_of_list(char *buff, int *buf_i, t_list **token_list)
{
	buff[*buf_i] = '\0';
	ft_lstadd_back(token_list, ft_lstnew(ft_strdup(buff)));
	ft_bzero(buff, ft_strlen(buff) + 1);
	*buf_i = 0;
}

int	check_new_token(char *str, int jdx, char *buff)
{
	if (str[jdx] == '|')
		return (1);
	else if (str[jdx] == '<')
	{
		if (!ft_strncmp(buff, "<", 2))
			return (0);
		return (1);
	}
	else if (str[jdx] == '>')
	{
		if (!ft_strncmp(buff, ">", 2))
			return (0);
		return (1);
	}
	if (check_redir(buff) || !ft_strncmp(buff, "|", 2))
		return (1);
	return (0);
}
