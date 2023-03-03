/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_factory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:21:51 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/03/03 12:51:54 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack **head, t_stack *head2)
{
	t_stack	*p;

	p = (*head)->next;
	if (sorted(*head) && (head2)->next == NULL)
		return ;
	if ((*head)->next->name == ((*head)->totalsize) - 1)
		rotate(head);
	else if ((*head)->next->next->name == ((*head)->totalsize) - 1)
		reverse_rotate(head);
	if ((*head)->next->name > (*head)->next->next->name)
		swap(head);
}

void	sort2(t_stack **head, int i)
{
	t_stack	*p;

	p = (*head)->next;
	if (i != 1 && p->name > p->next->name)
		swap(head);
	if (i == 1 && p->name < p->next->name)
		swap(head);
}

int	sorted(t_stack *head)
{
	head = head->next;
	while (head->next)
	{
		if (!(head->number < head->next->number))
			return (0);
		head = head->next;
	}
	write(1, "\n", 1);
	return (1);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
