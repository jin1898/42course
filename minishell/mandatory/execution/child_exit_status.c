/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_exit_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseong <hyseong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:17:24 by hyseong           #+#    #+#             */
/*   Updated: 2023/07/21 17:17:26 by hyseong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

int	check_exit_status(int child_status, int *signum)
{
	*signum = 0;
	if (WIFSIGNALED(child_status))
	{
		*signum = WTERMSIG(child_status);
		g_exit_status = 128 + WTERMSIG(child_status);
	}
	else
		g_exit_status = WEXITSTATUS(child_status);
	return (0);
}
