#include "gametypes.h"
#include <string.h>

void clonechar(gamecharwep str2[], int charpos2, gamechar str1[], int charpos1)
{		
		strcpy(str2[charpos2].character.charinits, str1[charpos1].charinits);
		strcpy(str2[charpos2].character.wepinits, str1[charpos1].wepinits);
		strcpy(str2[charpos2].character.name, str1[charpos1].name);
		str2[charpos2].character.type = str1[charpos1].type;						
		str2[charpos2].character.stats.health = str1[charpos1].stats.health;
		str2[charpos2].character.stats.stg = str1[charpos1].stats.stg;
		str2[charpos2].character.stats.magic = str1[charpos1].stats.magic;
		str2[charpos2].character.stats.skill = str1[charpos1].stats.skill;
		str2[charpos2].character.stats.luck = str1[charpos1].stats.luck;
		str2[charpos2].character.stats.spd = str1[charpos1].stats.spd;
		str2[charpos2].character.stats.def = str1[charpos1].stats.def;
		str2[charpos2].character.stats.res = str1[charpos1].stats.res;
		str2[charpos2].character.stats.move = str1[charpos1].stats.move;
}

void clonewep(gamecharwep str2[], int charpos2, int wepnum2, gameweapon str1[], int weppos1)
{
	strcpy(str2[charpos2].weapons[wepnum2].type, str1[weppos1].type);
	strcpy(str2[charpos2].weapons[wepnum2].name, str1[weppos1].name);
	str2[charpos2].weapons[wepnum2].range[0] = str1[weppos1].range[0];
	str2[charpos2].weapons[wepnum2].range[1] = str1[weppos1].range[1];
	str2[charpos2].weapons[wepnum2].might = str1[weppos1].might;
	str2[charpos2].weapons[wepnum2].hitrate = str1[weppos1].hitrate;
	str2[charpos2].weapons[wepnum2].critrate = str1[weppos1].critrate;
	str2[charpos2].weapons[wepnum2].effective = str1[weppos1].effective;
}
