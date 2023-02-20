#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_doubly_linke
{
	int name;
	int number;
	struct s_doubly_linke *next;
	struct s_doubly_linke *prev;


}t_stack;


t_stack *add_tail_dlinke(t_stack *head, int number, int name);
void	printf_linke(t_stack *head);

t_stack *get_linke(t_stack *head, int name);
#include <stdio.h>
#include <stdlib.h>
#endif 
