#include "push_swap.h"

void    ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

//t_stack2 *ft_stacknew(int value)
//{
//    t_stack2 *new;
//
//    new = (t_stack2 *)malloc(sizeof(t_stack2));
//    if (new)
//    {
//        new->value = value;
//        new->next = NULL;
//        new->prev = NULL;
//    }
//    return (new);
//}

void    ft_stackadd_front(t_stack **stack, t_stack *new)
{
    if (new)
    {
        new->next = *stack;
        if (*stack)
            (*stack)->prev = new;
        *stack = new;
    }
}

void    ft_stackadd_back(t_stack **stack, t_stack *new)
{
    if (new)
    {
        if (*stack)
            ft_stacklast(*stack)->next = new;
        else
            *stack = new;
        new->prev = ft_stacklast(*stack);
    }
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

void    ft_putstr_fd(char *s, int fd)
{
    if (s)
        write(fd, s, ft_strlen(s));
}

size_t  ft_strlen(const char *s)
{
    size_t  i;

    i = 0;
    while (s && s[i])
        i++;
    return (i);
}
