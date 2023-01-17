/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:26:45 by jsunwoo           #+#    #+#             */
/*   Updated: 2022/11/30 16:54:47 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*headlst;
	t_list	*newlst;
	void	*new_content;

	if (!f || !del)
		return (NULL);
	headlst = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		newlst = ft_lstnew(new_content);
		if (newlst == NULL)
		{
			del(new_content);
			ft_lstclear(&headlst, del);
			return (NULL);
		}
		ft_lstadd_back(&headlst, newlst);
		lst = lst->next;
	}
	return (headlst);
}
