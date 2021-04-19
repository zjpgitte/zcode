#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define SIZE 64


//int main()
//{
//    int pipefd[2];
//
//    pipe(pipefd);
//
//    if(fork() == 0)
//    {
//        //child
//        int second = 5;
//        while(second--)
//        {
//            close(pipefd[0]);
//            char *str = "hello parent!";
//            write(pipefd[1], str, strlen(str));
//            sleep(1);
//        }
//        exit(0);
//    }
//
//    close(pipefd[1]);
//
//    char buff[SIZE] ;
//
//    while(1)
//    {
//        ssize_t size = read(pipefd[0], buff, SIZE);
//        if(size == -1)
//        {
//            printf("read error!\n");
//        }
//        else if(size == 0)
//        {
//            break;
//        }
//        else 
//        {
//            printf("%s\n", buff);
//        }
//    }
//
//    return 0;
//}
