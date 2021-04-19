#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define SIZE 64

int main()
{
   if(mkfifo("fifo", 0644) == -1)
   {
       printf("mkfifo error!\n");
   }
   
   int infd = open("fifo", O_CREAT | O_WRONLY);

   char buff[SIZE];

   while(1)
   {
       ssize_t readSize = read(0, buff, SIZE);
       if(readSize == -1)
       {
           printf("read from stdin error!\n");
       }
       else if(readSize == 0)
       {
           break;
       }
       else 
       {
           buff[readSize - 1] = 0;
           write(infd, buff, strlen(buff));
       }
   }

    return 0;
}
