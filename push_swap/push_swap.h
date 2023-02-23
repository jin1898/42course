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


t_stack *add_tail_dlinke(t_stack *head, int number, int name);
void	printf_linke(t_stack *head);
void del_all_dlinke(t_stack **head);
t_stack *get_linke(t_stack *head, int name);
char	**ft_split(char const *s, char c);
int ft_atoll(const char *str);
void	print_error(void);
void	check_dup(t_stack *a);
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#endif 
