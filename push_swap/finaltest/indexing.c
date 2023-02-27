/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:10:47 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/02/28 02:10:39 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*indexing1(t_stack **head)
{
	int		*a;
	int		z;
	t_stack	*p;

	p = *head;
	z = -1;
	a = malloc(sizeof(t_stack) * ((*head)->totalsize));
	if (!a)
		return (NULL);
	while (z++ < (*head)->totalsize && p->next)
	{
		p = p->next;
		a[z] = p->number;
	}
	indexing2(head, a);
	indexing3(head, a);
	free(a);
	return (a);
}

void	*indexing2(t_stack **head, int *a)
{
	int	z;
	int	i;
	int	temp;

	z = 0;
	i = 0;
	while (z < (*head)->totalsize)
	{
		while (i < (((*head)->totalsize) - 1))
		{
			if (a[i] > a[i + 1])
			{
				temp = a[i];
					a[i] = a[i + 1];
					a[i + 1] = temp;
			}
			i++;
		}
		z++;
	}
	return (0);
}

void	*indexing3(t_stack **head, int *a)
{
	int		z;
	t_stack	*p;

	z = 0;
	p = *head;
	while (z < (*head)->totalsize)
	{	
		p = (*head)->next;
		while (p)
		{
			if (a[z] == p->number)
			{
				p->name = z;
				z++;
			}
			p = p->next;
		}
	}
	return (0);
}
