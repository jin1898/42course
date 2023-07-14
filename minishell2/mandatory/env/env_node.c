/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihham <jihham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:36:04 by jihham            #+#    #+#             */
/*   Updated: 2023/05/19 13:08:51 by jihham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*make_env(char *arg)
{//문자열을 파씽해서 키와 값을 구한다음에 그걸로 환경변수 노드 생성하는 함수
	char	*key;
	char	*value;

	if (get_key_value(arg, &key, &value)) // 키와값을 추출한다.
		return (NULL);// 실패시 NULL을 출력
	return (make_node(key, value)); //환경변수 노드 생성해서 돌려주기
}

int	add_env(t_env_manager *env_manager, t_env *new_env)
{ //new_node를 환경변수 목록에 추가하는 함수 
	t_env	*last_node; // 환경변수 목록의 마지막 노드 가리키는 포인터 

	if (!new_env)// 추가할 환경 변수 노드가 NULL인 경우
		return (1);// 에러를 나타내기 위해 1을 반환합니다.
	if (!env_manager->head)// 환경 변수 목록이 비어있는 경우
		env_manager->head = new_env;// 새로운 환경 변수를 목록의 첫 번째로 설정한다.
	else
	{
		last_node = get_last_node(env_manager->head);// 현재 목록의 마지막 노드를 찾습니다.
		last_node->next = new_env;// 마지막 노드의 다음 노드로 새로운 환경 변수를 추가
	}
	(env_manager->size)++;// 환경 변수 목록의 크기를 1 증가시킵니다.
	return (0);
}

int	delete_env(t_env_manager *env_manager, char *key)
{//환경변수에서 key를 찾아서 제거한다.
	t_env	*prev_node;
	t_env	*temp;

	prev_node = NULL;
	temp = env_manager->head;
	while (temp) //환경변수리스트 돌아가면서 제거할 환경 변수(key) 찾기
	{
		if (ft_strncmp(temp->key, key, ft_strlen(key) + 1) == 0) //제거할 환경변수를 찾았을시
		{
			if (temp == env_manager->head) // 제거할 환경 변수가 리스트의 첫번째 노드라면 
				env_manager->head = temp->next; // 헤드 포인터를 다음노드로 넘겨주기 
			else
				prev_node->next = temp->next; // 이전 노드의 다음 노드를 현재 노드의 다음 노드로 연결
			free_node(&temp);//환경변수 노드 해제 
			break ;
		}
		prev_node = temp; // 이전노드를 현재 노드로 바꾸기 
		temp = temp->next;// 다음노드로 이동 
	}
	(env_manager->size)--; // 환경 변수갯수 감소시키기
	return (0);
}

t_env	*get_env(t_env *env, char *key)
{//env(환경변수)에서 key라는 문자열이 있나 찾는 함수 
	t_env	*temp;

	temp = env; //env 변수 순회용도
	while (temp)
	{
		if (ft_strncmp(temp->key, key, ft_strlen(key) + 1) == 0) // key랑 현재env랑 같은지 비교
			return (temp);//일치시 환경 변수 찾으면 해당 환경 변수 반환
		temp = temp->next;//다음 환경변수로 이동
	}
	return (NULL);
}

int	change_env_value(t_env_manager *env_manager, char *key, char *value)
{//환경변수에 key랑 똑같은 환경변수의 값을 value로 변경해주는 함수
	t_env	*env;

	env = get_env(env_manager->head, key);//key랑 같은 환경변수 찾기
	if (!env) //환경변수 못찾을시
		return (1); //1을 반환 실행중지
	if (env->value)//환경변수 있을시
		free(env->value);//기존 할당된 환경 변수 값이 있으면 메모리 해제
	if (value == NULL)//변경해야할 값이 NULL일경우 
		env->value = NULL; //환경 변수의 값을 NULL로 주기 
	else
		env->value = ft_strdup(value);// value에 값이 있을시 그걸로 복제해서 넣어주기
	return (0);
}
