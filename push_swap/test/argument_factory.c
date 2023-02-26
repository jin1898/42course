#include "push_swap.h"

void	sort(t_stack **head,t_stack **head2)
{
	int a[(*head)->totalsize];
	int z;
	t_stack *p;
	
	p = *head;
	z = -1;
	while(z++ < (*head)->totalsize  && p->next)
	{
		p = p->next;
		a[z] = p->number;
	}
	//배열을 만들어서 값 다 넣은 다음
	int temp; 

  	  for(int i = 0;i < (*head)->totalsize; i++)
	  {
       		for(int j = 0;j < (((*head)->totalsize)- 1);j++)
		{
        	    if(a[j]>a[j+1])
		    {
       	         	temp=a[j];
        	        a[j]=a[j+1];
                	a[j+1]=temp;
		    }
       		 }
   	 }	
	printf("배열정렬 : ");
	for(int i = 0; i < ((*head)->totalsize); i++)
	{
		printf("%d ",a[i]);
	}
	z = 0;
	p = *head;
	printf_linke(*head);
	printf_linke(*head2); 
	while(z < (*head)->totalsize)
	{	
		p = (*head)->next;
		while(p)
		{
			if(a[z] == p->number)
			{
				p->name = z;
				z++;
			}
			p = p->next;
		}

	}
	printf("변경완료!\n");
}

void	print_error(void)
{
	write(2,"Error\n",6);
	exit(1);
}
