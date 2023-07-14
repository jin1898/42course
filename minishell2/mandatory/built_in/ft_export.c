/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihham <jihham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:28:24 by jihham            #+#    #+#             */
/*   Updated: 2023/05/15 16:30:34 by jihham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_env(t_env_manager *env_manager)
{//환경변수를 출력하는 함수
	t_env	*temp;

	if (!env_manager || !env_manager->head)// env_manager가 NULL이거나 head가 NULL인 경우
		return (0);// 0리턴
	temp = env_manager->head; //순회 용도 변수
	while (temp)
	{
		if (temp->value)// 현재 환경 변수의 값이 있는 경우
			ft_printf(1, "%s=\"%s\"\n", temp->key, temp->value);// 키와 값을 큰따옴표로 둘러싸고 출력한다.
		else // 환경변수의 값이 없을시
			ft_printf(1, "%s\n", temp->key); //키만 출력한다.
		temp = temp->next;//다음 환경변수로 이동
	}
	return (0);
}

static int	export_to_change(t_env_manager *env_manager, char *arg)
{//arg라는 주어진 환경 변수를 변경하는 함수 
	t_env	*env_node;
	char	*key;
	char	*value;

	key = NULL;
	value = NULL;
	if (get_key_value(arg, &key, &value))// 인수로 전달된 arg에서 키와 값을 추출한다.-> 'a="1234"' key=a value=1234
		return (0);
	env_node = get_env(env_manager->head, key);// env_manager에서 키에 해당하는 환경 변수를 찾아 env_node에 할당 -> a인 환경변수 찾아서 내용바꿀려는거임!
	if (!env_node)// env_node가 비어있을경우
	{
		if (key)
			free(key); //free
		if (value)
			free(value);//free
		return (0);
	}
	if (env_node->value)//값있다면
		free(env_node->value);// 기존 환경 변수의 값을 해제
	if (key)//키있을시
		free(key);//키해제!
	env_node->value = value;//새로운 환경변수를 넣어주기
	return (1);
}

static int	export_to_add(t_env_manager *env_manager, char *arg, int *error)
{//arg 환경 변수를 추가하는 함수
	t_env	*env_node;
	int		current_error;

	env_node = make_env(arg);// 주어진 문자열부터 키랑값을 구한다음에 노드로 만들어서 돌려주는 함수
	if (!env_node) // 환경변수 노드 생성에 실패시
		return (1); // 리턴 1
	current_error = !is_valid_env_key(env_node->key);// 해당인자값이 환경변수에 있는 값인지 확인한다.
	*error |= current_error; // *error변수와 current_error변수간에 비트 or연산을 수행하고 결과 *error에 저장
	if (current_error && free_node(&env_node) \
	&& ft_printf(2, "minishell: export: %s: not a valid identifier\n", arg))
		return (1); // 에러가 발생할시 에러 메세지를 출력후 1반환 
	add_env(env_manager, env_node);// 환경변수 추가하기 
	return (1);
}

int	ft_export(char **args, t_env_manager *env_manager) //*****여기잘모르겠ㄷ
{// 환경변수를 설정하거나 추가하는 함수
	int		i;
	int		error;

	if (!args || !*args) //NULL이거나 첫번째 인수가 없는 경우 
		return (print_env(env_manager));//현재 환경변수 전체다 출력
	i = is_ignore_first_arg(args[0]) - 1;//*****첫 번째 인수가 무시될 경우의 인덱스를 구하고 1을 뺀 값을 i에 저장합니다.

	if (i > -1 && !args[1])// 무시될 경우의 인덱스가 0보다 크고 두 번째 인수가 없는 경우
		return (print_env(env_manager));//현재 환경 변수를 출력하고 0을 반환
	error = 0;
	while (args[++i])
	{
		if (export_to_change(env_manager, args[i]) \
		|| export_to_add(env_manager, args[i], &error))//change함수에서 환경변수를 변경하거나 , add함수에서 환경변수 추가하기
			continue ;//둘다 참일시 계속 실행 ->근데 보니까 change에서만 0리턴 1리턴있는거 보니 환경변수 change할꺼없으면 끝날것같다.
	}
	return (error);
}
