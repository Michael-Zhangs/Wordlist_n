#include <stdio.h>
#include <stdlib.h>
#include "wordlist.h"

void ListItems()
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
}

int main()
{
	printf("Wordlist\n");
	ListItems();
	//printf("%d\n",WL_GetLen("../wordlist/1.1.txt"));
	return 0;
}
