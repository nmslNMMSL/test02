#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void fun(int signo)
{
    printf("捕捉到信号:%d\n", signo);
    printf("有子进程退出....\n");

    //非阻塞方式
    while((waitpid(-1, NULL, WNOHANG)) >  0)
    {
    }
}

int main(void)
{
    pid_t pid = -1;

    struct sigaction act;

    act.sa_handler = fun;
    act.sa_flags = 0;

    //注册信号处理函数
    sigaction(SIGCHLD, &act, NULL);

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
        printf("子进程比较累, 先休息两秒钟...\n");
        sleep(2); 
        printf("子进程休息好了, 太无聊了, 就退出了..\n");

        exit(0);
    }
    else
    {
        //父进程    
        while(1)
        {
            printf("父进程do working...\n"); 
            sleep(1);
        }
    }

    return 0;
}
