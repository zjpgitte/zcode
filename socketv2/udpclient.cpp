#include "udpclient.hpp"

using namespace std;

int main()
{
    UdpClient c("127.0.0.1", 8080);

    c.Start();

}
