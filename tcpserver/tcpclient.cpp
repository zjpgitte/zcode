
#include "tcpclient.hpp"
#include <stdlib.h>
static void Userage(char *argv)
{
  std::cout << argv << " ip port" << std::endl; 
  exit(0);
}

// ./tcpclient ip port
int main(int argc, char *argv[])
{
  if(argc != 3)
  {
    Userage(argv[0]);
  }

  tcpclient c(argv[1], atoi(argv[2]));
  c.InitClient();
  c.Start();

  return 0;
}
