/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseong <hyseong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:46:12 by hyseong           #+#    #+#             */
/*   Updated: 2022/11/26 23:46:13 by hyseong          ###   ########.fr       */
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
