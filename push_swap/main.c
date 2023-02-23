#include "push_swap.h"

int	main(int ac, char **av)
{
	if(ac <= 2 )
		print_error();
	t_stack	*head = NULL;
	head = get_linke(head,-1);
	char **a;
	int i = 1;
	int n = 0;
	int count = 0;

	while(*(av+i))
	{

		a = ft_split(av[i],' ');
		n = 0;
		while(a[n])
		{
			add_tail_dlinke(head,ft_atoll(a[n]),count);
			n++;
			count++;
		}
		i++;
		n = 0;
		while(a[n])
		{
			free(a[n]);
			n++;
		}
		free(a);

	}
	printf_linke(head);
	printf("\n[total %d words]\n",count);
	check_dup(head);
	swap(head);
	printf_linke(head);


	del_all_dlinke(&head);
	printf("head : %p\n",head);
	system("leaks a.out -q");
}
