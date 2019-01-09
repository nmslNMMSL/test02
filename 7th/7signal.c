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

    //信号注册
    //Ctrl + C
    signal(SIGINT, fun1); 

    //Ctrl + \ akjfdskj
    signal(SIGQUIT, fun2);


    while(1)
    {
        getchar(); 
        //sleep(1);
    }

    return 0;
}

