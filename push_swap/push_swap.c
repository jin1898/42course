/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:40:35 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/03/05 17:24:10 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	*head;
	t_stack	*head2;
	int		i;

	i = 1;
	(void)ac;
	head = NULL;
	head2 = NULL;
	head = get_linke(-1);
	head2 = get_linke(-2);
	parsing(av, &head, i);
	if ((head)->totalsize <= 1)
		exit(1);
	check_dup(head);
	indexing1(&head);
	// printf("indexing/check_dup/parsing완료--start--\n");
	// printf_linke(head);
	// printf_linke(head2);
	// printf("indexing/check_dup/parsing완료--end--\n");
	mainsort(&head, &head2);
	// printf("indexing/check_dup/indexing/mainsort완료--start--\n");
	// printf_linke(head);
	// printf_linke(head2);
	// printf("indexing/check_dup/indexing/mainsort완료--end--\n");
	del_all_dlinke(&head);
	del_all_dlinke(&head2);
}

void	parsing(char **av, t_stack **head, int i)
{
	int		n;
	char	**a;
	int		count;

	count = 0;
	n = 0;
	while (*(av + i))
	{
		a = ft_split(av[i], ' ');
		n = 0;
		while (a[n])
		{
			add_tail_dlinke(*head, ft_atoll(a[n]), count);
			n++;
			count++;
		}
		i++;
		n = 0;
		while (a[n])
		{
			free(a[n]);
			n++;
		}
		free(a);
	}
}

void	check_dup(t_stack *a)
{
	t_stack	*point;
	t_stack	*head;

	point = a;
	head = a;
	point = point->next;
	while (point->next)
	{
		head = point->next;
		while (head)
		{
			if (point->number == head->number)
			{
				del_all_dlinke(&a);
				print_error();
			}
			head = head->next;
		}
		point = point->next;
	}
}

//이 함수 없애야함!
void	printf_linke(t_stack *head)
{
	// printf("---start-----\n");
	while (head)
	{
		printf("[name : %d] [number: %d] [totalsize : %d]\n",head->name,head->number,head->totalsize);
		head = head->next;
	}
	printf("#######[head : %p]#########\n", head);
	// printf("----end----\n");
}
//이 함수 없애야함!
