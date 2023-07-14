/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:23:11 by jihham            #+#    #+#             */
/*   Updated: 2023/07/13 03:24:07 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

static int	print_prev_dollar(int fd, int *cur_i, char *str)
{
	int	prev_i;//시작지점

	prev_i = *cur_i;
	if (!str || !str[*cur_i]) // 문자열에 아무것도 없다면
		return (1); //리턴
	while (str[*cur_i])
	{
		if (str[*cur_i] == '$') //확장해야할부분을 찾았을시
			break ;//반복문 나가
		(*cur_i)++;
	}
	return (write(fd, str + prev_i, *cur_i - prev_i) && 0); //fd파일에다가 확장되야할 부분만 잘라서 써주기
}

static int	print_env_expand(int fd, int *cur_i, char *str, \
	t_env_manager *env_manager)
{
	int		prev_i;
	char	*env_key;
	t_env	*env;

	prev_i = *cur_i;
	if (!str || !str[*cur_i])
		return (1);
	(*cur_i)++;
	if (!str[*cur_i]) //문자가 널일시 
		return (write(fd, str + prev_i, *cur_i - prev_i) || 1);//fd파일에 시작점부터(str + prev_i) 끝부분까지*cur_i - prev_i 써 
	if (str[(*cur_i)++] == '?')
		return (ft_printf(fd, "%d", g_exit_status) && 0);
	if ((str[*cur_i] != '_' && !ft_isalpha(str[*cur_i])))
		return (write(fd, str + prev_i, *cur_i - prev_i) && 0);
	while (str[++(*cur_i)])
		if (str[*cur_i] != '_' && !ft_isalnum(str[*cur_i]))
			break ;
	env_key = ft_substr(str + prev_i, 1, *cur_i - prev_i - 1);
	env = get_env(env_manager->head, env_key);
	if (!env || !env->value || !*env->value)
		return (ft_free_util((void **)&env_key));
	return (ft_free_util((void **)&env_key) || \
		(write(fd, env->value, ft_strlen(env->value)) && 0));
}

static int	print_with_expand(int fd, char *str, t_env_manager *env_manager)
{//확장해야할 것들을 확장해주는함수 ->$로 들어오거나 , 환경변수 확장된 문자열을 환경 변수 확장시킴
	int		i;

	i = 0;
	while (1)
		if (print_prev_dollar(fd, &i, str) || \
				print_env_expand(fd, &i, str, env_manager))
			return (0);
}

void	heredoc_child_check(char *delimiter, int fd, t_env_manager *env_manager)
{// 히어독 리다이렉션 처리하는 자식프로세스에서 실행되는 코드다. / 입력없을때랑 end문자열 입력할때까지 (end문자열이 아닐시)입력을 출력한다.
	char	*str;

	set_heredoc_signal();// 리다이렉션을 처리하는 동안 사용될 시그널 처리를 설정->ctrl+c입력시  (SIGINT:(ctrl+c:인터럽트시그널/프로그램종료시킴))를 실행시키고 개행 출력하게함/ctrl+\는 무시시킴
	while (fd > 0) // fd가 열려있을시 반복문 수행
	{
		str = readline("> "); // 사용자에게 입력받아 str에 저장
		if (!str)//사용자가 아무것도 입력하지 않았을시 
			exit(0); //종료(0)
		if (!ft_strncmp(str, delimiter, ft_strlen(delimiter) + 1))//사용자가 입력한 값이 delimiter과 일치시(히어독 종료 문자열 입력시) 프로그램 종료 
		{
			ft_free_util((void **)&str); // str변수에 할당된 동적 메모리 해제
			exit(0);
		}
		print_with_expand(fd, str, env_manager);//fd에 str 문자열 쓰기
		ft_putstr_fd("\n", fd); //fd 파일디스크립터에 개행 출력
		ft_free_util((void **)&str); // str free
	}
	exit(1); //프로그램 종료 
}
