/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_factory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:21:51 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/02/28 00:32:11 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack **head)
{
	t_stack	*p;

	p = (*head)->next;
	if (sorted(*head))
		return ;
	if (p->name == ((*head)->totalsize) - 1)
		ra(head);
	else if (p->next->name == ((*head)->totalsize) - 1)
		rra(head);
	if (p->name > p->next->name)
		sa(head);
	printf("sort3으로 들어왔음!\n");
}

void	sort2(t_stack **head)
{
	t_stack	*p;

	p = (*head)->next;
	if (p->name > p->next->name)
		sa(head);
}

int	sorted(t_stack *head)
{
	head = head->next;
	printf("sorted들어왔음!\n");
	while (head->next)
	{
		if (!(head->number < head->next->number))
			return (0);
		head = head->next;
	}
	write(1, "\n", 1);
	exit(1);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
