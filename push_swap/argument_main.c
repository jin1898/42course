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

void	check_dup(t_stack *a)
{
	t_stack *point;
	t_stack *head;

	point = a;
	head = a;
	point = point->next;
	while(point->next)
	{
		head = point->next;
		while(head)
		{
			if(point->number == head->number)
			{
				printf("check_dup going in \n");
				printf("\n--[information]--\n [point->name %d] [head->name %d] \n [point: %d] == [head: %d]\n",point->name, head->name,point->number,head->number);
				del_all_dlinke(&a);
				
				system("leaks a.out -q");
				print_error();
			}
			head = head->next;
		}
		point = point->next;
	}
}

//int main(int ac, char **av)
//{
//	int i = 1;
//	while(*(av+i))
//	{
//		printf("%s\n",av[i]);
//		i++;
//	}
//}

//		while(point->number != a->number && a->name < a->totalsize && point->name < point->totalsize)
//		{
//			point = point->next;
//			a = a->next;
//		}
