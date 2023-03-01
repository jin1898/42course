/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:55:23 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/03/01 12:42:14 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **head)
{
	t_stack	*p0;
	t_stack	*p1;
	t_stack	*p2;

	if ((*head)->next && (*head)->next->next)
	{
		p0 = (*head)->next;
		p1 = (*head)->next->next;
		printf("--p0.name:%d p0.name:%d--\n",p0->name,p0->number);
		printf("--p1.name:%d p1.number:%d--\n",p1->name,p1->number);
		if ((*head)->next->next->next)
			p2 = (*head)->next->next->next;
		else
			p2 = 0;
		p0->prev = p1;
		p0->next = p2;
		p1->prev = (*head);
		p1->next = p0;
		if (p2)
			p2->prev = p0;
		for (t_stack *print = *head; print!= 0; print = print->next)//지워야함!!
			printf("[name:%d number:%d >> ",print->name, print->number);
		printf("]\n");// 지워야함!!!!!!!!!!!
	}
	else//지워야함!!!!!!!!!!
		printf("fail swap\n"); //지워야함!!!!!!!!!!!
	if ((*head)->name == -1)
		write(1, "sa\n", 3);
	else if ((*head)->name == -2)
		write(1, "sb\n", 3);
}

void	push(t_stack **in, t_stack **out)
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
	if ((*in)->name == -1)
		write(1, "pa\n", 3);
	else if ((*in)->name == -2)
		write(1, "pb\n", 3);
}

void	reverse_rotate(t_stack **head)
{
	t_stack	*p0;
	t_stack	*pl;
	t_stack	*plp;

	pl = (*head);
	p0 = (*head)->next;
	if ((*head)->next && (*head)->next->next)
	{
		while (pl->next)
			pl = pl->next;
		plp = pl->prev;
		(*head)->next = pl;
		pl->prev = (*head);
		pl->next = p0;
		p0->prev = pl;
		plp->next = NULL;
	}
	else
		printf("fail reverse_rotate\n");
	if ((*head)->name == -1)
		write(1, "rra\n", 4);
	else if ((*head)->name == -2)
		write(1, "rrb\n", 4);
}

void	rotate(t_stack **head)
{
	t_stack	*p0;
	t_stack	*p1;
	t_stack	*pl;

	pl = (*head);
	p0 = (*head)->next;
	p1 = (*head)->next->next;
	if ((*head)->next && (*head)->next->next)
	{
		while (pl->next)
			pl = pl->next;
		(*head)->next = p1;
		pl->next = p0;
		p1->prev = (*head);
		p0->prev = pl;
		p0->next = NULL;
	}
	else
		printf("fail rotate\n");
	if ((*head)->name == -1)
		write(1, "ra\n", 3);
	else if ((*head)->name == -2)
		write(1, "rb\n", 3);
}
