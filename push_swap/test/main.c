/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:28:45 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/02/28 01:04:29 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	if(ac <= 2 )
		print_error();
	t_stack	*head = NULL;
	t_stack *head2 = NULL;

	head = get_linke(head,-1);
	head2 = get_linke(head2,-2);
	char **a;
	int i = 1;
	int n = 0;
	int count = 0;

	while (*(av + i))
	{
		a = ft_split(av[i], ' ');
		n = 0;
		while (a[n])
		{
			add_tail_dlinke(head, ft_atoll(a[n]), count);
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
	printf("연결리스트 완료---start---\n");
	printf_linke(head);
	printf_linke(head2);
	printf("연결리스트 완료---end---\n");
	printf("\n[total %d words]\n",count);
	printf("=========================\n");
	check_dup(head);
	if (!indexing1(&head, &head2))
		return (0);
	printf("indexing 완료됬음!--start---\n");
	printf_linke(head);
	printf_linke(head2);
	printf("indexing 완료됬음!---end--\n");
	// mainsort(&head, &head2);
	// sandatob(&head, &head2);
	// sandbtoa(&head, &head2);
	del_all_dlinke(&head);
	del_all_dlinke(&head2);
	printf("head : %p, head2 : %p\n",head,head2);
	system("leaks a.out -q");
}

void	check_dup(t_stack *a)
{
	t_stack *point;
	t_stack *head;

	point = a;
	head = a;
	point = point->next;
	while(point->next)
	{
		head = point->next;
		while(head)
		{
			if(point->number == head->number)
			{
				printf("check_dup going in \n");
				printf("\n--[information]--\n [point->name %d] [head->name %d] \n [point: %d] == [head: %d]\n",point->name, head->name,point->number,head->number);
				del_all_dlinke(&a);

				system("leaks a.out -q");
				print_error();
			}
			head = head->next;
		}
		point = point->next;
	}
}
