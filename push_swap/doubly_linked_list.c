#include "push_swap.h"

t_stack *add_tail_dlinke(t_stack *head, int number, int name)
{
	t_stack *point;
	t_stack *new;

	point = head;
		if(!head)
		{
			free(head);
			return (NULL);
		}
	new = malloc(sizeof(t_stack));
	new->number = number;
	new->name = 0;
		while(point->next)
			point = point->next;
		new->prev = point;
		new->next = NULL;
		
		point->next = new;
		return(head);
}

void del_all_dlinke(t_stack *head)
{
	t_stack *temp;

	temp = head;
	while(head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

t_stack *get_linke(t_stack *head, int name)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	new->name = name;
	new->next = NULL;
	new->prev = NULL;
	new->number = 0;

	return(new);
}
void	printf_linke(t_stack *head)
{
	printf("--------\n");
	while(head)
	{
		printf("[name : %d] [number: %d]\n",head->name,head->number);
		head = head->next;
	}
	printf("[head : %p]\n",head);

	printf("--------\n");
}

