#ifndef __WORDLIST_H
#define __WORDLIST_H

#include <stdio.h>
#include <stdlib.h>

char *WL_GetItems();
unsigned int WL_GetLen(char* filename);
int WL_ListItems();
char *WL_GetName(int index);

#endif
