#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

#define SIZE 64

//父子进程使用无名管道进行通信
//父进程写管道 子进程读管道
int main(void)
{
    int ret = -1;
    int fds[2];
    char buf[SIZE];
    pid_t pid = -1;


    //1. 创建无名管道
    ret = pipe(fds);
    if (-1 == ret)
    {
        perror("pipe"); 
        return 1;
    }

    //2. 创建子进程
    pid = fork();
    if (-1 == pid)
    {
        perror("fork"); 
        return 1;
    }

    //子进程 读管道
    if (0 == pid) 
    {
        //关闭写端
        close(fds[1]); 
        
        memset(buf, 0, SIZE);
        //读管道的内容
        ret = read(fds[0], buf, SIZE);
        if (ret < 0)
        {
            perror("read"); 
            exit(-1);
        }

        printf("child process buf: %s\n", buf);

        //关闭读端
        close(fds[0]);
        //进程退出
        exit(0);
    }

    //父进程 写管道
    //关闭读端
    close(fds[0]);

    //写管道
    ret = write(fds[1], "ABCDEGHIJK", 10);
    if (ret < 0)
    {
        perror("write"); 
        return 1;
    }

    printf("parent process write len: %d\n", ret);
    

    //关闭写端
    close(fds[1]);

    return 0;
}
