/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_factory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:21:51 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/03/02 13:29:46 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack **head, t_stack *head2)
{ // 9 1 2
	t_stack	*p;

	p = (*head)->next;
	if (sorted(*head) && (head2)->next->next == NULL)
		return ;
	if (*((*head)->next == ((*head)->totalsize) - 1)
		rotate(head);
	else if (*(*head)->next->name == ((*head)->totalsize) - 1)
		reverse_rotate(head);
	if ((*head)->name > (*head)->next->name)
		swap(head);
	printf("sort3으로 들어왔음!\n");
}

void	sort2(t_stack **head)
{
	t_stack	*p;

	p = (*head)->next;
	if (p->name > p->next->name)
		swap(head);
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
