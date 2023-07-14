/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_node_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihham <jihham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:00:45 by jihham            #+#    #+#             */
/*   Updated: 2023/05/19 13:29:21 by jihham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*make_node(char *key, char *value)
{//새로운 환경변수 노드 생성해서 주기 
	t_env	*new;

	if (!key)
		return (NULL); //키가 없으니까 NULL리턴
	new = (t_env *)malloc(sizeof(t_env)); //환경변수 노드 그릇만들기위해 메모리 할당
	if (!new)
		return (NULL);//널가드
	new->key = key; //받아온 키 넣기
	new->value = value; //받아온 값 넣기
	new->next = NULL; // 다음없으니까 널
	return (new);//노드 돌려주기 
}

t_env	*get_last_node(t_env *head)
{//마지막 노드 찾기 
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}
