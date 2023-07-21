/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseong <hyseong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:18:29 by hyseong           #+#    #+#             */
/*   Updated: 2023/07/21 17:18:29 by hyseong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_env_manager *env_manager)
{
	t_env	*temp;

	temp = env_manager->head;
	while (temp)
	{
		if (temp->value)
			ft_printf(1, "%s=%s\n", temp->key, temp->value);
		temp = temp->next;
	}
	return (0);
}
