/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:59:07 by jihham            #+#    #+#             */
/*   Updated: 2023/07/14 11:06:14 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	free_env(t_env_manager *env_manager)
{//환경변수에 지정된 모든 환경변수 해제
	t_env	*temp;

	while (env_manager->head)
	{
		temp = env_manager->head;
		env_manager->head = env_manager->head->next;
		free(temp->key); //환경변수 노드의 키를 해제한다.
		temp->key = NULL;
		if (temp->value) // 환경변수 노드의 값이 있을경우 
		{
			free(temp->value); //값을 해제한다.
			temp->value = NULL;
		}
		free(temp); //환경변수 노드를 해제
		temp = NULL;
	}
	env_manager->size = 0; //환경변수 크기를 0으로 설정
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
