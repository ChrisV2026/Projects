#include <stdio.h>
#include "gametypes.h"
#include <time.h>
#include <stdlib.h>

void hitcrit(gamecharwep attacker[], gamecharwep defender[], int attpos, int defpos, int attweppos, int defweppos, int *damage, int *recoil)
{
	int hitchance, enhitchance, critchance, encritchance, avoid, enavoid, enhitrate, hitrate, dodge, endodge, critrate, encritrate;
	
	srand(time(NULL));
	
	hitchance = rand()%101;
	enhitchance = rand()%101;

	critchance = rand()%101;
	encritchance = rand()%101;
	
	avoid = (attacker[attpos].character.stats.spd * 3)/2 + attacker[attpos].character.stats.luck /2;
	enavoid = (defender[defpos].character.stats.spd * 3)/2 + defender[defpos].character.stats.luck /2;
	
	enhitrate = defender[defpos].character.stats.skill *3 + defender[defpos].weapons[defweppos].hitrate + defender[defpos].character.stats.luck /2 - avoid;
	hitrate = attacker[attpos].character.stats.skill *3 + attacker[attpos].weapons[attweppos].hitrate + attacker[attpos].character.stats.luck /2 - enavoid;
	
	dodge = attacker[attpos].character.stats.luck /2;
	endodge = defender[defpos].character.stats.luck /2;
	
	critrate = attacker[attpos].character.stats.skill /2 + attacker[attpos].weapons[attweppos].critrate - endodge;
	encritrate = defender[defpos].character.stats.skill /2 + defender[defpos].weapons[defweppos].critrate - dodge;
	
	if (hitchance <= hitrate)
	{
		if (critchance <= critrate)
			*damage = *damage *3;
	}
	
	else if (hitchance > hitrate)
		*damage = 0;
		
	if (enhitchance <= enhitrate)
	{
		if (encritchance <= encritrate)
			*recoil= *recoil *3;
	}
	
	else if (enhitchance > enhitrate)
		*recoil = 0;
}

