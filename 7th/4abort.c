#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

int main(void)
{
    int i = 1;

    while(1)
    {
        printf("do working %d\n", i); 

        if (4 == i)
        {
            //给自己发送一个编号为6的信号 默认的行为就是终止进程
            abort(); 
        }

    
        i++;
        sleep(1);
    }

    return 0;
}
