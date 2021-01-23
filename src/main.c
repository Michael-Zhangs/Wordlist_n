#include <stdio.h>
#include <stdlib.h>
#include "wordlist.h"

int main()
{
	printf("Wordlist\n");
	int len;
	len=WL_ListItems();
	printf("\nselect units(c to confirm)");
	int a;
	scanf("%d",&a);
	if(a>len||a<1)
	{
		printf("Number out of range");
		return 0;
	}
	printf("%s",WL_GetName(a));
	return 0;
}
