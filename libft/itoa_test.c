#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

long	ft_count(long num)
{
	long count = 0;
	if (num < 0)
	{
		num *=-1;
		count++;
	}
	while (num /= 10)
		count++;
	return (count);
}

void	ft_balck(long num,char *num_box, long *count)
{
	
	printf("in(count) : %ld/(num) : %ld\n",*count,num);
	if (num > 9)
		ft_balck(num/10, num_box,count);
	num_box[(*count)++] = (num + '0');
	printf("num_box[(*%ld)] : %c\n",*count,num_box[*count]);
}

char	*ft_itoa(int c)
{
	long	num;
	char	*num_box;
	long	i;
	
	i = 0;
	num = (long)c;
	num_box = malloc(sizeof(char) * (ft_count(num) + 1));
	if (num_box == NULL)
		return (NULL);

	if (num < 0)
	{
		num_box[0] = '-';
		num *= -1;
		i++;
	}

	printf("in(i) : %ld/(num) : %ld\n",i,num);
	ft_balck(num, num_box,&i);
	printf("out(i) : %ld/(num) : %ld\n",i,num);
	num_box[ft_count(num)] = 0;
	printf("num_box[%d] : %c\n",2,num_box[2]);
	return(num_box);
}