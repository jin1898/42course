/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:08:41 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/03/01 11:45:34 by sunwoo-jin       ###   ########.fr       */
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
	while (p->next)
	{
		if (pib > p->name)
			push(head2, head);
		else if ((pib + chunk) > (p->name))
		{
			push(head2, head);
			rotate(head2);
		}
		else if ((pib + chunk) < (p->name))
			rotate(head);
		pib++;
		p = p->next;
	}
	sandbtoa(head, head2);
}

void	sandbtoa(t_stack **head, t_stack **head2)
{
	int	pb;
	int	i;

	pb = ((*head)->totalsize) / 2;
	i = 0;
	while (i < ((*head)->totalsize))
	{
		if (pb > i)
		{
			while ((*head)->name != i)
				rotate(head2);
			push(head, head2);
		}
		else
		{
			while ((*head)->name != i)
				reverse_rotate(head2);
			push(head, head2);
		}
		i++;
	}
}
