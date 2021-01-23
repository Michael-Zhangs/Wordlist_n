#include <stdio.h>
#include <stdlib.h>
#include "wordlist.h"

int main()
{
	printf("Wordlist\n");
	char *buf=WL_GetItems;
	int i=0,j=1;
	printf("%d.",j++);
	while(*(buf+i)!='\0')
	{
		if(*(buf+i)=='\n')
			printf("\n%d.",j++);
		printf("%s",(buf+i++));
	}
	//printf("%d\n",WL_GetLen("../wordlist/1.1.txt"));
	return 0;
}
