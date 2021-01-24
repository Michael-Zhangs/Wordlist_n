#include <stdio.h>
#include <fcntl.h>
#include "http/http_download.h"
#define BUF_SIZE 1024 // the version length must be smaller than buf_size

int checkversion()
{
    http_download("http://1149e7e4.nat5.nsloop.com/wordlist/version","../tmp/version");
    int openFlags;
    char prebuf[BUF_SIZE],onlbuf[BUF_SIZE];
    openFlags = O_RDONLY;
    int fd,num1,num2;
    fd=open("version",openFlags);
    num1=read(fd,prebuf,BUF_SIZE);
    if(num1==-1)
    {
        printf("ERROR while reading the version\n");
        return 1;
    }
    else
        prebuf[num1]='\0';
    if(close(fd)==-1)
    {
        printf("ERROR while closing the file\n");
        return 1;
    }
    fd=open("../tmp/version",openFlags);
    num2=read(fd,onlbuf,BUF_SIZE);
    if(num2==-1)
    {
        printf("ERROR while reading the version\n");
        return 1;
    }
    else
        onlbuf[num2]='\0';
    if(close(fd)==-1)
    {
        printf("ERROR while closing the file\n");
        return 1;
    }
    //printf("\n%s\n%s\n\n",prebuf,onlbuf);
    for(int a=0;prebuf[a]!='\0'||onlbuf[a]!='\0';a++)
    {
        if(prebuf[a]!=onlbuf[a])
            return 1;
    }
    return 0;
}

int update()
{
    if(http_download("http://1149e7e4.nat5.nsloop.com/wordlist/wordlist","wordlist")==-1)
        return -1;
    http_download("http://1149e7e4.nat5.nsloop.com/wordlist/version","version");
    return 0;
}

int main()
{
    if(checkversion()==1)
    {
        printf("Not the lastest version,updating\n");
        if(update()==-1)
            printf("Update error\n");
    }
    execve("wordlist",0,0);
    return 0;
}