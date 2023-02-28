/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 01:29:26 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/02/28 16:51:19 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	if (a && *a && (*a)->next)
	{
		ft_swap(&((*a)->number), &((*a)->next->number));
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack **b)
{
	if (b && *b && (*b)->next)
	{
		ft_swap(&((*b)->number), &((*b)->next->number));
		write(1, "sb\n", 3);
	}
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (b && *b)
	{
		tmp = (*b)->next;
		(*b)->next = *a;
		*a = *b;
		*b = tmp;
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (a && *a)
	{
		tmp = (*a)->next;
		(*b)->next = tmp;
		tmp->next = tmp->prev->next;
		// *b = *a;
		// *a = tmp;
		write(1, "pb\n", 3);
	}
}

void	ra(t_stack **a)
{
	t_stack	*tmp;

	if (a && *a && (*a)->next)
	{
		tmp = (*a);
		(*a) = (*a)->next;
		(*a)->prev = NULL;
		tmp->prev = ft_stacklast(*a);
		tmp->next = NULL;
		tmp->prev->next = tmp;
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack **b)
{
	t_stack	*tmp;

	if (b && *b && (*b)->next)
	{
		tmp = (*b);
		(*b) = (*b)->next;
		(*b)->prev = NULL;
		tmp->prev = ft_stacklast(*b);
		tmp->next = NULL;
		tmp->prev->next = tmp;
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 1);
}

void	rra(t_stack **a)
{
	t_stack	*tmp;

	if (a && *a && (*a)->next)
	{
		tmp = ft_stacklast(*a);
		(*a) = tmp;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;

	if (b && *b && (*b)->next)
	{
		tmp = ft_stacklast(*b);
		(*b) = tmp;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_stack *ft_stacklast(t_stack *stack)
{
	if (stack)
	{
		while (stack->next)
			stack = stack->next;
	}
	return (stack);
}