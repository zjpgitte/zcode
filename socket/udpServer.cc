#include "udpServer.hpp"

int main()
{
    UdpServer s;
    s.InitServer();
    s.start();

    return 0;
}
