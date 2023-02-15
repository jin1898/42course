#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *string = malloc(10000);
	char *buffer = string;

	while(read(fd, buffer, 1) > 0 && *buffer++ != '\n');
	
	if(buffer > string)
	{
		*buffer = 0;
		return (string);
	}
	else
	{
		free(string);
		return (NULL);
	}
}

//https://github.com/pasqualerossi/42-School-Exam-Rank-03/blob/main/get_next_line/get_next_line.c
//직접변형시킴
