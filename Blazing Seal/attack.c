#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "gametypes.h"
#include "hit and crit rate.h"
#include "remove.h"

//defines the max x value for the array size of the map
//for future developments which involves increasing the size
#define maxx 25
#define weaponmax 10
#define charmax 6

int attack(gamecharwep attacker[], gamecharwep defender[], int attpos, int defpos, int attweppos, int defweppos, int range, gamemap map [][maxx], int turn)
{
	//initialising variables
	int damage, effective, attpow, defpow, enemytri, tri, eneffective, enattpow, endefpow, recoil, i;
	char answer, command;

	//uses the weapon triangle to decide the weapon triangle bonus
	//Axe and bows beat lance, lance beats sword and tome and sword and tome beat axe and bows
	if ((attacker[attpos].weapons[attweppos].type[0] == 'A' || attacker[attpos].weapons[attweppos].type[0] == 'B') &&
	(defender[defpos].weapons[defweppos].type[0] == 'S' || defender[defpos].weapons[defweppos].type[0] == 'T'))
		tri = -2;

	else if ((attacker[attpos].weapons[attweppos].type[0] == 'S' || attacker[attpos].weapons[attweppos].type[0] == 'T')
	&& defender[defpos].weapons[defweppos].type[0] == 'L')
		tri = -2;

	else if (attacker[attpos].weapons[attweppos].type[0] == 'L' &&
	(defender[defpos].weapons[defweppos].type[0] == 'A' || defender[defpos].weapons[defweppos].type[0] == 'B'))
		tri = -2;

	else if ((attacker[attpos].weapons[attweppos].type[0] == 'S' || attacker[attpos].weapons[attweppos].type[0] == 'T') &&
	(defender[defpos].weapons[defweppos].type[0] == 'A' || defender[defpos].weapons[defweppos].type[0] == 'B'))
		tri = 2;

	else if ((attacker[attpos].weapons[attweppos].type[0] == 'A' || attacker[attpos].weapons[attweppos].type[0] == 'B') &&
	(defender[defpos].weapons[defweppos].type[0] == 'L'))
		tri = 2;

	else if ((attacker[attpos].weapons[attweppos].type[0] == 'L') &&
	(defender[defpos].weapons[defweppos].type[0] == 'S' || defender[defpos].weapons[defweppos].type[0] == 'T'))
		tri = 2;
	else
		tri = 0;

	//enemy weapon triangle is the negative of the attacker's triangle
	enemytri = tri * -1;


	//Check the weapons super effective against the specfic type
	if (defender[defpos].character.type == attacker[attpos].weapons[attweppos].effective)
		effective = 3;
	else
		effective = 1;

	if(defender[defpos].weapons[defweppos].effective == attacker[attpos].character.type)
		eneffective = 3;
	else
		eneffective = 1;

	//checks the attackers weapon typing seeing if it is physical or magic to use either their strength or magic in the attack power calulations
	//attack power = character strgenth or magic + weapon might * effectiveness + weapon triangle bonus
	switch(attacker[attpos].weapons[attweppos].type[1])
	{
		//if attackers's weapon is magical does the calculation using the magic stat instead of the strength in the attack power calculation
		//uses the defender's resistance for the defense power calculation instead of the defense
		case 'M':
		{
			attpow = attacker[attpos].character.stats.magic + attacker[attpos].weapons[attweppos].might * effective + tri;
			endefpow = defender[defpos].character.stats.res;
		}

		//if the attacker's weapon is physical does the calculation using the strength stat in the attack power calculation
		//uses the defender's defense for his defense power calculation
		default:
		{
			attpow = attacker[attpos].character.stats.stg + attacker[attpos].weapons[attweppos].might * effective + tri;
			endefpow = defender[defpos].character.stats.def;
		}
	}

	//checks the defender's weapon tying to see if it physical or maigcal to use either the strength or magic in the attack power calculation
	//attack power = character strgenth or magic + weapon might * effectiveness + weapon triangle bonus
	switch(defender[defpos].weapons[defweppos].type[1])
	{
		//if defender's weapon is magical does the calculation using the magic stat instead of the strength in the attack power calculation
		//uses the attackers resistance for the defense power calculation instead of the defense
		case 'M':
		{
			enattpow = attacker[attpos].character.stats.magic + attacker[attpos].weapons[attweppos].might * effective + tri;
			defpow = defender[defpos].character.stats.res;
		}

		//if the defender's weapon is physical does the calculation using the strength stat in the attack power calculation
		//uses the attackers defense for his defense power calculation
		default:
		{
			enattpow = attacker[attpos].character.stats.stg + attacker[attpos].weapons[attweppos].might * effective + tri;
			defpow = defender[defpos].character.stats.def;
		}
	}

	//the damage is the attacker's attack power minus the defender's the defense power
	//the recoil is just the damage the attaker would take from the defender if not killed
	damage = attpow - endefpow;
	recoil = enattpow - defpow;

	//prints out an info screen to show the projected user health and damage that the characters will take if they want to switch weapons
	printf("%s\t%s", attacker[attpos].character.name, defender[defpos].character.name);
	printf("Health: %d/%d\tHealth: %d/%d", attacker[attpos].character.stats.health, defender[defpos].character.stats.health,
	attacker[attpos].character.stats.totalhealth, defender[defpos].character.stats.totalhealth);
	printf("%s\t%s", attacker[attpos].weapons[attweppos].name, defender[defpos].weapons[defweppos].name);
	printf("Damage: %d\tDamage: %d", damage, recoil);
	printf("Hit Rate: %d%%\tHit Rate: %d%%", attacker[attpos].weapons[attweppos].hitrate, defender[defpos].weapons[defweppos].hitrate);
	printf("Crit Rate: %d%%\tCrit Rate: %d%%", attacker[attpos].weapons[attweppos].critrate, defender[defpos].weapons[defweppos].critrate);

	//asks them if they want to attack knowing the attack info or not
	printf("Do you want to attack with this weapon (y or n): ");
	scanf(" %c", &answer);
	answer = toupper(answer);

	//checks if the input is correct
	while(answer != 'Y' && answer != 'N')
	{
		//prints an error message and lets them re-enter their answer
		printf("That is an invalid answer\nPlease re - enter your answer");
		printf("Do you want to attack (y or n): ");
		scanf(" %c", &answer);

		//caps all answers in case the user doesn't
		answer = toupper(answer);
	}

	if (answer == 'Y')
	{
		//calculates if they hit or miss and if they get a crit or not
		hitcrit(attacker, defender, attpos, defpos, attweppos, defweppos, &damage, &recoil);

		//does the damage to the defender and if they miss the damage is return as zero
		defender[defpos].character.stats.health -= damage;

		//if defender is kill the user is removed from the unit map
		if (defender[defpos].character.stats.health <= 0)
		{
			//marks the unit as retreated if they die and battle
			defender[defpos].character.retreated = true;

			//removes the unit from the map
			removeunit(map, defender, defpos);

			for (i = 0; i < charmax; i++)
            {
                if (!defender[i].character.retreated)
                    break;
                else if (i == (charmax - 1));
                    //gameover()
            }
		}

		//if the defender is still alive so not retreated it does an attack back
		else if (!defender[defpos].character.retreated)
			attacker[attpos].character.stats.health -= recoil;

		//if the attacking unit is not dead after the attack then labels it as retreated
		if (attacker[attpos].character.stats.health <= 0)
		{
			//labels the unit as retreated
			attacker[attpos].character.retreated = true;

			//removes the unit from the unit map
			removeunit(map, attacker, attpos);
		}

		//if not dead marks the unit as used
		else
			attacker[attpos].character.used = true;

		//returns one if the character attacked or ended the units turn
		return 1;
	}

	else if(answer == 'N')
	{
		//asks them they want to change unit or if they want to just end their turn or even select a target
		printf("Do you want to change weapons (c) or end character turn (e) or 0 to select a new attack target: ");
		scanf(" %c", &command);

		//capitals all the users commands for simplicity
		command = toupper(command);

		//if the answer is not C or E or 0 then asks them to re input a answer
		while((answer != 'C' && answer != 'E') || (isdigit(command) && command != '0'))
		{
			//prints an error message and lets the user re enter thei answer
			printf("That is an invalid answer\nPlease re - enter your answer");
			printf("Do you want to attack (y or n): ");
			scanf(" %c", &command);

			//caps the users answer
			command = toupper(command);
		}

		if (command == 'C')
		{
			//moves the characters attack weapon choice
			do
			{
				attweppos++;

				//if the attack weapon position if farther than the last weapon in the list moves it back to the beginning
				if (attweppos > weaponmax)
					attweppos = 1;

				//if there is weapon at the attack weapon position them moves it back over
				else if (attacker[attpos].weapons[attweppos].type[0] == ' ')
					attweppos++;

			//if the range of the next unit is not equal to the range that they selected for the attack target
			}while (attacker[attpos].weapons[attweppos].range[0] != range && attacker[attpos].weapons[attweppos].range[1] != range);

			//puts the new attack weapon position into the function to redo all the damage and info
			attack(attacker, defender, attpos, defpos, attweppos, defweppos, range, map, turn);
		}

		//if they want to go back and select another character
		else if (command == '0')

		//sends back 0 to identifiy that they want to select another character
			return 0;

		else if(command == 'E')
		{
			//ends the characters turn and marks them as used
			attacker[attpos].character.used = true;

			//return 1 to show that they ended their turn
			return 1;
		}
	}
}
