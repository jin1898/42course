/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihham <jihham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:05:46 by jihham            #+#    #+#             */
/*   Updated: 2022/11/16 11:03:39 by jihham           ###   ########.fr       */
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
