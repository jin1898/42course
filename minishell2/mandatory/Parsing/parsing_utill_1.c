/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utill_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:46:38 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/07/21 21:07:02 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_count_list(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

char	**merge_token(t_list *list_all)
{
	char	**answer;
	int		i;

	i = -1;
	answer = malloc(sizeof(char *) * (ft_count_list(list_all) + 1));
	answer[ft_count_list(list_all)] = 0;
	while (list_all)
	{
		answer[++i] = ft_strdup(list_all->content);
		list_all = list_all->next;
	}
	return (answer);
}

void	free_list1(t_list**list_all)
{
	t_list	*temp;

	while (*list_all)
	{
		temp = *list_all;
		*list_all = (*list_all)->next;
		ft_free_util((void **)&temp->content);
		ft_free_util((void **)&temp);
	}
	*list_all = NULL;
}

// void	free_list2(t_list **list, char **chr)
// {
// 	ft_free_util((void **)&list);
// 	*list = NULL;
// 	ft_free_util((void **)&chr);
// 	*chr = NULL;
// }

// int	find_colon(char *str, int idx)
// {
// 	int	len;

// 	len = idx;
// 	while (str[len] && str[len] != ':')
// 		len++;
// 	return (len);
// }
