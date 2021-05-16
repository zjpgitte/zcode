#pragma once 

#include "socket.hpp"

class UdpClient
{
    private:
        Sock _sc;
        std::string _ip;
        short _port;
    public:
        UdpClient(std::string ip = "127.0.0.1", short port = 8080)
            :_ip(ip), _port(port)
        {
            _sc.InitSock();
            _sc.SetEndPointAddr(_ip, _port);
        }

        void Start()
        {
            char rbuf[1024];
            while(1)
            {
                std::string buf;
                std::cin >> buf;
                _sc.Send(buf.c_str(), buf.size());

                //接收服务器响应
                ssize_t recvSize = _sc.Receive(rbuf, sizeof(rbuf) - 1);
                if(recvSize > 0)
                {
                    rbuf[recvSize] = '\0';
                    std::cout << "server: " << rbuf << std::endl;
                }
            }
        }


};
