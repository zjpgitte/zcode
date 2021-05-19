#include "tcpserver.hpp"

static void Usage(char *argv)
{
  std::cout << argv << " port" << std::endl;
  exit(0);
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
      Usage(argv[0]);
    }
    tcpserver c(atoi(argv[1]));

    c.InitServer();

    c.Start();

    return 0;
}
