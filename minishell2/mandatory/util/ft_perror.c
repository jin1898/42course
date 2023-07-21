/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseong <hyseong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:15:21 by hyseong           #+#    #+#             */
/*   Updated: 2023/07/21 17:15:23 by hyseong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_perror_join(char *prefix, char *postfix)
{
	char	*temp;

	if (!prefix || !postfix)
		return (1 & \
			ft_printf(2, "ft_prerror_join error [%s] [%s]\n", prefix, postfix));
	temp = ft_strjoin(prefix, postfix);
	perror(temp);
	free(temp);
	return (1);
}

int	ft_perror(char *cause)
{
	if (!cause)
		perror("minishell");
	else
		perror(cause);
	return (1);
}
