#include <stdio.h>
#include <stdlib.h>
#include "wordlist.h"

int main()
{
	printf("Wordlist\n");
	int len,wordlen=0;
	len=WL_ListItems();
	int a=1;
	int selections[100];
	int selen=0;
	while(a!=0)
	{
		printf("\nselect units(0 to confirm)");
		scanf("%d",&a);
		if(a!=0)
		{
			selections[selen]=a;
			selen++;
			char *tp = WL_GetName(a);
			//printf("%s",tp);//For debug
			wordlen+=WL_GetLen(tp);
			free(tp);
		}
		if(a>len||a<0)
		{
			printf("Number out of range");
			return 0;
		}
		if(a!=0)
		{
			WL_ListItems();
		}
	}
	/* Debug space*/
	struct WL_Word test = WL_GetWordFF(10,1);
	printf("%d,%s",wordlen,test.en);
	WL_FreeWord(test);

	return 0;
}
