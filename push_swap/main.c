#include "push_swap.h"

int	main(void)
{
	t_stack *head1 = get_linke(head1, -1);

	printf("[head1 : %p]\n", head1);
	printf("[head1->number : %d]\n",head1->number);

	add_tail_dlinke(head1, 33, -1);
	add_tail_dlinke(head1, 26, -1);
	
	printf("[head1->number : %d]\n",head1->number);
	add_tail_dlinke(head1, 96, -1);
	add_tail_dlinke(head1, 1, -1);

	printf_linke(head1);

	del_all_dlinke(head1);

	printf_linke(head1);
	
	printf("[head1 : %p]\n", head1);
	printf("----------\n");
	system("leaks -q a.out");

	printf("----------\n");

}
