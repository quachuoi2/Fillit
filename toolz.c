#include "fillit.h"
#include <stdio.h>

/* Don't pay attention to this file */


void print_all_tet(char ***arr)
{
	int i = 0;
	while ((*arr)[i] != NULL)
	{
		printf("tetri %d:\n%s", i, (*arr)[i]);
		free((*arr)[i++]);
	}
	free(*arr);
}

void print_pos(t_tetris t)
{
	int i;
	int i2;

	i = 0;
	while (i < 4)
	{
		i2 = 0;
		while (i2 < 2)
		{
			printf("%d ", t.box[i][i2]);
			i2++;
		}
		printf("\n");
		i++;
	}
}
