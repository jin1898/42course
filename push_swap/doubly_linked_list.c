/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:07:01 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/03/03 12:51:09 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*add_tail_dlinke(t_stack *head, int number, int name)
{
	t_stack	*point;
	t_stack	*new;

	point = head;
	if (!head)
	{
		free(head);
		return (NULL);
	}
	new = malloc(sizeof(t_stack));
	new->number = number;
	new->name = name;
	new->totalsize = 0;
	if (head->name == -1)
		head->totalsize += 1;
	while (point->next)
		point = point->next;
	new->prev = point;
	new->next = NULL;
	point->next = new;
	return (head);
}

void	del_all_dlinke(t_stack **head)
{
	t_stack	*temp;

	temp = *head;
	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
}

t_stack	*get_linke(int name)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->name = name;
	new->next = NULL;
	new->prev = NULL;
	new->number = 0;
	new->totalsize = 0;
	return (new);
}
