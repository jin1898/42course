/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseong <hyseong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:18:25 by hyseong           #+#    #+#             */
/*   Updated: 2023/07/21 17:18:25 by hyseong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_echo(char **args, int i)
{
	if (!args[i])
		ft_printf(1, "");
	else
		ft_printf(1, "%s", args[i]);
	if (args[i] && args[i + 1])
		ft_printf(1, " ");
}

static int	check_option(char *str)
{
	int	i;

	if (!str || str[0] != '-' || (str[0] == '-' && !str[1]))
		return (0);
	i = 0;
	while (str[++i])
		if (str[i] != 'n')
			return (0);
	return (1);
}

int	ft_echo(char **args)
{
	int	i;
	int	is_set_option;

	i = 0;
	is_set_option = check_option(args[0]);
	if (is_set_option)
		while (args[++i] && check_option(args[i]))
			;
	while (args[i])
		print_echo(args, i++);
	if (!is_set_option)
		ft_printf(1, "\n");
	return (0);
}
