#include "myas.h"

int is_mem(char *args)		// is args mem?
{
	if(strstr(args,"0x") != NULL)	// args have "0x"
		return 1;
	else if(strstr(args,"(") != NULL) // args have "("
		return 1;
	else
		return 0;
}

int is_immediate(char *args)	// is args immediate?
{
	if(args[0] == '$')	// args[0] is '$'
		return 1;
	else
		return 0;
}

int is_valid(char *op, char *args)	// is args valid?
{
	//printf("if valid, return 1\n");
	//printf("otherwise, return 0\n");

	char *poppy;	// source
	char *des;	// destination
	char str[128];	// put args

	strcpy(str,args);
	poppy = strtok(str,",");
	des = strtok(NULL , "\0");

	if(is_mem(poppy) == 1)	// when poppy is mem
	{
		if(is_mem(des) == 1)	// when des is mem
			return 0;
		else			// when des is not mem
			return 1;
	}

	else if(is_immediate(des) == 1)	// when des is immediate
		return 0;
	else				// when des is not immediate
		return 1;
}
