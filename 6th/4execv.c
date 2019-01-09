#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

//int execv(const char *path, char *const argv[]);
//int execvp(const char *file, char *const argv[]);
//int execle(const char *path, const char *arg, ... /*, (char *) NULL, char * const envp[] */);


//进程替换
int main(void)
{
    //ls -l /home
    char *argv[] = {"ls", "-l", "/home", NULL};
    char *envp[] = {"ADDR=BEIJING", NULL};

    printf("hello itcast\n");

    //第一个参数是可执行文件
    //第二个参数是指针数组 最后一定以NULL结束
    //execvp("ls", argv);   

    //第一个参数是可执行文件的路径
    //第二个参数是指针数组 最后一定以NULL结束
    //execv("/bin/ls", argv);

    //最后一个参数是环境变量指针数组
    //execle("/bin/ls", "ls", "-l", "/home", NULL, envp);

    //第一个参数是可执行文件
    //第二个参数是参数列表 指针数组
    //第三个参数是环境变量列表 指针数组
    execvpe("ls", argv, envp);
     
    printf("hello world\n");

    return 0;
}
