/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:08:41 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/03/06 10:58:11 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sandatob(t_stack **head, t_stack **head2)
{
	int		pib;
	int		chunk;
	t_stack	*p;

	p = (*head)->next;
	pib = 0;
	chunk = 0.000000053 * ((*head)->totalsize) * \
	((*head)->totalsize) + 0.03 * ((*head)->totalsize) + 14.5;
	while (p)
	{
		if (pib > p->name)
			sandatob_pib1(&pib, head, head2);
		else if ((pib + chunk) >= (p->name))
		{
			push(head2, head);
			rotate(head2);
			pib++;
		}
		else
			rotate(head);
		p = (*head)->next;
	}
	sandbtoa(head, head2);
}

void	sandatob_pib1(int *pib, t_stack **head, t_stack **head2)
{
	push(head2, head);
	*pib += 1;
}

void	sandbtoa(t_stack **head, t_stack **head2)
{
	t_stack	*head2_find;
	int		i;
	int		count;

	i = (*head)->totalsize -1;
	count = 0;
	while (i >= 0)
	{
		head2_find = *head2;
		count = 0;
		while (i != head2_find->name)
		{
			head2_find = head2_find->next;
			count++;
		}
		sandbtoa2(head, head2, &i, &count);
		i--;
	}
}

void	sandbtoa2(t_stack **head, t_stack **head2, int *i, int *count)
{
	if ((*i / 2) >= *count)
	{
		while ((*head2)->next->name != *i)
			rotate(head2);
		push(head, head2);
	}
	else if ((*i / 2) < *count)
	{
		while ((*head2)->next->name != *i)
			reverse_rotate(head2);
		push(head, head2);
	}
}
