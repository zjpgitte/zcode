#include "udpserver.hpp"

using namespace std;

int main()
{
    UdpServer s(8080);

    s.Start();

    return 0;
}
