/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseong <hyseong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:18:34 by hyseong           #+#    #+#             */
/*   Updated: 2023/07/21 17:18:34 by hyseong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exit_with_print(int n)
{
	ft_printf(1, "exit\n");
	exit(n);
}

int	ft_exit(char **args)
{
	int	i;

	if (!args || !*args)
		exit_with_print(0);
	i = is_ignore_first_arg(args[0]);
	if (i && !args[1])
		exit_with_print(0);
	if (is_num(args[i]))
	{
		if (args[i + 1] && ft_printf(2, \
		"exit\nminishell: exit: too many arguments\n"))
			return (1);
		else
			exit_with_print((unsigned char)ft_atoi(args[i]));
	}
	else
	{
		ft_printf(2, "exit\nminishell: exit: %s: numeric argument required\n", \
		args[i]);
		exit(255);
	}
	return (0);
}
