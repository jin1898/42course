/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_convert_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseong <hyseong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:17:42 by hyseong           #+#    #+#             */
/*   Updated: 2023/07/21 17:17:43 by hyseong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_exist_oldpwd(char *key)
{
	if (!ft_strncmp(key, "OLDPWD", 7))
		return (1);
	return (0);
}

int	check_shlvl(t_env *env)
{
	char	*new_value;

	if (!ft_strncmp(env->key, "SHLVL", 6))
	{
		if (env->value && is_unsigned_num(env->value) ^ is_num(env->value))
			new_value = ft_itoa(0);
		else if (!env->value || !is_num(env->value))
			new_value = ft_itoa(1);
		else
			new_value = ft_itoa(ft_atoi(env->value) + 1);
		if (env->value)
			free(env->value);
		env->value = new_value;
		return (1);
	}
	return (0);
}
