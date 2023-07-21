/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:12:06 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/07/21 20:13:44 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

static char	*ft_pexitstatus(int *str_i)
{
	char	*str;

	if (str_i)
		*str_i += 1;
	str = ft_itoa(g_exit_status);
	g_exit_status = 0;
	return (str);
}

static char	*ft_find_cur(t_env *cur, char *substr, int len, char **status_num)
{
	char	*str;

	while (cur)
	{
		if (!strncmp(substr, cur->key, len) && cur->key[len] == '\0')
		{
			if (*status_num && cur->value)
			{
				str = ft_strjoin(cur->value, *status_num);
				ft_free_util((void **)status_num);
				return (str);
			}
			if (cur->value && !ft_free_util((void **)status_num))
				return (ft_strdup(cur->value));
		}
		cur = cur->next;
	}
	return (NULL);
}

char	*expand_env(char *substr, int *str_i, t_env_manager *env_lst)
{
	t_env	*cur;
	int		len;
	char	*status_num;
	char	*result;

	if (substr[0] == '?')
		return (ft_pexitstatus(str_i));
	len = 0;
	status_num = NULL;
	while (ft_isalpha(substr[len]) || ft_isalnum(substr[len]))
		len++;
	if (str_i)
		*str_i += len;
	cur = env_lst->head;
	result = ft_find_cur(cur, substr, len, &status_num);
	if (result)
		return (result);
	if (ft_isdigit(substr[0]))
		return (ft_substr((substr + 1), 0, ft_strlen(substr + 1) - 1));
	if (substr[0] == '\0' || (substr[ft_strlen(substr)-1] == '\"'))
		return (ft_strdup("$"));
	ft_free_util((void **)&status_num);
	return (ft_strdup(""));
}
