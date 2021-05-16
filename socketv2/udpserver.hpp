#ifndef __UDPSERVER_HPP__ 
#define __UDPSERVER_HPP__

#include "socket.hpp"

class UdpServer 
{
    private:
        Sock _sc;
        int _port;
    public:
        UdpServer(int port = 8080)
            :_port(port)
        {
            _sc.InitSock(); 
            _sc.Bind(port);
        }

        ~UdpServer()
        {}

        void Start()
        {
            char buf[1024];
            while(1)
            {
                ssize_t recvSize = _sc.Receive(buf, sizeof(buf) - 1);
                if(recvSize > 0)
                {
                    buf[recvSize] = '\0';
                    std::cout << "client: " << buf << std::endl;

                    // 发送数据做出响应
                    std::string echo(buf);
                    echo += " [server echo]";
                    _sc.Send(echo.c_str(),echo.size());
                }
                
            }
        }
};

#endif

