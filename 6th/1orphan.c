#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

//孤儿进程: 父进程退出了, 子进程还在执行
int main(void)
{
    pid_t pid = -1;

    //创建一个子进程
    pid = fork();
    if (-1 == pid)
    {
        perror("fork"); 
        return 1;
    }

    //父进程
    if (pid > 0)
    {
        printf("父进程休息一秒钟然后退出...\n"); 
        sleep(1);
        printf("父进程太累了, 先退出了...\n");
        exit(0);
    }

    //子进程
    while(1)
    {
        printf("子进程不停的工作  ppid: %d\n", getppid()); 
        sleep(1); 
    }

    return 0;
}
