/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihham <jihham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 23:29:42 by marvin            #+#    #+#             */
/*   Updated: 2023/05/22 16:09:01 by jihham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	swap_pwd(char *old_pwd_path, char *pwd_path, \
t_env *old_pwd, t_env *pwd)
{ // `old_pwd`와 `pwd`의 값을 교환하는 함수
	char	*temp;

	temp = old_pwd_path;
	old_pwd_path = pwd_path;
	pwd_path = temp; // 임시 변수 `temp`를 사용하여 `old_pwd_path`와 `pwd_path` 값을 교환

	old_pwd->value = old_pwd_path;// `old_pwd`와 `pwd`의 값을 교환된 값으로 업데이트한다.
	pwd->value = pwd_path;
	return (ft_pwd()); // 현재 디렉토리 경로 출력
}

static int	ft_cd_oldpwd(t_env_manager *env)
{ // cd명령어 처리하는 함수 (경로/"-")를 처리한다.
	t_env	*old_pwd;
	t_env	*pwd;
	char	*pwd_path;
	char	*old_pwd_path;

	old_pwd = get_env(env->head, "OLDPWD"); // 환경변수에서 "OLDPWD"값 가져와
	if ((!old_pwd || !old_pwd->value) && \
	ft_printf(2, "minishell: cd: OLDPWD not set\n")) // "OLDPWD"가 설정되지 않았거나 값이 없을 경우 에러 출력 후 1 반환
		return (1);
	pwd = get_env(env->head, "PWD"); // 환경변수에서 PWD값가져온다.
	if (!pwd)
		return (0); //PWD가 설정되지 않을 경우 0을 반환한다.
	old_pwd_path = old_pwd->value; //35번에서 가져온 old_pwd의 값을 저장
	pwd_path = pwd->value; // 39번에서 가져온 pwd값을 저장
	if (chdir(old_pwd_path))//프로세스의 현재 작업 디렉토리가 해당 경로로 변경되는함수
		return (ft_perror_join("minishell: cd: ", old_pwd_path)); //OLDPWD의 경로로 디렉토리를 변경한다.
	return (swap_pwd(old_pwd_path, pwd_path, old_pwd, pwd)); //OLDPWD와 PWD의 값을 서로 교환한다. (chdir 함수가 성공적으로 실행되고 이전 작업 디렉토리로 이동한 경우에 실행)
}

static int	move_to_home(t_env_manager *env_manager)
{//HOME환경변수에 적힌 위치로 이동하는 함수 /현재 작업 디렉토리랑 환경변수 변경하고 이동
	t_env	*env;
	char	*current_path;

	env = get_env(env_manager->head, "HOME"); //HOME이라는 환경 변수 찾아서 가져오기
	if (!env && ft_printf(2, "minishell: cd: HOME not set\n")) // HOME 환경변수가 없을시
		return (1); // 1반환 종료시키기
	current_path = getcwd(NULL, 0); //현재 작업디렉토리의 경로 가져옴
	if (chdir(env->value))//HOME디렉토리로 위치 변경 
		return (ft_perror_join("minishell: cd: ", env->value)); // 변경실패시 에러메세지 출력후 1반환
	change_env_value(env_manager, "OLDPWD", current_path);//OLDPWD 환경변수를 현재작업 디렉토리로 변경
	if (current_path) // 현재작업 디렉토리 경로가 존재할시
		free(current_path); // free
	change_env_value(env_manager, "PWD", getcwd(NULL, 0)); //PWD환경변수를 현재 작업 디렉토리로 변경해주기!
	return (0);
}

static	int	pwd_check(char *args, t_env_manager *env_manager)
{//주어진 경로로 디렉토리를 변경하고 이전 작업 디렉토리와 현재 작업 디렉토리의 경로를 관련된 환경 변수에 업데이트한다.
	char	*current_path;

	if (access(args, F_OK)) //args를 경로가 존재하지 않으면 
		return (ft_perror_join("minishell: cd: ", args));//에러메세지를 경로와 함께 출력한다.
	current_path = getcwd(NULL, 0); //현재 작업 디렉토리 경로 가져오기 
	if (chdir(args))// 주어진 경로로 디렉토리 변경
		return (ft_perror_join("minishell: cd: ", args));//변경실패시 해당경로 사용해서 에러메세지 출력 
	change_env_value(env_manager, "OLDPWD", current_path); //환경변수 업데이트(OLDPWD 환경변수에 이전 작업 디렉토리의 경로를 업데이트)
	if (current_path)//해당변수가 할당되어있으면 
		free(current_path); //free해주기
	change_env_value(env_manager, "PWD", args);//PWDkey의 환경변값을 현재 작업 디렉토리 경로를 업데이트
	return (0);
}

int	ft_cd(char **args, t_env_manager *env_manager)
{//cd함수 구현
	int		i;

	if (!args || !args[0]) //args가 널이든 첫번째 요소가 없을시 
		return (move_to_home(env_manager)); //홈디렉토리로 이동
	i = is_ignore_first_arg(args[0]); //ignore(첫번쨰 인수 무시해야하는지 확인해야하는함수)함수에서인게스 얻기 
	if (!args[i]) // args[i]가 없다면
		return (move_to_home(env_manager)); //(홈디렉토리로이동함수)를 호출해서 결과 반환
	else if (ft_strncmp(args[i], "-", 2) == 0) //args[i]가 "-"로 시작할시
		return (ft_cd_oldpwd(env_manager)); //이전 디렉토리로 이동하는 함수 실행후 결과 반환
	return (pwd_check(args[i], env_manager)); //"-"가 아닐경우 args[i]의 경로로 디렉토리 변경하기
}
