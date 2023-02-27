/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_factory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:56:02 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/02/27 17:51:35 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **head, t_stack **head2)
{
	int		a[(*head)->totalsize];
	int		z;
	t_stack	*p;
	int		temp;

	p = *head;
	z = -1;
	while (z++ < (*head)->totalsize && p->next)
	{
		p = p->next;
		a[z] = p->number;
	}
	for (int i = 0; i < (*head)->totalsize; i++)
	{
		for(int j = 0;j < (((*head)->totalsize)- 1);j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
			}
		}
	}
	printf("배열정렬 : ");
	for(int i = 0; i < ((*head)->totalsize); i++)
	{
		printf("%d ",a[i]);
	}
	z = 0;
	p = *head;
	printf_linke(*head);
	printf_linke(*head2); 
	while(z < (*head)->totalsize)
	{	
		p = (*head)->next;
		while(p)
		{
			if(a[z] == p->number)
			{
				p->name = z;
				z++;
			}
			p = p->next;
		}

	}
	printf("변경완료!\n");
}

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
	printf("sort2!\n");
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
