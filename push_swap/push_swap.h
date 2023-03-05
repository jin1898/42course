/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:36:36 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/03/03 19:26:04 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_doubly_linke
{
	int						name;
	int						number;
	struct s_doubly_linke	*next;
	struct s_doubly_linke	*prev;
	int						totalsize;

}t_stack;

t_stack	*add_tail_dlinke(t_stack *head, int number, int name);
void	del_all_dlinke(t_stack **head);
t_stack	*get_linke(int name);
char	**ft_split(char const *s, char c);
int		ft_atoll(const char *str);
void	print_error(void);
void	printf_linke(t_stack *head); // 이 함수 없애야함!!!!!!!!!!!!!!!!!!!!!!!!ㄴ
void	check_dup(t_stack *a);
void	*indexing3(t_stack **head, int *a);
void	*indexing2(t_stack **head, int *a);
int		*indexing1(t_stack **head);
void	parsing(char **av, t_stack **head, int i);

int		sorted(t_stack *head);
void	find_pushb(int a, t_stack **head, t_stack **head2);
void	sort3(t_stack **head, t_stack *head2);
void	sort4(t_stack **head, t_stack **head2);
void	sort5(t_stack **head, t_stack **head2);
void	sort2(t_stack **head, int i);
void	mainsort(t_stack **head, t_stack **head2);
void	sandatob(t_stack **head, t_stack **head2);
void	sandbtoa(t_stack **head, t_stack **head2);

void	push(t_stack **in, t_stack **out);
void	push2(t_stack **in, t_stack **out);
void	swap(t_stack **a);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
#endif