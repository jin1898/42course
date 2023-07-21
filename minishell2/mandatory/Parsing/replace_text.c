/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:15:28 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/07/21 20:19:03 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_value(t_value *value, char *str, t_list **text_list)
{
	value->str_i = 0;
	value->buf_i = 0;
	*text_list = NULL;
	value->q_flag = 0;
	value->quote = 0;
	value->buff = malloc(sizeof(char) * (ft_strlen(str) + 1));
	ft_bzero(value->buff, (ft_strlen(str) + 1));
}

static void	ft_str_check(char *str, t_value *value, \
t_list **text_list, t_env_manager *env_lst)
{
	while (str[value->str_i])
	{
		if (!value->quote && (str[value->str_i] == '\'' \
		|| str[value->str_i] == '\"'))
		{
			create_buff_put_end_of_list(value->buff, &value->buf_i, text_list);
			if (str[value->str_i] == '"')
				value->q_flag = 1;
			value->quote = str[value->str_i];
		}
		else if (value->quote == str[value->str_i])
		{
			create_buff_put_end_of_list(value->buff, &value->buf_i, text_list);
			value->quote = 0;
		}
		else if (str[value->str_i] == '$' && (value->quote != '\''))
		{
			create_buff_put_end_of_list(value->buff, &value->buf_i, text_list);
			ft_lstadd_back(text_list, ft_lstnew(\
			expand_env(str + value->str_i + 1, &value->str_i, env_lst)));
		}
		else
			value->buff[value->buf_i++] = str[value->str_i];
		value->str_i++;
	}
}

char	*replace_symbol_to_text(char *str, \
t_env_manager *env_lst, t_value *value)
{
	t_list	*text_list;
	char	*word;

	init_value(value, str, &text_list);
	ft_str_check(str, value, &text_list, env_lst);
	create_buff_put_end_of_list(value->buff, &value->buf_i, &text_list);
	ft_free_util((void **)&value->buff);
	if (value->q_flag == 1 && value->redir != 1)
	{
		word = connect_list(text_list);
		free_list1(&text_list);
		value->text = ft_strjoin("\"", word);
		ft_free_util((void **)&word);
	}
	else
	{
		value->text = connect_list(text_list);
		free_list1(&text_list);
	}
	return (value->text);
}
