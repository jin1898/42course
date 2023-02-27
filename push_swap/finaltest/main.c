/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:40:35 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/02/28 02:09:43 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	check_dup(head);
	indexing1(&head);
	mainsort(&head, &head2);
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
