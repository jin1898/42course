#include "push_swap.h"

void swap(t_stack *head)
{
	t_stack *pointer;

	pointer = head;
	pointer->next = pointer->next->next;
	pointer = head->next->prev;
	pointer->next = pointer->next->next;
	pointer->prev = head->next;
	pointer = head->next;
	pointer->prev = head;
	pointer = head->next->next;






}

push

rotate

reverse rotate
