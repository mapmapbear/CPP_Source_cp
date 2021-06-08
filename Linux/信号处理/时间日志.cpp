#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

int main(){
    time_t t = time(NULL);
    struct tm *pT = NULL;
    pT = localtime(&t);
    char buf[100];
    memset(buf,0,100);
    sprintf(buf,"%s %d%d%d%d%d%d.log", "touch ", pT->tm_year+1990, pT->tm_mon+1, pT->tm_mday, pT->tm_hour, pT->tm_min, pT->tm_sec);
    system(buf);
    printf("%s\n",buf);
}