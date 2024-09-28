/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseong <hyseong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:15:16 by hyseong           #+#    #+#             */
/*   Updated: 2023/07/21 17:15:18 by hyseong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_unsigned_num(char *arg)
{
	int	i;

	if (!arg || !*arg)
		return (0);
	i = 0;
	if (arg[0] == '+')
		i++;
	while (arg[i])
		if (!ft_isdigit(arg[i++]))
			return (0);
	return (1);
}

int	is_num(char *arg)
{
	int	i;

	if (!arg || !*arg)
		return (0);
	i = 0;
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	while (arg[i])
		if (!ft_isdigit(arg[i++]))
			return (0);
	return (1);
}
