/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:08:41 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/03/02 10:30:12 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sandatob(t_stack **head, t_stack **head2)
{
	int		pib;
	int		chunk;
	t_stack	*p;

	printf("[sandatob 적용전 배열상태 ---start---]\n"); // 지워야함
	printf_linke(*head);
	printf_linke(*head2);
	printf("[sandatob완료 적용전 배열상태---end---]\n"); // 지워야함
	p = (*head)->next;
	pib = 0;
	chunk = 0.000000053 * ((*head)->totalsize) * \
	((*head)->totalsize) + 0.03 * ((*head)->totalsize) + 14.5;
	while (p)
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
		p = (*head)->next;
	}
	sandbtoa(head, head2);
}

void	sandbtoa(t_stack **head, t_stack **head2)
{
	int	pb;
	int	i;
	printf("[sandatob 적용전 배열상태 ---start---]\n"); // 지워야함
	printf_linke(*head);
	printf_linke(*head2);
	printf("[sandatob완료 적용전 배열상태---end---]\n"); // 지워야함
	pb = ((*head)->totalsize) / 2;
	i = ((*head)->totalsize) - 1;
	while (i >= 0)
	{
		if (pb > i)
		{
			while ((*head2)->next->name != i)
				rotate(head2);
			push(head, head2);
		}
		else
		{
			while ((*head2)->next->name != i)
				reverse_rotate(head2);
			push(head, head2);
		}
		i--;
	}
}
