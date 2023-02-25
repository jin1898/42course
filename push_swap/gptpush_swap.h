#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
typedef struct  s_stack
{
    int             value;
    struct s_stack  *next;
    struct s_stack  *prev;
}               t_stack;



void    ft_swap(int *a, int *b);
t_stack *ft_stacknew(int value);
void    ft_stackadd_front(t_stack **stack, t_stack *new);
void    ft_stackadd_back(t_stack **stack, t_stack *new);
t_stack *ft_stacklast(t_stack *stack);
void    ft_putstr_fd(char *s, int fd);
size_t  ft_strlen(const char *s);
#endif