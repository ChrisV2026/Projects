#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "file read lines.h"
#include "gametypes.h"
#include "selection.h"

#define charmax 6
#define maxx 25
#define maxy 25

main()
{
	gamecharwep p1list[6] = {}, p2list[6] ={};
	int check = 0;
	bool p1turn, p2turn;


 	gamemap map[maxy][maxx] =
		{{'0', '0', '0', '0', '0', '0', '0', 'F', 'F', 'F', 'F', '0', 'R', '0', 'F', 'F', 'F', 'F', '0', '0', '0', '0', '0', 'S', 'S'},
		{'0', '0', '0', '0', '0', '0', '0', 'F', 'F', 'F', '0', '0', 'B', '0', '0', 'F', 'F', 'F', '0', '0', '0', '0', '0', 'S', 'S'} ,
		{'0', '0', '0', '0', '0', '0', '0', 'F', 'F', '0', '0', '0', 'R', '0', '0', '0', 'F', 'F', '0', '0', '0', '0', '0', 'S', 'S'},
		{'0', '0', '0', 'F', 'F', 'F', '0', 'F', '0', '0', '0', 'R', 'R', 'R', '0', '0', '0', 'F', '0', 'F', 'F', 'F', '0', '0', '0'},
		{'F', '0', 'F', 'F', 'F', 'F', '0', '0', '0', '0', 'B', 'R', 'R', 'R', 'B', '0', '0', '0', '0', 'F', 'F', 'F', 'F', '0', 'F'},
		{'F', '0', 'F', 'F', 'F', 'F', '0', '0', '0', 'R', 'B', '0', '0', '0', 'B', 'R', '0', '0', '0', 'F', 'F', 'F', 'F', '0', 'F'},
		{'F', '0', 'F', 'F', 'F', 'F', '0', '0', 'R', 'R', '0', '0', 'F', '0', '0', 'R', 'R', '0', '0', 'F', 'F', 'F', 'F', '0', 'F'},
		{'F', '0', '0', 'F', 'F', '0', '0', 'R', 'R', '0', '0', 'F', 'F', 'F', '0', '0', 'R', 'R', '0', '0', 'F', 'F', '0', '0', 'F'},
		{'F', '0', '0', 'F', '0', '0', 'R', 'R', '0', '0', '0', 'F', 'F', 'F', '0', '0', '0', 'R', 'R', '0', '0', 'F', '0', '0', 'F'},
		{'F', '0', '0', '0', '0', 'B', 'R', '0', '0', 'M', 'M', 'M', 'F', 'M', 'M', 'M', '0', '0', 'R', 'B', '0', '0', '0', '0', 'F'},
		{'0', '0', '0', '0', 'R', 'B', '0', '0', '0', 'M', 'M', 'M', '0', 'M', 'M', 'M', '0', '0', '0', 'B', 'R', '0', '0', '0', '0'},
		{'0', '0', '0', 'R', 'R', '0', '0', 'F', 'F', 'M', 'M', 'M', '0', 'M', 'M', 'M', 'F', 'F', '0', '0', 'R', 'R', '0', '0', '0'},
		{'R', 'B', 'R', 'R', '0', '0', 'F', 'F', 'F', 'F', '0', '0', '0', '0', '0', 'F', 'F', 'F', 'F', '0', '0', 'R', 'R', 'B', 'R'},
		{'0', '0', '0', 'R', 'R', '0', '0', 'F', 'F', 'M', 'M', 'M', '0', 'M', 'M', 'M', 'F', 'F', '0', '0', 'R', 'R', '0', '0', '0'},
		{'0', '0', '0', '0', 'R', 'B', '0', '0', '0', 'M', 'M', 'M', '0', 'M', 'M', 'M', '0', '0', '0', 'B', 'R', '0', '0', '0', '0'},
		{'F', '0', '0', '0', '0', 'B', 'R', '0', '0', 'M', 'M', 'M', 'F', 'M', 'M', 'M', '0', '0', 'R', 'B', '0', '0', '0', '0', 'F'},
		{'F', '0', '0', 'F', '0', '0', 'R', 'R', '0', '0', '0', 'F', 'F', 'F', '0', '0', '0', 'R', 'R', '0', '0', 'F', '0', '0', 'F'},
		{'F', '0', '0', 'F', 'F', '0', '0', 'R', 'R', '0', '0', 'F', 'F', 'F', '0', '0', 'R', 'R', '0', '0', 'F', 'F', '0', '0', 'F'},
		{'F', '0', 'F', 'F', 'F', 'F', '0', '0', 'R', 'R', '0', '0', 'F', '0', '0', 'R', 'R', '0', '0', 'F', 'F', 'F', 'F', '0', 'F'},
		{'F', '0', 'F', 'F', 'F', 'F', '0', '0', '0', 'R', 'B', '0', '0', '0', 'B', 'R', '0', '0', '0', 'F', 'F', 'F', 'F', '0', 'F'},
		{'F', '0', 'F', 'F', 'F', 'F', '0', '0', '0', '0', 'B', 'R', 'R', 'R', 'B', '0', '0', '0', '0', 'F', 'F', 'F', 'F', '0', 'F'},
		{'0', '0', '0', 'F', 'F', 'F', '0', 'F', '0', '0', '0', 'R', 'R', 'R', '0', '0', '0', 'F', '0', 'F', 'F', 'F', '0', '0', '0'},
		{'S', 'S', '0', '0', '0', '0', '0', 'F', 'F', '0', '0', '0', 'R', '0', '0', '0', 'F', 'F', '0', '0', '0', '0', '0', '0', '0'},
		{'S', 'S', '0', '0', '0', '0', '0', 'F', 'F', 'F', '0', '0', 'B', '0', '0', 'F', 'F', 'F', '0', '0', '0', '0', '0', '0', '0'},
		{'S', 'S', '0', '0', '0', '0', '0', 'F', 'F', 'F', 'F', '0', 'R', '0', 'F', 'F', 'F', 'F', '0', '0', '0', '0', '0', '0', '0'}};

/*
	gamemap map2[maxy][maxx] =
		{{'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
		{'W', 'S', 'S', '0', '0', 'W', '/', '/', '/', '/', 'W', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'W'},
		{'W', 'S', 'S', '0', '0', 'W', '/', '/', '/', '/', 'W', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'W', 'W', 'W', '0', 'W'},
		{'W', 'S', 'S', '0', '0', 'W', '/', '/', '/', '/', 'W', '0', 'W', 'W', '0', 'W', 'W', 'W', 'W', '0', 'W', '/', 'W', '0', 'W'},
		{'W', 'W', 'W', '0', '0', 'W', '/', '/', '/', '/', 'W', '0', 'W', 'W', '0', 'W', '/', '/', 'W', '0', 'W', '/', 'W', '0', 'W'},
		{'/', '/', 'W', '0', '0', 'W', '/', '/', 'W', 'W', 'W', '0', 'W', 'W', '0', 'W', '/', '/', 'W', '0', 'W', 'W', 'W', '0', 'W'},
		{'/', '/', 'W', '0', '0', 'W', '/', '/', 'W', '0', '0', '0', '0', 'W', '0', 'W', '/', '/', 'W', '0', '0', '0', '0', '0', 'W'},
		{'W', 'W', 'W', '0', '0', 'W', 'W', 'W', 'W', '0', '0', '0', '0', 'W', '0', 'W', '/', '/', 'W', '0', '0', '0', '0', '0', 'W'},
		{'W', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'W', '0', 'W', '/', '/', 'W', '0', 'W', 'W', 'W', '0', 'W'},
		{'W', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'W', '0', 'W', 'W', 'W', 'W', '0', 'W', '/', 'W', '0', 'W'},
		{'W', '0', '0', 'W', 'W', 'W', 'W', 'W', 'W', 'W', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'W', 'W', 'W', '0', 'W'},
		{'W', '0', '0', 'W', '/', '/', '/', '/', '/', 'W', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'W'},
		{'W', '0', '0', 'W', '/', '/', '/', '/', '/', 'W', '0', '0', 'W', 'W', 'W', '0', '0', '0', '0', '0', 'W', '0', '0', '0', 'W'},
		{'W', '0', '0', 'W', '/', '/', '/', '/', '/', 'W', '0', '0', 'W', '/', 'W', '0', '0', '0', '0', '0', 'W', '0', '0', '0', 'W'},
		{'W', '0', '0', 'W', '/', '/', '/', '/', '/', 'W', '0', '0', 'W', '/', 'W', '0', '0', '0', '0', '0', 'W', '0', '0', '0', 'W'},
		{'W', '0', '0', 'W', 'W', 'W', 'W', 'W', 'W', 'W', '0', '0', 'W', '/', 'W', '0', '0', '0', '0', '0', 'W', '0', '0', '0', 'W'},
		{'W', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'W', '/', 'W', '0', '0', '0', '0', '0', 'W', '0', '0', '0', 'W'},
		{'W', '0', '0', 'W', 'W', 'W', 'W', '0', 'W', 'W', 'W', '0', 'W', '/', 'W', '0', '0', '0', '0', '0', 'W', '0', '0', '0', 'W'},
		{'W', '0', '0', 'W', '/', '/', 'W', '0', 'W', '/', 'W', '0', 'W', '/', 'W', '0', '0', '0', '0', '0', 'W', '0', '0', '0', 'W'},
		{'W', '0', '0', 'W', 'W', 'W', 'W', '0', 'W', '/', 'W', '0', 'W', '/', 'W', '0', '0', '0', '0', '0', 'W', '0', 'S', 'S', 'W'},
		{'W', '0', '0', '0', '0', '0', '0', '0', 'W', '/', 'W', '0', 'W', '/', 'W', '0', '0', '0', '0', 'W', 'W', 'W', 'S', 'S', 'W'},
		{'W', '0', '0', 'W', 'W', 'W', 'W', 'W', 'W', '/', 'W', '0', 'W', 'W', 'W', '0', '0', '0', 'W', 'W', '/', 'W', 'S', 'S', 'W'},
		{'W', 'W', 'W', 'W', '/', '/', '/', '/', '/', '/', 'W', '0', '0', '0', '0', '0', '0', 'W', 'W', '/', '/', '/', 'W', 'W', 'W'},
		{'/', '/', '/', '/', '/', '/', '/', '/', '/', '/', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', '/', '/', '/', '/', '/', '/', '/'},
		{'/', '/', '/', '/', '/', '/', '/', '/', '/', '/', '/', '/', '/', '/', '/', '/', '/', '/', '/', '/', '/', '/', '/', '/', '/'}}

	gamemap map3[maxy][maxx] =
		{{'D', 'S', 'S', 'S', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', '0', '0', '0'}
		{'D', 'S', 'S', 'S', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', '0', '0', '0', 'D', 'D', '0', '0', '0'}
		{'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', '0', '0', 'D', 'D', 'D', '0', '0', '0', '0', 'D', '0', '0', 'D', 'D', 'D', 'D'}
		{'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', '0', '0', 'D', 'D', '0', '0', '0', '0', 'D', 'D', 'D', '0', '0', 'D', 'D', 'V'}
		{'D', 'D', 'D', 'D', '0', 'D', 'D', 'D', '0', '0', '0', 'D', '0', '0', '0', 'D', 'D', 'D', 'D', 'D', 'D', '0', 'D', 'V', 'V'}
		{'D', 'D', 'D', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'B', 'V', 'V', 'V'}
		{'D', 'D', 'D', '0', '0', '0', '0', '0', '0', '0', 'D', '0', '0', '0', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'B', 'V', 'V', 'V'}
		{'D', 'D', 'D', '0', '0', '0', '0', '0', '0', 'D', 'D', 'D', '0', '0', 'D', 'D', 'D', 'V', 'V', 'V', 'V', 'B', 'V', 'V', 'D'}
		{'D', 'D', 'D', 'D', 'D', '0', '0', '0', '0', 'D', 'D', 'D', '0', '0', 'D', 'D', 'V', 'V', 'V', 'V', 'V', 'B', 'V', 'D', 'D'}
		{'D', 'D', 'D', 'D', 'D', 'D', '0', '0', '0', 'D', 'D', 'D', 'B', 'B', 'D', 'V', 'V', 'V', 'V', 'V', 'V', 'B', 'D', 'D', 'D'}
		{'D', 'D', 'D', 'D', 'D', 'D', 'D', '0', 'D', 'D', 'D', 'V', 'B', 'B', 'V', 'V', 'V', 'V', 'D', 'D', 'B', 'D', 'D', 'D',}
		{'D', 'D', 'D', 'D', 'D', 'D', 'D', '0', 'D', 'D', 'V', 'V', 'B', 'B', 'V', 'V', 'V', 'D', 'D', 'D', 'D', '0', '0', 'D', 'D'}
		{'D', 'D', 'D', 'D', 'D', 'D', 'D', 'B', 'D', 'V', 'V', 'V', 'B', 'B', 'V', 'V', 'D', 'D', 'D', 'D', 'D', '0', '0', 'D', 'D'}
		{'D', 'D', 'D', 'D', 'D', 'D', 'V', 'B', 'V', 'V', 'V', 'D', 'B', 'B', 'D', 'D', 'D', 'D', 'D', 'D', 'D', '0', '0', 'D', 'D'}
		{'D', 'D', 'D', 'D', 'D', 'V', 'V', 'B', 'V', 'V', 'D', 'D', '0', '0', 'D', 'D', 'D', 'D', 'D', 'D', '0', '0', '0', 'D', 'D'}
		{'D', 'D', 'D', 'D', 'V', 'V', 'V', 'B', 'V', 'D', 'D', 'D', '0', '0', 'D', 'D', 'D', 'D', 'D', 'D', '0', '0', '0', 'D', 'D'}
		{'D', 'D', 'D', 'V', 'V', 'V', 'D', 'B', 'D', 'D', 'D', 'D', '0', '0', '0', '0', 'D', 'D', 'D', 'D', '0', '0', 'D', 'D', 'D'}
		{'D', 'D', 'V', 'V', 'V', 'D', 'D', '0', 'D', 'D', 'D', 'D', '0', '0', '0', '0', 'D', 'D', '0', '0', '0', '0', 'D', 'D', 'D'}
		{'V', 'V', 'V', 'V', 'D', 'D', 'D', '0', '0', 'D', 'D', 'D', '0', '0', '0', '0', 'D', '0', '0', '0', '0', '0', 'D', 'D', 'D'}
		{'V', 'V', 'V', 'D', 'D', 'D', 'D', '0', '0', '0', 'D', '0', '0', '0', 'D', '0', '0', '0', '0', 'D', '0', '0', 'D', 'D', 'D'}
		{'V', 'V', 'D', 'D', 'D', 'D', 'D', 'D', '0', '0', '0', '0', '0', '0', 'D', '0', '0', '0', 'D', 'D', '0', '0', 'D', 'D', 'D'}
		{'V', 'D', 'D', 'D', 'D', 'D', 'D', 'D', '0', '0', '0', '0', '0', '0', 'D', '0', '0', '0', 'D', 'D', '0', '0', 'D', 'D', 'D'}
		{'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', '0', 'D', 'D', '0', '0', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D'}
		{'D', 'D', 'D', '0', '0', '0', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'S', 'S', 'S', 'D'}
		{'D', 'D', 'D', '0', '0', '0', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'S', 'S', 'S', 'D'}

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
