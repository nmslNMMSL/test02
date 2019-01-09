#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

//信号处理函数
void fun1(int signum)
{
    printf("捕捉到信号: %d\n", signum);
}

//信号处理函数2
void fun2(int signum)
{
    printf("捕捉到信号: %d\n", signum);
}

//信号注册函数
int main(void)
{
    int i = 0;
    int ret = -1;

    //信号集
    sigset_t set;
    sigset_t oldset;

    //信号注册
    //Ctrl + C
    signal(SIGINT, fun1); 

    //Ctrl + \ akjfdskj
    signal(SIGQUIT, fun2);

    printf("按下回车键 阻塞信号2\n");
    getchar();

    sigemptyset(&oldset);
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGQUIT);

    //设置屏蔽编号为2和3的信号
    ret = sigprocmask(SIG_BLOCK, &set, &oldset); 
    if (-1 == ret)
    {
        perror("sigprocmask"); 
        return 1;
    }
    printf("设置屏蔽编号为2的信号成功....\n");

    printf("按下回车键来获取未决的信号\n");
    getchar();

    /////////////////////////////////////////

    //获取未决的信号集
    sigemptyset(&set);
    ret = sigpending(&set);
    if (-1 == ret)
    {
        perror("sigpending"); 
        return 1;
    }

    printf("处于未决的信号有: ");
    //输出未决的信号
    for (i = 1; i < 32; i++)
    {
        if (sigismember(&set, i)) 
        {
            printf("%d ", i); 
        }
    }
    putchar('\n');

    //////////////////////////////////////////

    printf("按下回车键解除编号为2的信号的阻塞...\n");
    getchar();

    //将信号屏蔽集设置为原来的集合
    ret = sigprocmask(SIG_SETMASK, &oldset, NULL);
    if (-1 == ret)
    {
        perror("sigprocmask"); 
        return 1;
    }

    printf("按下回车键 退出....\n");
    getchar();

    return 0;
}

