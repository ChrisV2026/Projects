#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void filereadline(FILE *stream, char str[])
{
	char ch;
	int count = 0; 
	
	while((ch = (getc(stream))) != '\n')
	{				
		*(str + count) = ch;
		count++;
	}
	
	*(str + count) = '\0';
}
