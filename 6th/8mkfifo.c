#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>

//通过mkfifo函数创建一个管道文件
int main(void)
{
    
    int ret = -1;

    //创建一个有名管道 管道的名字fifo
    ret = mkfifo("fifo", 0644);
    if (-1 == ret)
    {
        perror("mkfifo"); 
        return 1;
    }

    printf("创建一个有名管道ok...\n");

    return 0;
}
