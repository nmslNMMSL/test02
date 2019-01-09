#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>




//int execlp(const char *file, const char *arg, .../* (char  *) NULL */);
// int execl(const char *path, const char *arg, .../* (char  *) NULL */);

int main(void)
{
    printf("hello itcast\n");

    //arg0 arg1 arg2 ... argn
    //arg0一般是可执行文件名  argn必须是NULL
    //等价于执行ls -l /home
    //execlp("ls", "ls", "-l", "/home", NULL);
    
    //第一个参数是可执行文件的绝对路径或者相对路径
    //第二个参数一般是可执行文件的名字
    //中间的参数就是可执行文件的参数
    //最后一个参数是NULL 
    execl("/bin/ls", "ls", "-l", "/home", NULL);

    printf("hello world\n");

    return 0;
}
