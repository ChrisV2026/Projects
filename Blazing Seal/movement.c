#include <stdio.h>
#include <stdbool.h>
#include "gametypes.h"
#include <stdlib.h>
#include <ctype.h>
#include "graphic move.h"
#include "heal.h"
#include <string.h>
#include "rangecheck.h"
#include "attack.h"

#define charmax 6
#define maxx 25
#define weaponmax 10

void move(gamecharwep plist[], char terremap[][maxx], gamemap map[][maxx], int attweppos, gamecharwep opplist[], int turn)
//make a array that can hold my character type)
{
	bool invalid = false, finished = false;
	char answer, choice, command, alpha, selected, response;
	int move, rangelist[charmax] = {100,100,100,100,100,100}, count = 0, i, n;
	int charnum = 0, offset, movex, movey, xcord, ycord, pos, defpos = 0, deltax, defweppos = 0;
	int deltay, range, check;
	bool rng2 = false, rng1 = false, allmoved = false, done = false, cannotmove = false, correctchoice = false, healposs = false;

	while (!allmoved)
	{
		offset = 0;
		invalid = true;
		rng1 = false;
		rng2 = false;
		healposs = false;
		correctchoice = false;

		if (done)
		{
			printf("Are you sure you want to end your turn without fully moving all your units (Y or N): ");
			scanf(" %c", &answer);
			answer = toupper(answer);

			do
			{
				if (answer != 'Y' && answer != 'N')
				{
					printf("\nThis is an invalid answer\nPlease re-enter your response with Y for yes and N for no: ");
					scanf(" %c", &answer);
					answer = toupper(answer);
				}

				else if (answer == 'Y')
				{
					finished = true;
					break;
				}

				else if (answer == 'N')
				{
					finished = false;
					done = false;
					break;
				}

			} while (answer != 'Y' && answer != 'N');
		}

		if (finished)
			break;

		for (n = 0; n < charmax; n++)
		{

			if (!plist[n].character.retreated && !plist[n].character.used)
            {
                offset++;
                alpha = (char)(64 + offset);
				printf("%c) %s\n", alpha, plist[n].character.name);
            }
		}


		printf("Which character would you to move? (for A) enter a or A or 0 to end turn): ");
		scanf(" %c", &choice);

        choice = toupper(choice);

		while (((int)(choice) > (int)alpha) || (isdigit(choice) && choice != '0'))
		{
			printf("This is an invalid option\nPlease re-enter a choice from between A to - %c or 0 to end turn: ", alpha);
			scanf(" %c", &choice);
			choice = toupper(choice);
		}

		if (choice == '0')
		{
			allmoved = true;
			continue;
		}

		choice = ((int)(choice)) - 65;

		for (i = 0; i < charmax; i++)
		{
			if (!plist[i].character.retreated && !plist[i].character.used)
			{
				if (choice == 0)
					charnum = i;
				else if (choice > 0)
					choice--;
			}
		}

		printf("\nWhere do you want to move your");

		printf("%s (W for up, S for down, A for left and D for right or 0 to go back to character choice): ", plist[charnum].character.name);

		scanf(" %c", &command);
		command = toupper(command);

		while (invalid)
		{
			while ((command != 'W' && command != 'A' && command != 'S' && command != 'D') || (isdigit(command) && command != '0'))
			{
				printf("This is an invalid option\n");
				printf("Please re-enter a choice either W for up, S for down, A for left and D for right or 0 to go back to character choice: ");
				scanf(" %c", &command);
				command = toupper(command);
			}

			if (command == '0')
				continue;

			if (command == 'W')
			{
				movex = 0;
				movey = 1;

				if (plist[charnum].position[0] == 'A')
					cannotmove = true;
			}

			else if (command == 'S')
			{
				movex = 0;
				movey = -1;

				if (plist[charnum].position[0] == 'Y')
					cannotmove = true;
			}

			else if (command == 'A')
			{
				movex = -1;
				movey = 0;

				if (plist[charnum].position[0] == 'A')
					cannotmove = true;
			}

			else if (command == 'D')
			{
				movex = 1;
				movey = 0;

				if (plist[charnum].position[0] == 'Y')
					cannotmove = true;
			}

			xcord = (int)(plist[charnum].position[1]) - 65;
			ycord = (int)(plist[charnum].position[0]) - 65;

			if (terremap[ycord + movey][xcord + movex] == 'W')
				cannotmove = true;

			else if ((terremap[ycord + movey][xcord + movex] == 'V' ||
			terremap[ycord + movey][xcord + movex] == 'M' || terremap[ycord + movey][xcord + movex] == 'R')
			&& plist[charnum].character.type != 'F')
				cannotmove = true;

			if (cannotmove)
			{
				printf("You can't move there");
				printf("Please re-enter a choice either W for up, S for down, A for left and D for right");
				printf("or 0 to go back to character choice: ");
				scanf(" %c", &command);
				command = toupper(command);
				cannotmove = false;
				continue;
			}

			invalid = false;
		}

        //mapmove(xcord, ycord, command, turn, plist[charnum].character.charinits);
        //royces function (xcord, ycord, command, turn, &plist[charnum].character.charinits);

		plist[charnum].position[0] = (char)(((int)plist[charnum].position[0]) + movey);
		plist[charnum].position[1] = (char)(((int)plist[charnum].position[1]) + movex);

		if ((terremap[ycord][xcord] == 'D'||terremap[ycord][xcord] == 'F') && plist[charnum].character.type != 'F')
		{
			plist[charnum].character.stats.movesleft--;
		}

		if (plist[charnum].character.stats.movesleft <= 0)
		{
			plist[charnum].character.stats.movesleft = plist[charnum].character.stats.move;
			plist[charnum].character.used = true;
		}

		printf("Do you want to end character turn (E) or attack (A)");
		for (i = 0; i < weaponmax; i++)
		{
			if (plist[charnum].weapons[i].type[0] == 'W')
				healposs = true;
		}

		if (healposs)
			printf(" or heal (H)");

		printf(": ");

		scanf(" %c", &response);
		response = toupper(response);

		while ((response != 'A' && response != 'E') || (healposs && response != 'H'))
		{

			printf("This is an invalid option\nPlease re-enter a choice either E for end turn or A for attack ");

			if (healposs)
				printf("or H for heal");

			printf(": ");
			scanf(" %c", &response);
			response = toupper(response);
		}

		if (healposs && response == 'H')
		{
			healchar(rangelist, plist, charnum, map, xcord, ycord);
			continue;
		}


		for (i = 0; i < weaponmax; i++)
		{
			if (plist[charnum].weapons[i].range[0] == 2 || plist[charnum].weapons[i].range[1] == 2)
			{
				rng2 = true;
				break;
			}
		}

		for (i = 0; i < weaponmax; i++)
		{
			if (plist[charnum].weapons[i].range[0] == 1 || plist[charnum].weapons[i].range[1] == 1)
			{
				rng1 = true;
				break;
			}
		}

		if (rng1)
		{
			if ((strcmp(map[ycord + 1][xcord].tile, "00")) != 0)
				withinrange(rangelist, (ycord + 1), xcord, map, opplist, &count);
			else if ((strcmp(map[ycord - 1][xcord].tile, "00")) != 0)
				withinrange(rangelist, (ycord + 1), xcord, map, opplist, &count);
			else if ((strcmp(map[ycord][xcord - 1].tile, "00")) != 0)
				withinrange(rangelist, (ycord + 1), xcord, map, opplist, &count);
			else if ((strcmp(map[ycord][xcord + 1].tile, "00")) != 0)
				withinrange(rangelist, (ycord + 1), xcord, map, opplist, &count);
		}

		if (rng2)
		{
			if ((strcmp(map[ycord + 2][xcord].tile, "00")) != 0)
				withinrange(rangelist, (ycord + 2), xcord, map, opplist, &count);
			else if ((strcmp(map[ycord - 1][xcord - 1].tile, "00")) != 0)
				withinrange(rangelist, (ycord - 1), (xcord - 1), map, opplist, &count);
			else if ((strcmp(map[ycord - 1][xcord + 1].tile, "00")) != 0)
				withinrange(rangelist, (ycord - 1), (xcord + 1), map, opplist, &count);
			else if ((strcmp(map[ycord][xcord - 2].tile, "00")) != 0)
				withinrange(rangelist, ycord, (xcord - 2), map, opplist, &count);
			else if ((strcmp(map[ycord][xcord + 2].tile, "00")) != 0)
				withinrange(rangelist, ycord, (xcord + 2), map, opplist, &count);
			else if ((strcmp(map[ycord + 1][xcord - 1].tile, "00"))!= 0)
				withinrange(rangelist, (ycord + 1), (xcord - 1), map, opplist, &count);
			else if ((strcmp(map[ycord + 1][xcord + 1].tile, "00")) != 0)
				withinrange(rangelist, (ycord + 1), (xcord + 1), map, opplist, &count);
			else if ((strcmp(map[ycord - 2][xcord].tile, "00")) != 0)
				withinrange(rangelist, (ycord - 2), xcord, map, opplist, &count);
		}

		while (!correctchoice)
		{
			for (i = 0; i < charmax; i++)
			{
				pos = rangelist[i];
				if (pos != 100)
				{
					if (!opplist[pos].character.retreated && !opplist[pos].character.used)
					{
						offset++;
						alpha = (char)(64 + offset);
						printf("%c) %s\n", alpha, &opplist[i].character.name);
					}
				}
			}


			printf("Which character would you like to attack with your %s? (for A enter a or A): ", &plist[charnum].character.name);
			scanf(" %c", &selected);

			while (((int)(toupper(selected)) > (int)alpha) || (isdigit(choice) && selected != '0'))
			{
				printf("This is an invalid option\nPlease re-enter a choice from between A to - %c: ", alpha);
				scanf(" %c", &selected);
				selected = toupper(selected);
			}

			selected = ((int)selected - 65);
			defpos = rangelist[selected];

			deltay = abs((int)opplist[defpos].position[0] - (int)plist[charnum].position[0]);
			deltax = abs((int)opplist[defpos].position[1] - (int)plist[charnum].position[1]);

			range = deltax + deltay;

			check = attack(plist, opplist, charnum, defpos, attweppos, defweppos, range, map, turn);

			if (check == 0)
			{
				continue;
			}

			else if (check == 1)
			{
				correctchoice = true;
			}


			for (i = 0; i < charmax; i++)
			{
				if (!plist[i].character.used)
					break;
				else if (i == charmax - 1)
					allmoved = true;
			}
		}
	}
}


