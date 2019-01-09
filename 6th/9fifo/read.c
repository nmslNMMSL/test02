#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define SIZE 128

//读管道
int main(void)
{
    int fd = -1;
    int ret = -1;
    char buf[SIZE];

    //1. 以只读的方式打开一个管道文件
    fd = open("fifo", O_RDONLY);
    if (-1 == fd)
    {
        perror("open"); 
        return 1;
    }
    printf("以只读的方式打开一个管道ok....\n");

    //2. 循环读管道
    while(1)
    {
        memset(buf, 0, SIZE); 
        ret = read(fd, buf, SIZE); 
        if (ret <= 0)
        {
            perror("read"); 
            break;
        }
    
        printf("buf:%s\n", buf);
    }

    //3. 关闭文件
    close(fd);

    return 0;
}
