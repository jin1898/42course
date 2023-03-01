#include "push_swap.h"

int	main(int ac, char **av)
{
	if(ac <= 2 )
		print_error();
	t_stack	*head = NULL;
	t_stack	*head2 = NULL;

	head = get_linke(head,-1);
	head2 = get_linke(head2,-2);
	char **a;
	int i = 1;
	int n = 0;
	int count = 0;

	while (*(av + i))
	{
		a = ft_split(av[i], ' ');
		n = 0;
		while (a[n])
		{
			add_tail_dlinke(head, ft_atoll(a[n]), count);
			n++;
			count++;
		}
		i++;
		n = 0;
		while (a[n])
		{
			free(a[n]);
			n++;
		}
		free(a);
	}
	printf_linke(head);
	printf_linke(head2);
	printf("\n[total %d words]\n", count);
//	check_dup(head);
	printf("going in to sort\n");
	sort(&head,&head2);
	printf_linke(head);
	printf_linke(head2);
//	sa(&(head->next));
//	printf_linke(head);
//	printf_linke(head2);
//


//	ss(&(head->next),&(head2->next));
//	printf_linke(head);
//	printf_linke(head2);

//	pb(&(head->next),&(head2->next));
//	printf_linke(head);
//	printf_linke(head2);
//
//	pb(&(head->next),&(head2->next));
//	printf_linke(head);
//	printf_linke(head2);
//
//	sb(&(head2->next));
//	printf_linke(head);
//	printf_linke(head2);

	del_all_dlinke(&head);
	del_all_dlinke(&head2);
	printf("head : %p, head2 : %p\n",head,head2);
	system("leaks a.out -q");
}
