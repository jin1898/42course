/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_factory2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:59:51 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/02/28 01:54:36 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort4(t_stack **head, t_stack **head2)
{
	find_pushb(0, head, head2);
	sort3(head);
	printf("sort4!\n");
	printf_linke(*head);
	printf_linke(*head2);
	printf("sort4!\n");
}

void	sort5(t_stack **head, t_stack **head2)
{
	find_pushb(0, head, head2);
	find_pushb(1, head, head2);
	sort3(head);
	printf("sort5\n");
	printf_linke(*head);
	printf_linke(*head2);
	printf("sort5\n");
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
			rra(head);
		else
			ra(head);
	}
	pb(head, head2);
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
			sort4(head, head2);
	}
	else if ((*head)->totalsize == 2)
	{
		if (!sorted(*head))
			sort4(head, head2);
	}
}
// mainsort 이상함 total이 3인데 4를 들어가지 않나.. 결과적으로도 출력상 정렬이 안되어있다.
// b->a 로 되돌리는 식도 만들어야한다.