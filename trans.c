#include "myas.h"

int instr_trans(char *op, char *args, char* mcode)
{
	// check syntax 
	char *poppy;
	char *des;
	char str[128];
	
	strcpy(str,args);
	poppy = strtok(str,",");
	des = strtok(NULL , "\0");

	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}

	if(poppy[0] == '%' && des[0] == '%')
		strcpy(mcode , "89");
	else if((poppy[0] == '(' && des[0] =='%') || (poppy[0] == '-' && des[0] == '%'))
		strcpy(mcode , "8b");
	else if(poppy[0] == '0' && strstr(des,"%eax") != NULL)
		strcpy(mcode , "a1");
	else if(strstr(poppy,"%eax") != NULL && des[0] == '0')
		strcpy(mcode , "a3");
	else if(poppy[0] == '$' && des[0] == '%')
	{
		strcpy(mcode , "b8");
	}
		
	
	return 1;	
}
