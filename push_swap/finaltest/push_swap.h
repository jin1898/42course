/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:36:36 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/03/02 10:01:33 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_doubly_linke
{
	int						name;
	int						number;
	struct s_doubly_linke	*next;
	struct s_doubly_linke	*prev;
	int						totalsize;

}t_stack;

t_stack	*add_tail_dlinke(t_stack *head, int number, int name);
void	printf_linke(t_stack *head);
void	del_all_dlinke(t_stack **head);
t_stack	*get_linke(int name);
char	**ft_split(char const *s, char c);
int		ft_atoll(const char *str);
void	print_error(void);
void	check_dup(t_stack *a);
void	*indexing3(t_stack **head, int *a);
void	*indexing2(t_stack **head, int *a);
int		*indexing1(t_stack **head);
void	parsing(char **av, t_stack **head, int i);

// void	sa(t_stack **a);
// void	sb(t_stack **b);
// void	ss(t_stack **a, t_stack **b);
// void	pa(t_stack **a, t_stack **b);
// void	pb(t_stack **a, t_stack **b);
// void	ra(t_stack **a);
// void	rb(t_stack **b);
// void	rr(t_stack **a, t_stack **b);
// void	rra(t_stack **a);
// void	rrb(t_stack **b);
// void	rrr(t_stack **a, t_stack **b);
// void	ft_swap(int *a, int *b);
// t_stack	*ft_stacklast(t_stack *stack);

int		sorted(t_stack *head);
void	find_pushb(int a, t_stack **head, t_stack **head2);
void	sort3(t_stack **head);
void	sort4(t_stack **head, t_stack **head2);
void	sort5(t_stack **head, t_stack **head2);
void	sort2(t_stack **head);
void	mainsort(t_stack **head, t_stack **head2);
void	sandatob(t_stack **head, t_stack **head2);
void	sandbtoa(t_stack **head, t_stack **head2);

void	push(t_stack **in, t_stack **out);
void	push2(t_stack **in, t_stack **out);
void	swap(t_stack **a);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
#endif