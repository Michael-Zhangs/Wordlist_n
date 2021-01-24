#ifndef __WORDLIST_H
#define __WORDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

struct WL_Word
{
    char *en;
    char *zh;
    int correct;
};

struct WL_Files
{
    int* files;
    int filenum;
};

char *WL_GetItems();
unsigned int WL_GetLen(char* filename);
int WL_ListItems();
char *WL_GetName(int index);
struct WL_Word WL_GetWordFF(int serial,int index);
struct WL_Word WL_GetWord(int serial,struct WL_Files filetmp);
void WL_FreeWord(struct WL_Word wordname);

#endif
