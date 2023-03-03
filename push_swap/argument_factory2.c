/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_factory2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:59:51 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/03/03 12:52:32 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort4(t_stack **head, t_stack **head2)
{
	find_pushb(0, head, head2);
	sort3(head, *head2);
	push(head, head2);
}

void	sort5(t_stack **head, t_stack **head2)
{
	find_pushb(0, head, head2);
	find_pushb(1, head, head2);
	sort3(head, *head2);
	sort2(head2, 1);
	push(head, head2);
	push(head, head2);
}

void	find_pushb(int a, t_stack **head, t_stack **head2)
{
	int		count;
	t_stack	*p;

	p = (*head)->next;
	count = 0;
	while (p->next)
	{
		if (p->name == a)
			break ;
		p = p->next;
		count++;
	}
	while (p->name != (*head)->next->name)
	{
		if (count > 2)
			reverse_rotate(head);
		else
			rotate(head);
	}
	push(head2, head);
}

void	mainsort(t_stack **head, t_stack **head2)
{
	if ((*head)->totalsize > 5)
	{
		if (!sorted(*head))
			sandatob(head, head2);
	}
	else if ((*head)->totalsize == 5)
	{
		if (!sorted(*head))
			sort5(head, head2);
	}
	else if ((*head)->totalsize == 4)
	{
		if (!sorted(*head))
			sort4(head, head2);
	}
	else if ((*head)->totalsize == 3)
	{
		if (!sorted(*head))
			sort3(head, *head2);
	}
	else if ((*head)->totalsize == 2)
	{
		if (!sorted(*head))
			sort2(head, 0);
	}
}
