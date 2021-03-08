#include <iostream>
#include <unistd.h>
#include <string.h>
using namespace std;

int main(int argc, char *argv[], char *env[])
{
    printf("%s\n",getenv("MYENV"));
   // printf("%s",getenv("PATH"));
   // for(int i = 0; i < argc; i++)
   // {
   //     cout << "argv[" << i << "]" << ":" << argv[i] << endl;
   // }

   // if(strcmp(argv[1], "-a") == 0)
   // {
   //     printf("-a\n");
   // }
   // else 
   // {
   //     printf("else\n");
   // }
   // for(int i = 0; env[i] ; i++)
   // {
   //     printf("env[%d]:%s\n", i, env[i]);
   // }
   //cout << "I am running!" << endl;
   // while(1)
   // {
   //     sleep(2);
   // }

    return 0;
}
