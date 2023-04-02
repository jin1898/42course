#include "so_long.h"
#include <stdio.h>

void print_DFS(t_gi *gp, t_dfs *dfs, int location,int i,int plant)
{
	int count = 0;
	for(int b = 0; b < (gp->height); b++)
	{
		
		for(int i = 0; i < (gp->width); i++)
		{
			printf("[%c(%d)]",dfs->cp_str_line[count],count);
			count++;
		}
		printf("    %d",count);
		printf("\n");
	}
	printf("\n[location : %d] / dfs->str_line[location] : %c / [location + move[i] : %d\n",location,dfs->cp_str_line[location], (location+dfs->move[i]));

	printf("\n------------[%d]----------------------\n",plant);
}