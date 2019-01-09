#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

//父进程杀死子进程
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

    //子进程
    if (0 == pid)
    {
        while(1) 
        {
            printf("child process do work....\n"); 
            sleep(1);
        }
    
        //进程的退出
        exit(0);
    }
    else
    {
        //父进程
        
        sleep(3);
        printf("子进程不听话了, 该退出了...\n");
        kill(pid, 15);
        printf("父进程该结束了 已经完成了他的使命\n");
    
    }

    return 0;
}
