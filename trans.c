#include "myas.h"

int num_register(char *des)
{
	if(strstr(des,"%eax")!=NULL)
		return EAX;
	else if(strstr(des,"%ecx")!=NULL)
		return ECX;
	else if(strstr(des,"%edx")!=NULL)
		return EDX;
	else if(strstr(des,"%ebx")!=NULL)
		return EBX;
	else if(strstr(des,"%esp")!= NULL)
		return ESP;
	else if(strstr(des,"%ebp")!= NULL)
		return EBP;
	else if(strstr(des,"%esi")!= NULL)
		return ESI;
	else if(strstr(des,"%edi") != NULL)
		return EDI;
}

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
		switch(num_register(des)){
			printf("%c",'b');
		case EAX:
			printf("%x\n",EAX);
			break;
		case ECX:
			printf("%x\n",ECX);
			break;
		case EDX:
			printf("%x\n",EDX);
			break;
		case EBX:
			printf("%x\n",EBX);
			break;
		case ESP:
			printf("%x\n",ESP);
			break;
		case EBP:
			printf("%x\n",EBP);
			break;
		case ESI:
			printf("%x\n",ESI);
			break;
		case EDI:
			printf("%x\n",EDI);
			break;
		default:
			printf("error");
			break;
		}
	}
		
	
	return 1;	
}
