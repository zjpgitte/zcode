#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

int main()
{
    pid_t id = fork();

    if(id < 0)
    {
        cout << "fork error" << endl;
        return 1;
    }
    if(id == 0) //child
    {
        int second = 0;
        while(second++ < 5)
        {
            cout << "I am child process" << endl;
            sleep(1);
        }
        exit(2);
    }

    int status = 0; // 获取进程退出码
    pid_t ret = waitpid(id, &status, 0);
    if(ret == -1)
    {
        printf("wait error\n");
    }
    else 
    {
        int ifExit = status & 0x0f;
        if(ifExit == 0)
        {
            cout << "exitcode:" << (status >> 8 & 0x0f) << endl;
        }
        else 
        {
            cout << "killed by sign" << endl;
        }
    }
        
    return 0;
}
