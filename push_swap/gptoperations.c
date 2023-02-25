#include "push_swap.h"

void    sa(t_stack **a)
{
    if (a && *a && (*a)->next)
    {
        ft_swap(&((*a)->number), &((*a)->next->number));
        ft_putstr_fd("sa\n", 1);
    }
}

void    sb(t_stack **b)
{
    if (b && *b && (*b)->next)
    {
        ft_swap(&((*b)->number), &((*b)->next->number));
        ft_putstr_fd("sb\n", 1);
    }
}

void    ss(t_stack **a, t_stack **b)
{
    sa(a);
    sb(b);
    ft_putstr_fd("ss\n", 1);
}

void    pa(t_stack **a, t_stack **b)
{
    if (b && *b)
    {
        t_stack *tmp;

        tmp = (*b)->next;
        (*b)->next = *a;
        *a = *b;
        *b = tmp;
        ft_putstr_fd("pa\n", 1);
    }
}

void    pb(t_stack **a, t_stack **b)
{
    if (a && *a)
    {
        t_stack *tmp;

        tmp = (*a)->next;
        (*a)->next = *b;
        *b = *a;
        *a = tmp;
        ft_putstr_fd("pb\n", 1);
    }
}

void    ra(t_stack **a)
{
    if (a && *a && (*a)->next)
    {
        t_stack *tmp;

        tmp = (*a);
        (*a) = (*a)->next;
        (*a)->prev = NULL;
        tmp->prev = ft_stacklast(*a);
        tmp->next = NULL;
        tmp->prev->next = tmp;
        ft_putstr_fd("ra\n", 1);
    }
}

void    rb(t_stack **b)
{
    if (b && *b && (*b)->next)
    {
        t_stack *tmp;

        tmp = (*b);
        (*b) = (*b)->next;
        (*b)->prev = NULL;
        tmp->prev = ft_stacklast(*b);
        tmp->next = NULL;
        tmp->prev->next = tmp;
        ft_putstr_fd("rb\n", 1);
    }
}

void    rr(t_stack **a, t_stack **b)
{
    ra(a);
    rb(b);
    ft_putstr_fd("rr\n", 1);
}

void    rra(t_stack **a)
{
    if (a && *a && (*a)->next)
    {
        t_stack *tmp;

        tmp = ft_stacklast(*a);
        (*a) = tmp;
        ft_putstr_fd("rra\n", 1);
    }
}

void    rrb(t_stack **b)
{
    if (b && *b && (*b)->next)
    {
        t_stack *tmp;

        tmp = ft_stacklast(*b);
        (*b) = tmp;
        ft_putstr_fd("rrb\n", 1);
    }
}

void    rrr(t_stack **a, t_stack **b)
{
    rra(a);
    rrb(b);
    ft_putstr_fd("rrr\n", 1);
}