/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:53:38 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/07/21 22:57:51 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*del_front_space(char *str)
{
	int		i;
	char	*word;
	int		word_i;

	word_i = 0;
	word = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!word)
		return (NULL);
	ft_memset(word, 0, ft_strlen(str) + 1);
	word[ft_strlen(str)] = '\0';
	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		word[word_i] = str[i];
		word_i++;
		i++;
	}
	return (word);
}

static void	ft_word_combine(char *str, char *word)
{
	if (str[strlen(str) - 1] == '\"')
	{
		free(word);
		word = ft_strjoin("\"", str + 1);
	}
}

void	parsing_newlist(char *str, t_list **list_all)
{
	t_list	*token_list;
	t_list	*list;
	char	*word;

	if (str[0] != 0)
	{
		if (str[0] != '\"')
		{
			word = del_front_space(str);
			token_list = split_space(word);
			free(word);
			ft_lstadd_back(list_all, token_list);
			list = ft_lstlast(*list_all);
			list->next = NULL;
		}
		else
		{
			word = ft_strdup(str + 1);
			ft_word_combine(str, word);
			ft_lstadd_back(list_all, ft_lstnew(ft_strdup(word)));
			free(word);
			list = ft_lstlast(*list_all);
			list->next = NULL;
		}
	}
}

void	parsing_command(t_cmd_info *cmd, char *path)
{
	t_cmd_info	*cmd_c;
	int			i;
	t_list		*list_all;

	cmd_c = cmd;
	list_all = NULL;
	while (cmd_c)
	{
		i = -1;
		{
			while (cmd_c->argv && cmd_c->argv[++i])
			{
				parsing_newlist(cmd_c->argv[i], &list_all);
				free(cmd_c->argv[i]);
				cmd_c->argv[i] = NULL;
			}
			free(cmd_c->argv);
			cmd_c->argv = merge_token(list_all);
			put_path(cmd_c->argv, path);
			cmd_c = cmd_c->next;
			free_list1(&list_all);
		}
	}
	free(path);
}
