#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
using namespace std;
int main()
{
    int fd = open("file.txt", O_CREAT | O_WRONLY, 0644);



    //cout << "fd: " << fd << endl;

    char *buff = "hello world!";

    ssize_t retSize = write(fd, buff, strlen(buff));
    if(retSize == -1)
    {
        perror("write");
    }
    close(fd);

    fd = open("file.txt", O_RDONLY);

    char buff2[64] = {0};

    ssize_t s = read(fd, buff2, 63); 
    if(s == -1)
    {
        //读取失败
        perror("read");
    }
    else if(s < 63)
    {
        //读取到文件结尾
        printf("end of file!");
    }
    else 
    {
        //读取成功
        printf("read success!");
    }

    //dup2(fd, 1);

    //cout << buff << endl;
    
    

    return 0;
}
