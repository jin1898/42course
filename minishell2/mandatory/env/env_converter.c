/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihham <jihham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:25:51 by jihham            #+#    #+#             */
/*   Updated: 2023/05/19 10:25:51 by jihham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	make_env_arr(t_env *temp, char **envp, int *i)
{
	char	*env;
	char	*env2;

	env = ft_strjoin(temp->key, "=");
	env2 = ft_strjoin(env, temp->value);
	free(env);
	envp[(*i)++] = env2;
	return (1);
}

char	**env_list_to_arr(t_env_manager *env_manager)
{
	char	**envp;
	t_env	*temp;
	int		i;

	envp = (char **)malloc(sizeof(char *) * (env_manager->size + 1));
	if (!envp)
		return (NULL);
	temp = env_manager->head;
	i = 0;
	while (temp)
	{
		if (!make_env_arr(temp, envp, &i))
			return (NULL);
		temp = temp->next;
	}
	envp[i] = NULL;
	return (envp);
}

int	env_arr_to_list(t_env_manager *env_manager, char **envp)
{// 환경 변수 배열을 환경 변수 링크드 리스트로 변환하여 관리한다. 주어진 환경 변수 배열을 순회하면서 각 환경 변수를 make_env 함수를 통해 Env 구조체로 변환한다. 이후, 생성된 Env 구조체를 환경 변수 링크드 리스트에 추가한다. 동시에 "OLDPWD"와 "SHLVL" 환경 변수의 존재 여부를 확인하고, 없는 경우에는 해당 환경 변수를 링크드 리스트에 추가한다. 이를 통해 초기 설정되지 않은 환경 변수들을 추가 및 관리한다.
	int		i;
	int		exist_oldpwd;
	int		exist_shlvl;
	t_env	*new_env;

	i = -1;
	exist_oldpwd = 0;
	exist_shlvl = 0;
	while (envp[++i])//환경변수 배열 순회
	{
		new_env = make_env(envp[i]);  // 각 환경 변수를 Env 구조체로 변환(그냥 환경변수 저장하기 좋은 구조체로 변경)
		if (!new_env && !free_env(env_manager))// Env 구조체 생성 실패 시 이전에 할당된 Env 구조체들을 해제하고 종료
			return (1);
		exist_oldpwd |= is_exist_oldpwd(new_env->key);// "OLDPWD" 환경 변수의 존재 여부 확인
		exist_shlvl |= check_shlvl(new_env);// "SHLVL" 환경 변수의 존재 및 값 검사
		add_env(env_manager, new_env);
	}
	if (!exist_oldpwd) // "OLDPWD" 환경 변수가 없는 경우
		add_env(env_manager, make_env("OLDPWD")); // "OLDPWD" 환경 변수 추가
	if (!exist_shlvl)// "SHLVL" 환경 변수가 없는 경우
		add_env(env_manager, make_env("SHLVL=1"));// "SHLVL" 환경 변수 추가 (값은 1로 설정)
	return (0);
	/*
	함수공부 
	SHLVL은 환경 변수(environment variable)로, 쉘 세션의 중첩 수준(nesting level)을 나타냅니다. 쉘 세션이 시작될 때마다 SHLVL 값은 1씩 증가합니다. 이 값은 쉘 세션 내에서 현재 쉘 세션의 중첩 깊이를 추적하는 데 사용됩니다.

	위의 코드에서 check_shlvl 함수는 주어진 환경 변수 env가 SHLVL인지 확인하고, 해당 변수의 값을 조정하는 역할을 수행합니다. 만약 env의 키(key)가 "SHLVL"과 일치한다면, 다음과 같은 동작을 수행합니다:
	
	env의 값(value)이 존재하고, 이 값이 부호 없는 숫자가 아니거나 음수인 경우: SHLVL 값을 0으로 설정합니다.
	env의 값이 존재하지 않거나 부호 없는 숫자가 아닌 경우: SHLVL 값을 1로 설정합니다.
	그렇지 않은 경우: env의 값에 1을 더한 값을 SHLVL로 설정합니다.
	이렇게 check_shlvl 함수는 SHLVL 값을 확인하고 조정하여 쉘 세션의 중첩 깊이를 유지합니다.
	*/
}
