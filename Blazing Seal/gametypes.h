#include <stdbool.h>

typedef struct gamecharstats
{
	int health;
	int totalhealth;
	int stg;
	int magic;
	int skill;
	int luck;
	int spd;
	int def;
	int res;
	int move;
	int movesleft; 
}
gamecharstats;

typedef struct gamemap
{
	char tile[2];
}
gamemap;

typedef struct gamechar 
{
	char charinits[2];
	char type;
	gamecharstats stats;
	char wepinits[2];
	char name[50];
	bool used;
	bool retreated;
}
gamechar;

typedef struct gameweapon
{
	char type[2];
	int range[2];
	int might;
	int hitrate;
	int critrate;
	int cost;
	char effective;
	char name[50];
}
gameweapon;

typedef struct gamecharwep
{
	gamechar character;
	gameweapon weapons[10];
	char position[2];
}
gamecharwep;
