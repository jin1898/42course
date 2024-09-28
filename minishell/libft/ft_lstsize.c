/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseong <hyseong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:47:44 by hyseong           #+#    #+#             */
/*   Updated: 2022/11/26 22:47:50 by hyseong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	cnt;

	if (lst == 0)
		return (0);
	cnt = 1;
	while (lst->next)
	{
		lst = lst->next;
		cnt++;
	}
	return (cnt);
}
