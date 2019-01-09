#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

//用于创建无名管道
int main(void)
{
    int fds[2];
    int ret = -1;

    //创建一个无名管道
    ret = pipe(fds);
    if (-1 == ret)
    {
        perror("pipe"); 
        return 1;
    }

    //fds[0]用于读  fds[1]用于写
    printf("fds[0]: %d  fds[1]: %d\n", fds[0], fds[1]);

    //查看管道的缓冲区的大小
    printf("pipe size: %ld\n", fpathconf(fds[0], _PC_PIPE_BUF));
    printf("pipe size: %ld\n", fpathconf(fds[1], _PC_PIPE_BUF));

    //关闭文件描述符
    close(fds[0]);
    close(fds[1]);

    return 0;
}
