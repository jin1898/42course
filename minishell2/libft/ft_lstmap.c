/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihham <jihham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:08:35 by jihham            #+#    #+#             */
/*   Updated: 2022/11/16 10:56:21 by jihham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;
	void	*ret_temp;

	res = 0;
	while (lst)
	{
		ret_temp = f(lst->content);
		if (!ret_temp)
		{
			ft_lstclear(&res, del);
			return (0);
		}
		tmp = ft_lstnew(ret_temp);
		if (!tmp)
		{
			del(ret_temp);
			ft_lstclear(&res, del);
			return (0);
		}
		ft_lstadd_back(&res, tmp);
		lst = lst->next;
	}
	return (res);
}
