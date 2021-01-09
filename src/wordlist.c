#include "wordlist.h"

char *WL_GetItems()
{
	system("ls ../wordlist > ../tmp/Items");
	FILE *ItFP;
	ItFP=fopen("../tmp/Items","r");
	char ch = fgetc(ItFP);
	while(ch != EOF)
		ch=fgetc(ItFP);
	unsigned int n=ftell(ItFP);
	char *sp = (char*)malloc(n);
	rewind(ItFP);
	fread(sp,n,1,ItFP);
	fclose(ItFP);
	return sp;
}

unsigned int WL_GetLen(char* filename)
{
	FILE *LnFP;
	LnFP=fopen(filename,"r");
	if(LnFP==NULL)
	{
		printf("No such a file\n");
		return 0;
	}
	char ch = fgetc(LnFP);
	unsigned int len=0;
	while(ch != EOF)
	{
		if(ch=='\n')
			len++;
		ch = fgetc(LnFP);
	}
	fclose(LnFP);
	return len;
}
