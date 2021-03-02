#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
    
    int ret = fork();
    
    //分流
    //父进程
    if(ret > 0)
    {
        sleep(35);
    }
    //子进程
    else if(ret == 0)
    {
        sleep(5);
    }
    else 
    {
        printf("fork error!\n");
        exit(0);
    }

    return 0;
}
