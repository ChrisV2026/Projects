#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "file read lines.h"
#include "gametypes.h"
#include "duplicate.h"
#include <time.h>
#include <ctype.h>

#define charmax 6

//Character Info
//Class Weapon Health Stg Magic Skill Luck Speed Def Res Move Name

//Weapons info
//ty rng rng mgt hit crit eff name

/*void clonechar(gamecharwep str2[], int charpos2, gamechar str1[], int charpos1)
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
}*/
//returns 0 if it doesn't work and 1 if it did

int cwselect(gamecharwep p1list[], gamecharwep p2list[])
{
	FILE *fp, *fp2;
	gamechar charlist[20] = {};
	gameweapon weplist[30] = {};
	char alpha, answer, choice, command[10] = {}, selected;
	int count = 0, i, n, picksp1 = 0, picksp2 = 0, j, weppoints, p1wepnum, p2wepnum, offset;
	bool finished = false, repeated = false, p1turn = false, p2turn = false, invalid = true, done = false;

	fp = fopen("Character info.txt", "r");
	fp2 = fopen("Weapons info.txt", "r");

	if (fp == NULL || fp2 == NULL)
	{
		//make sure to keep this up to date with all the notepad files we need to put in the same folder as the game*********************
		printf("Cannot open file\nTo make sure game works have file Character info.txt and Weapon.txt in the same folder as the game");
		return 0;
	}

	printf("\n\n\t\t----------------------------------------------------------------------------------\n");
	printf("\t\t|                               Character List                                    |\n");
	printf("\t\t----------------------------------------------------------------------------------\n\n\n");

	fscanf(fp, "%s\t", charlist[count].charinits);

	do
	{
		fscanf(fp,"%c\t%s\t", &charlist[count].type, charlist[count].wepinits);
		fscanf(fp,"%d\t%d\t%d\t%d\t",&charlist[count].stats.health, &charlist[count].stats.stg, &charlist[count].stats.magic, &charlist[count].stats.skill);
		fscanf(fp,"%d\t%d\t%d\t%d", &charlist[count].stats.luck,&charlist[count].stats.spd, &charlist[count].stats.def, &charlist[count].stats.res);
		fscanf(fp,"\t%d\t", &charlist[count].stats.move);

		//because the other one does not replace \n with \0
		filereadline(fp, charlist[count].name);

		printf("%s\n", charlist[count].name);
		printf("Health: %d\tStrength: %d\tMagic: %d\t", charlist[count].stats.health, charlist[count].stats.stg, charlist[count].stats.magic);
		printf("Skill: %d\tLuck: %d\tSpeed: %d\n", charlist[count].stats.skill, charlist[count].stats.luck, charlist[count].stats.spd);
		printf("Defense: %d\tResistence: %d\tMovement: %d\t", charlist[count].stats.def, charlist[count].stats.res, charlist[count].stats.move);
		printf("Weapons: ");
		for (i = 0; i < 2; i++)
		{
			switch (charlist[count].wepinits[i])
			{
				case 'A':
				{
					printf("Axes");
					break;
				}
				case 'B':
				{
					printf("Bows");
					break;
				}
				case 'L':
				{
					printf("Lances");
					break;
				}
				case 'S':
				{
					printf("Swords");
					break;
				}
				case 'T':
				{
					printf("Tomes");
					break;
				}
				case 'W':
				{
					printf("Staffs");
					break;
				}
				case 'N':
					break;
			}
			printf(" ");
		}

			printf("\tUnit Type: ");

			////////////////////////////////////add any class that are out standing and change some like mage if needed
			switch (charlist[count].type)
			{
				case 'A':
				{
					printf("Armored");
					break;
				}
				case 'F':
				{
					printf("Flying");
					break;
				}
				case 'H':
				{
					printf("Horse Riders");
					break;
				}
				case 'M':
				{
					printf("Mage");
					break;
				}
				case 'S':
				{
					printf("Solider");
					break;
				}
		}

		printf("\n\n");
		count++;

	}while(fscanf(fp, "%s\t", charlist[count].charinits) != EOF);

	printf("The character draft will commence when you are ready\n");

	//Instructions to the draft format
	printf("This will be in standard draft format\n");

	/*contemplating on taking out
	printf("Meaning that it will consist of alternating turns for picking a character starting with Player 1\n");
	printf("Each character will only be able to be picked once by one player\n");
	printf("This process will be done until each player has 6 characters\n");
	*/

	printf("Enter anything character when you are ready to start the draft\n");
	printf("Otherwise scroll up to view stats and enter any letter when ready\n");
	printf("Ready? ");
	scanf("%s", command);

	printf("\t\t----------------------------------------------------------------------------------\n");
	printf("\t\t|                                   Draft Time                                   |\n");
	printf("\t\t----------------------------------------------------------------------------------\n\n\n");


	for (i = 1; i <= (charmax * 2); i ++)
	{
		if (i % 2 == 0 && !p2turn)
		{
			printf("\n\n--------------Player 2's pick--------------\n\n");
			p2turn = true;
		}
		else if(i % 2 != 0 && !p1turn)
		{
			printf("\n\n--------------Player 1's pick--------------\n\n");
			p1turn = true;
		}

		printf("Character Selection List:\n");
		for (n = 0; n >= 0; n++)
		{

			if (!isalpha(charlist[n].charinits[0]))
				break;
			alpha = (char)(65 + n);
			for (j = 0; j < 6; j++)
			{
				if ((strcmp(charlist[n].charinits, p1list[j].character.charinits) == 0) ||
				(strcmp(charlist[n].charinits, p2list[j].character.charinits) == 0))
					break;

				//when j gets to it's last iteration and it has not found that the character has already been chosen and is in players list
				//prints character names as an option
				else if(j == 5)
					printf("%c) %s\n", alpha, &charlist[n].name);
			}
		}

		printf("\nTo see stats scroll up\n");


		printf("Which character would you like to select (for A) enter a or A): ");
		scanf(" %c", &choice);

		while (((int)(toupper(choice)) > (int)alpha) || isdigit(choice))
		{
			printf("This is an invalid option\nPlease re-enter a choice from between A to - %c: ", alpha);
			scanf(" %c", &choice);
		}

		//takes inputted letter and sets A to equal the value of zero and b as two and so on to find the corresponding character in the list
		//by using the positions as the first character is at position zero in the array
		choice = ((int)(toupper(choice))) - 65;

		for (n = 0; n < charmax; n++)
		{
			if ((strcmp(charlist[choice].charinits, p1list[n].character.charinits) == 0) ||
			(strcmp(charlist[choice].charinits, p2list[n].character.charinits)) == 0)
			{
				repeated = true;
				printf("\nThe character %s has already been selected\nPlease pick another character\n\n ", &charlist[choice].name);
				i--;
				break;
			}
		}

		if (repeated)
		{
			repeated = false;
			continue;
		}

		else if (p2turn)
		{
			clonechar(p2list, picksp2, charlist, choice);
			picksp2++;
			p2turn = false;
		}

		else if(p1turn)
		{
			clonechar(p1list, picksp1, charlist, choice);
			picksp1++;
			p1turn = false;
		}
	}

	printf("\n\n\t\t----------------------------------------------------------------------------------\n");
	printf("\t\t|                                Draft Time Over                                  |\n");
	printf("\t\t----------------------------------------------------------------------------------\n\n\n");

	printf("Player 1's Team:\t\tPlayer 2's Team:\n");

	///////////////////////////////////////////printf out which people each person has picked not working
	for (i = 0; i < 6; i++)
	{
		printf("%-20s\t\t%-20s\n", &p1list[i].character.name, &p2list[i].character.name);
	}

	printf("After this it will be weapon selection time\n");
	printf("Enter any letter when ready: ");
	scanf("%s", command);
	printf("\nTime to pick weapons");



	printf("\n\n\t\t----------------------------------------------------------------------------------\n");
	printf("\t\t|                                  Armoury                                        |\n");
	printf("\t\t----------------------------------------------------------------------------------\n\n\n");



	count = 0;
	fscanf(fp2, "%s\t", &weplist[count].type);

	do
	{
		fscanf(fp2, "%d\t%d\t%d\t", &weplist[count].range[0], &weplist[count].range[1], &weplist[count].might);
		fscanf(fp2, "%d\t%d\t%d\t", &weplist[count].hitrate, &weplist[count].critrate, &weplist[count].cost);
		fscanf(fp2,"%c\t", &weplist[count].effective);

		//////////////////////////////no \n after the last word so it screws up
		filereadline(fp2, weplist[count].name);

		printf("%s\n", &weplist[count].name);

		printf("Weapon Type: ");

		if (weplist[count].type[1] == 'P')
			printf("Physical ");
		else if (weplist[count].type[1] == 'M')
			printf("Magical ");

		switch (weplist[count].type[0])
		{
			case 'A':
			{
				printf("Axe");
				break;
			}
			case 'B':
			{
				printf("Bow");
				break;
			}
			case 'L':
			{
				printf("Lance");
				break;
			}
			case 'S':
			{
				printf("Sword");
				break;
			}
			case 'T':
			{
				printf("Tome");
				break;
			}
			case 'W':
			{
				printf("Staff");
				break;
			}
			printf(" ");
		}

		printf("\n");

		//to explain a little bit more what the might stat is on the staffs
		if (weplist[count].type[0] == 'W')
			printf("Base Heal Strength/");
		printf("Might: %d\tRange: %d", weplist[count].might, weplist[count].range[0]);

		if(weplist[count].range[1] != 0)
			printf(" - %d", weplist[count].range[1]);
		printf("\t");

		printf("Hit Rate: %d\tCritical Rate: %d\n", weplist[count].hitrate, weplist[count].critrate);
		printf("Effective Against: ");

		switch(weplist[count].effective)
		{
			case 'A':
			{
				printf("Armored Units");
				break;
			}
			case 'F':
			{
				printf("Flying Units");
				break;
			}
			case 'H':
			{
				printf("Horse Riding Units");
				break;
			}
			case 'M':
			{
				printf("Mage Units");
				break;
			}
			case 'S':
			{
				printf("Solider Units");
				break;
			}
			case 'N':
			{
				printf("No Units");
				break;
			}
		}

		printf("\n\n");
		count++;

	} while(fscanf(fp2, "%s\t", &weplist[count].type) != EOF);


	printf("What would you to like to purchase from the armoury");

	//////////////////////////////////////////////////////////have to explain wands so if it has a W it has to have different prints statements


	for (i = 1; i <= 2; i++)
	{
		if (i % 2 != 0)
		{
			p1turn = true;
			p2turn = false;
		}
		else if (i % 2 == 0)
		{
			p2turn = true;
			p1turn = false;
		}

		if (p1turn)
			printf("\n\n--------------Player 1's turn--------------\n\n");
		else if (p2turn)
			printf("\n\n--------------Player 2's turn--------------\n\n");

		weppoints = 2000;
		done = false;
		finished = false;
		offset = 0;

		while (weppoints > 0)
		{
			offset = 0;
			invalid = true;

			if (done)
			{
				printf("\nYou will not be able to change or get more weapons for your characters after this section\n");
				printf("Are you sure you want to leave the Armoury (Y or N): ");
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
						printf("Thank you for shopping at the Armoury");
						finished = true;
						break;
					}

					else if (answer == 'N')
					{
						finished = false;
						done = false;
						printf("\n\n");
						break;
					}

				} while (answer != 'Y' && answer != 'N');
			}

			if (finished)
				break;


			for (n = 0; n < charmax; n++)
			{
				alpha = (char)(65 + n);
				printf("%c)", alpha);

				if (p1turn)
					printf("%s\n", &p1list[n].character.name);
				else if (p2turn)
					printf("%s\n", &p2list[n].character.name);
			}


			printf("\nWeapon points left: %d\n", weppoints);
			printf("Which character would you like to buy a weapon for? (Scroll up to see weapons stats)");
			printf("For option A enter a or A or 0 to leave the shop: ");
			scanf(" %c", &choice);

			while (((int)(toupper(choice)) > (int)alpha) || (isdigit(choice) && choice != '0'))
			{
				printf("This is an invalid option\nPlease re-enter a choice from between A to - %c or 0 to leave the shop: ", alpha);
				scanf(" %c", &choice);
			}

			if (choice == '0')
			{
				done = true;
				continue;
			}

			choice = ((int)(toupper(choice)) - 65);

			///////////have zero cost weapons that are weak for each class like a branch for a sword, old book for tome, log for lance
			printf("\nWeapon Selection List:\n");

			for (n = 0; n >= 0; n++)
			{
				if (!isalpha(weplist[n].type[0]))
				{
					///////////////////////////////////////// (word better) to make sure that the letter count moves back one after it's over
					break;
				}

				if (p1turn)
				{
					if (weplist[n].type[0] == p1list[choice].character.wepinits[0] || weplist[n].type[0] == p1list[choice].character.wepinits[1])
					{
						offset++;
						alpha = (char)(64 + offset);
						printf("%c) %s Cost: %d WP\n", alpha, weplist[n].name, weplist[n].cost);
					}
				}

				else if (p2turn)
				{
					if (weplist[n].type[0] == p2list[choice].character.wepinits[0] || weplist[n].type[0] == p2list[choice].character.wepinits[1])
					{
						offset++;
						alpha = (char)(64 + offset);
						printf("%c) %s Cost: %d WP\n", alpha, weplist[n].name, weplist[n].cost);
					}
				}
			}

			printf("\nWeapon points left: %d\n", weppoints);
			printf("What weapon would you like to buy for your");

			if (p1turn)
				printf("%s (for A enter a or A or 0 to go back to character selection): ", &p1list[choice].character.name);
			else if (p2turn)
				printf("%s (for A enter a or A or 0 to go back to character selection): ", &p2list[choice].character.name);

			scanf(" %c", &selected);
			printf("\n");

			while (invalid)
			{
				while (((int)(toupper(selected)) > (int)alpha) || (isdigit(selected) && selected != '0'))
				{
					printf("This is an invalid option\nPlease re-enter a choice from between A to - %c or 0 to quit: ", alpha);
					scanf(" %c", &selected);
				}

				if (selected == '0')
					break;

				/////////////////////////////////////////////////////////////////setting a at one
				selected = ((int)(toupper(selected))) - 65;


				for (n = 0; n >= 0; n++)
				{
					if (selected == 0 && p1turn &&
					(weplist[n].type[0] == p1list[choice].character.wepinits[0] || weplist[n].type[0] == p1list[choice].character.wepinits[1]))
					{
						if (weppoints < weplist[n].cost)
						{
							printf("You don't have sufficent weapon points to buy this item\n");
							printf("Please pick a weapon that costs that cost less or equal to %d WP\n", weppoints);
							printf("For A enter a or A or 0 to go back to character selection: ");
							scanf(" %c", &selected);
							printf("\n");
							break;
						}

						invalid = false;

						clonewep(p1list, choice, p1wepnum, weplist, n);
						p1wepnum++;
						weppoints = weppoints - weplist[n].cost;
						break;
					}

					else if (selected == 0 && p2turn &&
					(weplist[n].type[0] == p2list[choice].character.wepinits[0] || weplist[n].type[0] == p2list[choice].character.wepinits[1]))
					{
						if (weppoints < weplist[n].cost)
						{
							printf("You don't have sufficent weapon points to buy this item\n");
							printf("Please pick a weapon that costs that cost less or equal to %d WP\n", weppoints);
							printf("For A enter a or A or 0 to go back to character selection: ");
							scanf(" %c", &selected);
							printf("\n");
							break;
						}

						invalid = false;

						clonewep(p2list, choice, p2wepnum, weplist, n);
						p2wepnum++;
						weppoints = weppoints - weplist[n].cost;
						break;
					}

					else if (p1turn)
					{
						if(weplist[n].type[0] == p1list[choice].character.wepinits[0] || weplist[n].type[0] == p1list[choice].character.wepinits[1])
							selected--;
					}

					else if (p2turn)
					{
						if(weplist[n].type[0] == p2list[choice].character.wepinits[0] || weplist[n].type[0] == p2list[choice].character.wepinits[1])
							selected--;
					}
				}
			}
		}
	}
	return 1;
}
