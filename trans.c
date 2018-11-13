#include "myas.h"

int num_register(char *des)	// what is des's register_num?
{
	if(strcmp(des,"%eax")==0)
		return EAX;
	else if(strcmp(des,"%ecx")==0)
		return ECX;
	else if(strcmp(des,"%edx")==0)
		return EDX;
	else if(strcmp(des,"%ebx")==0)
		return EBX;
	else if(strcmp(des,"%esp")==0)
		return ESP;
	else if(strcmp(des,"%ebp")==0)
		return EBP;
	else if(strcmp(des,"%esi")==0)
		return ESI;
	else if(strcmp(des,"%edi")==0)
		return EDI;
}

int instr_trans(char *op, char *args, char* mcode)
{
	// check syntax 
	char *poppy;	// source
	char *des;	// destination
	char str[128];	// put args
	
	strcpy(str,args);
	poppy = strtok(str,",");
	des = strtok(NULL , "\0");

	if(!is_valid(op, args)){ // args is not valid
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}

	if(poppy[0] == '%' && des[0] == '%')	// reg to reg
		strcpy(mcode , "89");
	else if((poppy[0] == '(' && des[0] =='%') || (poppy[0] == '-' && des[0] == '%')) // mem to reg
		strcpy(mcode , "8b");
	else if(poppy[0] == '0' && strstr(des,"%eax") != NULL) // mem to reg(eax)
		strcpy(mcode , "a1");
	else if(strstr(poppy,"%eax") != NULL && des[0] == '0') // reg(eax) to mem
		strcpy(mcode , "a3");
	else if(poppy[0] == '$' && des[0] == '%')	// immediate to reg
	{
		switch(num_register(des)){
		case EAX:
			strcpy(mcode , "b8");
			break;
		case ECX:
			strcpy(mcode , "b9");
			break;
		case EDX:
			strcpy(mcode , "ba");
			break;
		case EBX:
			strcpy(mcode , "bb");
			break;
		case ESP:
			strcpy(mcode , "bc");
			break;
		case EBP:
			strcpy(mcode , "bd");
			break;
		case ESI:
			strcpy(mcode , "be");
			break;
		case EDI:
			strcpy(mcode , "bf");
			break;
		default:
			printf("error");
			break;
		}
	}
	else	// exception
		return 0;
	
	return 1;	
}
