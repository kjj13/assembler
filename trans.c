#include "myas.h"

int is_mem(char *args)
{
		return 1;
}

int is_immediate(char *args)
{
		return 1;
}

int is_valid(char *op, char *args)
{
	//printf("if valid, return 1\n");
	//printf("otherwise, return 0\n");

	char *poppy;
	char *des;
	char str[128];

	strcpy(str,args);
	poppy = strtok(str,",");
	des = strtok(NULL , "\0");

	if(is_mem(poppy) == 1)
	{
		if(is_mem(des) == 1)
			return 0;
		else
			return 1;
	}

	else if(is_immediate(des) == 1)
		return 0;
	else
		return 1;
}
