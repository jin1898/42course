#include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <strings.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"

int main(void)
{
	int		fd;
	char	*line;

	fd = open("get_next_line.c", O_RDONLY);
    while ((line = get_next_line(fd)) != 0)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	
	/*
	printf("----------------------------------\n");
	system("leaks -q a.out");
	*/
	return (0);
	
}
