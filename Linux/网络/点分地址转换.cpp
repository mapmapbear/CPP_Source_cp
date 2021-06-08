#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    char buf[] = "192.168.1.1";
    unsigned int num = 0;
    inet_pton(AF_INET, buf, &num);
    unsigned char *p = (unsigned char*)&num;
    printf("%d %d %d %d\n",*p,*(p+1),*(p+2),*(p+3));
    char ip[16];
    inet_ntop(AF_INET, &num, ip, 16);    
    return 0;
}