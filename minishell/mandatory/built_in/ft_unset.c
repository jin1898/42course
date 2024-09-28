/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseong <hyseong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:18:48 by hyseong           #+#    #+#             */
/*   Updated: 2023/07/21 17:18:48 by hyseong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(char **args, t_env_manager *env_manager)
{
	int	i;
	int	error;
	int	current_error;

	error = 0;
	if (!args || !*args)
		return (error);
	i = is_ignore_first_arg(args[0]) - 1;
	while (args[++i])
	{
		current_error = !is_valid_env_key(args[i]);
		error |= current_error;
		if (current_error \
		&& ft_printf(2, "minishell: unset: %s: not a valid identifier\n", \
		args[i]))
			continue ;
		delete_env(env_manager, args[i]);
	}
	return (error);
}
