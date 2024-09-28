/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_space_for_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:53:51 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/07/21 20:54:42 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	split_init(t_list **spl_list, int *start_i, \
int *line_i, int *quote_flag)
{
	*spl_list = NULL;
	*start_i = 0;
	*line_i = 0;
	*quote_flag = 0;
}

static void	quote_do(int *start_i, int line_i, \
t_list **spl_list, char *line)
{
	if ((*start_i) != line_i)
		ft_lstadd_back(spl_list, ft_lstnew(\
		ft_substr(line, (*start_i), line_i - (*start_i))));
	(*start_i) = line_i + 1;
}

static void	add_back(t_list	**spl_list, int line_i, \
int start_i, char *line)
{
	ft_lstadd_back(spl_list, ft_lstnew(\
	ft_substr(line, start_i, line_i - start_i)));
}

t_list	*split_space(char *line)
{
	t_list	*spl_list;
	int		start_i;
	int		line_i;
	int		quote_flag;

	split_init(&spl_list, &start_i, &line_i, &quote_flag);
	while (line[line_i])
	{
		if (!quote_flag && check_space(line[++line_i]))
		{
			if (start_i != line_i)
				ft_lstadd_back(&spl_list, ft_lstnew(\
				ft_substr(line, start_i, line_i - start_i)));
			start_i = line_i + 1;
		}
		else if (!quote_flag && (line[line_i] == '\"' || line[line_i] == '\''))
			quote_flag = line[line_i];
		else if (quote_flag == line[line_i])
			quote_flag = 0;
	}
	if (quote_flag)
		quote_do(&start_i, line_i, &spl_list, line);
	if (start_i != line_i)
		add_back(&spl_list, line_i, start_i, line);
	return (spl_list);
}
