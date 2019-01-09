#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

//僵尸进程: 子进程结束了, 父进程没有回收其资源
int main(void)
{
    int i = 0;

    pid_t pid = -1;

    //创建一个子进程
    pid = fork();
    if (-1 == pid)
    {
        perror("fork"); 
        return 1;
    }

    //子进程
    if (0 == pid)
    {
        for (i = 0; i < 5; i++)        
        {
            printf("子进程做事 %d\n", i); 
            sleep(1);
        }

        printf("子进程想不开了, 结束了自己...\n");

        //子进程退出
        exit(0); 
    }

    sleep(100);
    printf("父进程睡醒了 父进程退出....\n");

    return 0;
}
