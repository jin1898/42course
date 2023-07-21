/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:41:36 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/07/21 21:56:35 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

static void	init_vlaue(t_list **spl_list, \
int *start_i, int *line_i, int *quote_flag)
{
	*spl_list = NULL;
	*start_i = 0;
	*line_i = -1;
	*quote_flag = 0;
}

static void	cmpar_i(int *start_i, char **line, \
int *line_i, t_list **spl_list)
{
	if (*start_i != *line_i)
		ft_lstadd_back(spl_list, ft_lstnew(\
		ft_substr(*line, *start_i, *line_i - *start_i)));
	*start_i = *line_i + 1;
}

t_list	*first_parsing_by_space(char *line)
{
	t_list	*spl_list;
	int		start_i;
	int		line_i;
	int		quote_flag;

	init_vlaue(&spl_list, &start_i, &line_i, &quote_flag);
	while (line[++line_i])
	{
		if (!quote_flag && check_space(line[line_i]))
			cmpar_i(&start_i, &line, &line_i, &spl_list);
		else if (!quote_flag && (line[line_i] == '\"' || line[line_i] == '\''))
			quote_flag = line[line_i];
		else if (quote_flag == line[line_i])
			quote_flag = 0;
	}
	if (quote_flag)
	{
		if (spl_list)
			free_list1(&spl_list);
		ft_printf(1, "minishell: syntax error: unexpected end of file\n");
		g_exit_status = 258;
		return (NULL);
	}
	if (start_i != line_i)
		ft_lstadd_back(&spl_list, ft_lstnew(\
		ft_substr(line, start_i, line_i - start_i)));
	return (spl_list);
}

t_list	*splitting_values_into_tokens(char *line)
{
	t_list	*token_list;
	t_list	*spl_list;
	t_list	*spl_cur;

	token_list = NULL;
	spl_list = NULL;
	spl_list = first_parsing_by_space(line);
	if (spl_list == NULL)
		return (NULL);
	spl_cur = spl_list;
	while (spl_cur)
	{
		second_parsing_by_metacharacters(&token_list, \
		(char *)(spl_cur->content));
		spl_cur = spl_cur->next;
	}
	free_list1(&spl_list);
	return (token_list);
}
