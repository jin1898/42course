/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:55:23 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/02/28 17:23:34 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **a, int i)
{
	t_stack	*p0;
	t_stack	*p1;
	t_stack	*p2;

	if ((*a)->next && (*a)->next->next)
	{
		p0 = (*a)->next;
		p1 = (*a)->next->next;
		if ((*a)->next->next->next)
			p2 = (*a)->next->next->next;
		else
			p2 = 0;

		(*a)->next = p1;
		p1->prev = (*a);
		p1->next = p0;
		p0->prev = p1;
		p0->next = p2;
		p2->prev = p0;
	}
	else//지워야함!!!!!!!!!!
		printf("fail swap\n"); //지워야함!!!!!!!!!!!
	if (i == -1)
		write(1, "sa\n", 3);
	if (i == -2)
		write(1, "sb\n", 3);
}

void	push(t_stack **in, t_stack **out, int i)
{
	t_stack	*p0;
	t_stack	*p1;
	t_stack	*in0;

	if ((*out)->next)
	{
		p0 = (*out)->next;
		p1 = (*out)->next->next;
		(*out)->next = (*out)->next->next;
		p1->prev = (*out);
		if ((*in)->next)
			in0 = (*in)->next;
		else
			in0 = 0;
		p0->prev = *in;
		p0->next = in0;
		if (in0)
			(in0)->prev = p0;
		(*in)->next = p0;
	}
	else
		printf("fail push\n"); // 지워야해!!!!!!!!!
	if (i == -1)
		write(1, "pa\n", 3);
	if (i == -2)
		write(1, "pb\n", 3);
}

void	reverse_rotate

void	rotate(t_stack **stack)