#include "gametypes.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "rangecheck.h"
#define charmax 6
#define maxx 25
#define weaponmax 10

void healchar(int rangelist[], gamecharwep plist[], int charnum, gamemap map[][25], int xcord, int ycord)
{
	char selected, alpha, choice;
	int i, pos, heal, wandpos, count, offset;
	bool invalid = true;


	if ((strcmp(map[ycord + 1][xcord].tile, "00")) != 0)
		withinrange(rangelist, (ycord + 1), xcord, map, plist, &count);

	else if ((strcmp(map[ycord - 1][xcord].tile, "00")) != 0)
		withinrange(rangelist, (ycord + 1), xcord, map, plist, &count);

	else if ((strcmp(map[ycord][xcord - 1].tile, "00")) != 0)
		withinrange(rangelist, (ycord + 1), xcord, map, plist, &count);

	else if ((strcmp(map[ycord][xcord + 1].tile, "00")) != 0)
		withinrange(rangelist, (ycord + 1), xcord, map, plist, &count);

    while (invalid)
    {
		for (i = 0; i < charmax; i++)
		{
			pos = rangelist[i];
			if (pos != 100)
			{
				if (!plist[pos].character.retreated && !plist[pos].character.used)
				{
					offset++;
					alpha = (char)(64 + offset);
					printf("%c) %s\n", alpha, plist[i].character.name);
				}
			}
		}

        printf("Which character would you like to heal with your %s? (for A enter a or A): ", plist[charnum].character.name);
        scanf(" %c", &selected);
        selected = toupper(selected);

        while (((int)(selected) > (int)alpha) || (isdigit(selected) && selected != '0'))
        {
            printf("This is an invalid option\nPlease re-enter a choice from between A to - %c: ", alpha);
            scanf(" %c", &selected);
            selected = toupper(selected);
        }

        for (i = 0; i < weaponmax; i++)
        {
            if (plist[charnum].weapons[i].type[0] == 'W')
            {
                offset++;
                alpha = (char)(64 + offset);
                printf("%c) %s\n", alpha, plist[charnum].weapons[i].name);
            }
        }

        printf("Which staff would you like to use to heal your %s or enter 0 to go back to character selection: ", &plist[selected].character.name);
        scanf(" %c", &choice);
        choice = toupper(choice);

        while (((int)(choice) > (int)alpha) || (isdigit(choice) && choice != '0'))
        {
            printf("This is an invalid option\nPlease re-enter a choice from between A to - %c or 0 to go back to character heal selection: ", alpha);
            scanf(" %c", &choice);
            choice = toupper(choice);
        }

        if (choice == '0')
            continue;

        choice = ((int)choice) - 65;

        for (i = 0; i < weaponmax; i++)
        {
            if (plist[charnum].weapons[i].type[0] == 'W')
            {
                if (choice == 0)
                    wandpos = i;
                else if (choice > 0)
                    choice--;
            }
        }

        invalid = false;
    }



    heal = plist[charnum].character.stats.magic + plist[charnum].weapons[wandpos].might;

    plist[selected].character.stats.health += heal;

    if (plist[selected].character.stats.health > plist[selected].character.stats.totalhealth)
        plist[selected].character.stats.health = plist[selected].character.stats.totalhealth;

    plist[charnum].character.used = true;
}
