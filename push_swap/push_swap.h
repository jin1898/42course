#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_doubly_linke
{
	int name;
	int number;
	struct s_doubly_linke *next;
	struct s_doubly_linke *prev;
	int totalsize;

}t_stack;

typedef struct  s_stack
{
    int             value;
    struct s_stack  *next;
    struct s_stack  *prev;
}               t_stack2;

#include <stdlib.h>
#include <unistd.h>



t_stack *add_tail_dlinke(t_stack *head, int number, int name);
void	printf_linke(t_stack *head);
void del_all_dlinke(t_stack **head);
t_stack *get_linke(t_stack *head, int name);
char	**ft_split(char const *s, char c);
int ft_atoll(const char *str);
void	print_error(void);
void	check_dup(t_stack *a);


//----gpt-------------------




void    ft_swap(int *a, int *b);
t_stack2 *ft_stacknew(int value);
void    ft_stackadd_front(t_stack **stack, t_stack *new);
void    ft_stackadd_back(t_stack **stack, t_stack *new);
t_stack *ft_stacklast(t_stack *stack);
void    ft_putstr_fd(char *s, int fd);
size_t  ft_strlen(const char *s);

void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);
void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);
void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#endif 
