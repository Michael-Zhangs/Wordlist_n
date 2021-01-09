#include <stdio.h>
#include <stdlib.h>
#include "wordlist.h"

int main()
{
	printf("Wordlist\n");
	printf("%s",WL_GetItems());
	printf("%d\n",WL_GetLen("../wordlist/1.1.txt"));
	return 0;
}
