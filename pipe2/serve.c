#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define SIZE 64

int main()
{
    int outfd = open("fifo", O_RDONLY);

    char buff[SIZE];

    while(1)
    {
        ssize_t readSize = read(outfd, buff, SIZE - 1);
        if(readSize == -1)
        {
            printf("read from outfd error!\n");
        }
        else if(readSize == 0)
        {
            printf("read tail!\n");
            break;
        }
        else 
        {
            buff[readSize] = 0;
            printf("%s\n", buff);
        }
    }

    return 0;
}
