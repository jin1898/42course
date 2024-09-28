/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseong <hyseong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:18:07 by hyseong           #+#    #+#             */
/*   Updated: 2023/07/21 17:18:08 by hyseong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	free_env(t_env_manager *env_manager)
{
	t_env	*temp;

	while (env_manager->head)
	{
		temp = env_manager->head;
		env_manager->head = env_manager->head->next;
		free(temp->key);
		temp->key = NULL;
		if (temp->value)
		{
			free(temp->value);
			temp->value = NULL;
		}
		free(temp);
		temp = NULL;
	}
	env_manager->size = 0;
	return (0);
}

int	free_node(t_env **node)
{
	free((*node)->key);
	(*node)->key = NULL;
	if ((*node)->value)
	{
		free((*node)->value);
		(*node)->value = NULL;
	}
	free(*node);
	*node = NULL;
	return (1);
}

void	free_for_exit(t_env_manager *env_manager, int code)
{
	free_env(env_manager);
	exit(code);
}
