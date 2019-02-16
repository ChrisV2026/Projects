#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "file read lines.h"
#include "gametypes.h"
#include "selection.h"

#define charmax 6

main()
{
	gamecharwep p1list[6] = {}, p2list[6] ={};
	int check = 0;
	bool p1turn, p2turn;
	//char map1[25][25] = {}
	//map2[25][25] = {}, map3[25][25] = {}, map[25][25]= {};

	/*if ()
	{
		for (i = 0; i < 25; i++)
			for (n = 0; n < 25; n++)
				map[i][n] = map1[i][n];
	}
	else if()
	{
		for (i = 0; i < 25; i++)
			for (n = 0; n < 25; n++)
				map[i][n] = map2[i][n];
	}
	else if()
	{
		for (i = 0; i < 25; i++)
			for (n = 0; n < 25; n++)
				map[i][n] = map3[i][n];
	}*/

	check = cwselect(p1list, p2list);

	//starting positions will just be given

	/*for (i = 1; i > 0; i++)
	{
		if (i % 2 != 0)
		{
			move(p1list, terremap, map, 0, p2list, 1)
		}
		else if (i % 2 == 0)
		{
			move(p2list, terremap, map, 0, p2list, 2)
		}

		//change all people that aren't dead to not being used
	}
	*/



}
