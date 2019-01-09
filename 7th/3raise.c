#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>


//自己给自己发送一个信号
int main(void)
{
    int i = 1;

    while(1)
    {
        printf("do working %d\n", i); 
    
        //自己给自己发送一个信号
        if (i == 4)
        {
            //自己给自己发送编号为15的信号
            kill(getpid(), SIGTERM);
            //等价于以上kill
            //raise(SIGTERM); 
        }

        i++;
        sleep(1);
    }
    

    return 0;
}
