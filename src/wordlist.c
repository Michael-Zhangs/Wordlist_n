#include "wordlist.h"

char *WL_GetName(int index)
{
	char *buf;
	int i=0;
	buf=WL_GetItems();
	int t=index;
	t--;
	while(t>0)
	{
		while(*(buf+i++)!='\n');
		t--;
	}
	//printf("%s",(buf+i));//For debug	
	char fn[100];
	int n=0;
	while(*(buf+i+n)!='\0'&&*(buf+i+n)!='\n')
	{
		fn[n]=*(buf+i+n);
		n++;
	}
	fn[n]='\0';
	char ft[100]="../wordlist/";
	int j=0;
	while(j<=n)
	{
		ft[12+j]=fn[j];
		j++;
	}
	char* sp=(char*)malloc(n+12);
	for(n+=12;n>=0;n--)
	{
		*(sp+n)=ft[n];
	}
	return sp;
}

int WL_ListItems()
{
	char *buf;
	buf=WL_GetItems();
	int i=0,j=1;
	int ff=0;
	while(*(buf+i)!='\0')
	{
		if((*(buf+i)=='\n'||ff==0)&&*(buf+i+1)!='\0')
		{
			if(ff==0)
				ff=1;
			else
				i++;
			printf("\n%d.",j++);
		}
		printf("%c",*(buf+i));
		i++;
	}
	j--;
	return j;
}

char *WL_GetItems()//remember ro free it
{
	system("ls ../wordlist | grep .txt > ../tmp/Items");//warining , here has been changed for debug
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
