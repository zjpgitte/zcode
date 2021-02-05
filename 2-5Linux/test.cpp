#include <iostream>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main()
{
    
   // while(1)
   // {
   //     cout << "pid:" << getpid() << "       ppid:"<< getppid() << endl;
   //     sleep(1);
   // }

   // cout << "before fork" << endl;
   // printf("ppid:%d   pid:%d\n",getpid(),getppid());
    
    //调用fork函数，产生的进程和旧进程代码共享，但是数据不同。
   // fork();
   // 
   // cout << "after fork" << endl;
   // //fork之后的代码，新进程和老进程共享，各自都会执行一遍。
   // printf("ppid:%d   pid:%d\n",getpid(),getppid());
    
    //查看 fork 函数返回值
    printf("ppid: %d     pid: %d\n",getppid(), getpid());

    pid_t ret = fork();
    
    if(ret == 0)
    {
        
        cout << "child:" << endl;
        printf("ppid: %d     pid: %d     ret:%d   temp:%d\n", getppid(), getpid(), ret);
        sleep(35);
    }
    else if(ret > 0)
    {
        int count = 0;
        cout << "parent:" << endl;
        printf("ppid: %d     pid: %d     ret:%d   temp:%d\n", getppid(),  getpid(), ret);
        sleep(5); 
    }
    else 
    {
        cout << "fork error" << endl;
        exit(0);
    }
    sleep(1);
    return 0;

}
