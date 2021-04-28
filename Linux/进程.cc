#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main(){
    fork();
    printf("Hello Word\n");
    exit(0);
    //return 0;
}