#include "push_swap.h"

void	sort(t_stack **head,t_stack **head2)
{
	int a[(*head)->totalsize];
	int z;
	int totalsize;
	t_stack *p;
	
	p = *head;
	totalsize = p->totalsize;
	z = -1;
	while(z++ < totalsize && p->next)
	{
		p = p->next;
		a[z] = p->number;
	}
	//배열을 만들어서 값 다 넣은 다음
	int temp; 

  	  for(int i = 0;i < totalsize;i++)
	  {
       	for(int j = 0;j < (totalsize - 1);j++)
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
	for(int i = 0; i < totalsize; i++)
	{
		printf("%d ",a[i]);
	}
	// 정렬시켜서 
	z = -1;
	p = *head;
	printf_linke(*head);
	printf_linke(*head2); 
	while (z++ < totalsize)
	{	
		p = (*head)->next;
		if (!(a[z] != p->number))
		{
			p = p->next;
			printf("같지 않음! 다음으로 넘어감\n");
		}
		else
		{
			printf("같음1! a[z] = %d / p->name = %d\n",a[z],p->name);
			p->name = z;
			printf("같음2! a[z] = %d / p->name = %d z = %d\n",a[z],p->name,z);
		}
	}
	printf("변경완료!\n");
	printf_linke(*head);
	printf_linke(p);
	//정렬시킨 인덱스값을 head에 다 넣어주기
}

void	print_error(void)
{
	write(2,"Error\n",6);
	exit(1);
}
