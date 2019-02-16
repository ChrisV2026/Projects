#include <stdio.h>
#include "gametypes.h"

#define maxx 25

void removeunit(gamemap map[][maxx], gamecharwep unit[], int charnum) 
{
	int xcord, ycord;
	
	xcord = (int)(unit[charnum].position[1]) - 65;
	ycord = (int)(unit[charnum].position[0]) - 65;
	map[ycord][xcord].tile[0] = '0';
	map[ycord][xcord].tile[1] = '0';
}
