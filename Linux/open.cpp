#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int fd = -1;
    //fd = open("text.txt",O_RDONLY); //只读模式打开，文件必须存在
    //fd = open("text.txt",O_WRONLY | O_CREAT,0755); //只写模式打开，文件不存在就创建，创建的文件权限为755
    //fd = open("text.txt",O_WRONLY | O_CREAT | O_EXCL,0755); //只写模式打开，文件不存在就创建，创建的文件权限为755，文件存在就报错，创建失败
    //fd = open("text.txt",O_RDWR | O_CREAT | O_EXCL,0755); //读写模式打开，文件不存在就创建，创建的文件权限为755，文件存在就报错，创建失败
    //fd = open("text.txt",O_WRONLY | O_CREAT | O_TRUNC,0755);//只写模式打开，文件不存在就创建，创建的文件权限为755，文件存在就清空文件内容
    fd = open("text.txt",O_WRONLY | O_APPEND); //只写和追加模式打开，文件不存在就报错
    if(fd == -1){
        printf("The file Open File");
        perror("open");
        return 1;
    }
    printf("fd = %d",fd);
    close(fd);
}