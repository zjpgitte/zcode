#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXSIZE 1024
using namespace std;

bool CheckDup(char *cmd)
{
    //遍历字符串判断是否有>
    for(int i = 0; cmd[i]; i++)
    {

    }
}

int main()
{

    while(1)
    {
        pid_t id = fork();
        if(id < 0)
        {
            cout << "fork error!" << endl;
            exit(0);
        }
        else if(id == 0)
        {
            //child 
            //显示命令行界面 [minishell]# 
            cout << "[minishell]# ";

            //输入命令保存在cmd中
            char cmd[MAXSIZE] = {'\0'};
            fgets(cmd, MAXSIZE -1, stdin);
            cmd[strlen(cmd) - 1] = '\0';   //将读入的\n取消

            //检测是否有>进行文件冲定向
            if(CheckDup(cmd))
            {
                continue;
            }

            //解析string,将指令和参数保存到 args[] 中
            char *args[MAXSIZE / 100] = {NULL}; 
            char *ps = strtok(cmd, " ");
            int i = 0;
            while(ps)
            {
                args[i++] = ps;
                ps = strtok(NULL, " ");
            }
            //进程替换
            execvp(args[0], args);
            exit(0);
        }

        //父进程等待子进程的执行
        int status = 0;
        pid_t ret = waitpid(id, &status, 0);

        //检测等待过程是否成功
        if(ret == -1)
        {
            //函数调用失败
            cout << "wait error!" << endl;
        }
        else if(ret == id)
        {
            if(WIFEXITED(status))
            {
                //等待成功
                cout << WEXITSTATUS(status) << endl;
            }
            else 
            {
                cout << "killed by sign!" << endl;
            }
        }
    }

    return 0;
}
