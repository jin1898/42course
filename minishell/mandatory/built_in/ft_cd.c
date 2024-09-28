/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseong <hyseong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:18:20 by hyseong           #+#    #+#             */
/*   Updated: 2023/07/21 17:18:20 by hyseong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	swap_pwd(char *old_pwd_path, char *pwd_path, \
t_env *old_pwd, t_env *pwd)
{
	char	*temp;

	temp = old_pwd_path;
	old_pwd_path = pwd_path;
	pwd_path = temp;
	old_pwd->value = old_pwd_path;
	pwd->value = pwd_path;
	return (ft_pwd());
}

static int	ft_cd_oldpwd(t_env_manager *env)
{
	t_env	*old_pwd;
	t_env	*pwd;
	char	*pwd_path;
	char	*old_pwd_path;

	old_pwd = get_env(env->head, "OLDPWD");
	if ((!old_pwd || !old_pwd->value) && \
	ft_printf(2, "minishell: cd: OLDPWD not set\n"))
		return (1);
	pwd = get_env(env->head, "PWD");
	if (!pwd)
		return (0);
	old_pwd_path = old_pwd->value;
	pwd_path = pwd->value;
	if (chdir(old_pwd_path))
		return (ft_perror_join("minishell: cd: ", old_pwd_path));
	return (swap_pwd(old_pwd_path, pwd_path, old_pwd, pwd));
}

static int	move_to_home(t_env_manager *env_manager)
{
	t_env	*env;
	char	*current_path;

	env = get_env(env_manager->head, "HOME");
	if (!env && ft_printf(2, "minishell: cd: HOME not set\n"))
		return (1);
	current_path = getcwd(NULL, 0);
	if (chdir(env->value))
		return (ft_perror_join("minishell: cd: ", env->value));
	change_env_value(env_manager, "OLDPWD", current_path);
	if (current_path)
		free(current_path);
	change_env_value(env_manager, "PWD", getcwd(NULL, 0));
	return (0);
}

static	int	pwd_check(char *args, t_env_manager *env_manager)
{
	char	*current_path;

	if (access(args, F_OK))
		return (ft_perror_join("minishell: cd: ", args));
	current_path = getcwd(NULL, 0);
	if (chdir(args))
		return (ft_perror_join("minishell: cd: ", args));
	change_env_value(env_manager, "OLDPWD", current_path);
	if (current_path)
		free(current_path);
	change_env_value(env_manager, "PWD", args);
	return (0);
}

int	ft_cd(char **args, t_env_manager *env_manager)
{
	int		i;

	if (!args || !args[0])
		return (move_to_home(env_manager));
	i = is_ignore_first_arg(args[0]);
	if (!args[i])
		return (move_to_home(env_manager));
	else if (ft_strncmp(args[i], "-", 2) == 0)
		return (ft_cd_oldpwd(env_manager));
	return (pwd_check(args[i], env_manager));
}
