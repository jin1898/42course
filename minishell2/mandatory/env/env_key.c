/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihham <jihham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:36:34 by jihham            #+#    #+#             */
/*   Updated: 2023/05/19 12:57:49 by jihham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_key_value(char *arg, char **key, char **value)
{//주어진 문자열에서 키(key)와 값을(value) 추출한다.
	char	*equal_pos;
	int		equal_len;

	equal_pos = ft_strchr(arg, '=');// 문자열 arg에서 '=' 문자의 위치를 찾는다.
	if (!equal_pos)// '=' 문자가 존재하지 않는 경우
	{
		*key = ft_strdup(arg);// key에 arg를 가져온다.
		*value = NULL;
		return (0);
	}
	equal_len = equal_pos - arg;// '=' 문자의 위치까지의 길이를 계산합니다.
	*key = ft_substr(arg, 0, equal_len);// arg의 시작부터 '=' 문자 직전까지를 key에 할당합니다.
	if (!*key)// 할당 중 오류가 발생!
		return (1);//1반환시켜버리기
	*value = ft_substr(arg, equal_len + 1, \
	ft_strlen(arg) - (equal_len + 1));// '=' 문자 이후부터 문자열의 끝까지를 value에 할당합니다.
	if (!*value)// 할당 중 오류가 발생한 경우
	{
		free(*key);// key free
		return (1);
	}
	return (0);
}

int	is_valid_env_key(char *key)
{//key가 환경변수에 있는 key인지 확인하는 역할이다.
	int	i;

	if (!key)// 키가 없다는 뜻이기 때문에 
		return (0); //에러리턴
	i = 0;
	if (!ft_isalpha(key[i]) && key[i] != '_') //// 환경변수의 이름의 규칙의 경우 첫 번째 문자가 알파벳이나 '_'가 아닌 경우 이름 자체가 성립하지 않기에 이외것들은 모두 0을 반환
		return (0);
	while (key[++i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')// 환경변수 이름 규칙에 따라서 key[i]가 (알파벳,숫자,_)가 아닐경우
			return (0);//에러리턴
	}
	return (1);// 성공적임을 리턴 
}
