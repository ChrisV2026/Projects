#include <stdio.h>
#include "gametypes.h"
#include <string.h>

#define charmax 6
#define maxx 25

void withinrange(int rangelist[], int ycord, int xcord, gamemap map[][maxx], gamecharwep opplist[], int *count)
{
    int i;

	for (i = 0; i < charmax; i++)
	{
		if ((strcmp(opplist[i].character.charinits, map[ycord][xcord].tile)) == 0)
		{
			rangelist[*count] = i;
			(*count)++;
		}
	}
}
