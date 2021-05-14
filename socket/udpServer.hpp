#pragma once 
#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


class UdpServer
{
    public:
        UdpServer(std::string ip = "127.0.0.1", int port = 8080)
            :_ip(ip), _port(port)
        {
        }

        ~UdpServer()
        {
            close(_sockfd);
        }

        // 初始化服务器
        void InitServer()
        {
            //创建网络文件
            _sockfd = socket(AF_INET, SOCK_DGRAM, 0);
            std::cout << "_sockfd " << _sockfd << std::endl;

            struct sockaddr_in  addr;
            addr.sin_family = AF_INET;
            addr.sin_port = htons(_port);
            addr.sin_addr.s_addr = inet_addr(_ip.c_str()); 
            int len = sizeof(addr);

            // 绑定, 将软件服务器和自己的硬件ip和端口号绑定
            int bindRet = bind(_sockfd, (struct sockaddr*)&addr, len);
            if(bindRet < 0)
            {
                std::cerr << "bind error!" << std::endl;
                exit(1);
            }

        }

        void start()
        {
            char buf[64];
            while(1)
            {
                sockaddr_in peer; // 保存远端地址信息
                socklen_t len;

                //从远端接收数据（包括远端的ip和port），存放在buf中， 类似于从文件读。
                ssize_t recvSize = recvfrom(_sockfd, buf, sizeof(buf)-1, 0, (struct sockaddr*)&peer, &len);
                if(recvSize == -1)
                {
                    std::cerr << "recvfrom" << std::endl;
                    exit(1);
                }
                buf[recvSize] = 0;

                std::cout << "recive " << buf << std::endl;

                //回应远端，向远端发送数据
                std::string echo_string(buf);
                echo_string += "[server echo]";
                sendto(_sockfd, echo_string.c_str(), echo_string.size(), 0, (struct sockaddr*)&peer, len);
            }
        }

    private:
         // ip + port 可以确定网络中唯一进程
         // 该ip和端口号是客户端的ip和端口号
        std::string _ip; // ip地址 ，确定网络中唯一一台主机
        int _port; // 端口号， 用来确定主机中唯一一个进程  
        int _sockfd; // 网络文件描述符
};
