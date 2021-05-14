#pragma once 
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


class UdpClient
{
    public:
        UdpClient(std::string ip = "127.0.0.1", int port = 8080)
            :_ip(ip), _port(port)
        {
        }

        ~UdpClient()
        {
            close(_sockfd);
        }

        // 初始化客户端
        void InitClient()
        {
            //创建网络文件
            _sockfd = socket(AF_INET, SOCK_DGRAM, 0);
            std::cout << "_sockfd " << _sockfd << std::endl;

            //客户端不需要绑定
            //struct sockaddr_in  addr;
            //addr.sin_family = AF_INET;
            //addr.sin_port = htons(_port);
            //addr.sin_addr.s_addr = inet_addr(_ip.c_str()); 
            //int len = sizeof(addr);

            //// 绑定, 将软件服务器和自己的硬件ip和端口号绑定
            //int bindRet = bind(_sockfd, (struct sockaddr*)&addr, len);
            //if(bindRet < 0)
            //{
            //    std::cerr << "bind error!" << std::std::endl;
            //    exit(1);
            //}

        }

        void start()
        {
            char buf[64];
            while(1)
            {
                std::cin >> buf;
                struct sockaddr_in server;
                server.sin_family = AF_INET;
                server.sin_port = htons(_port);
                server.sin_addr.s_addr = inet_addr(_ip.c_str());
                socklen_t len = sizeof(server);
                //客户端想服务器发送消息
                sendto(_sockfd, buf, strlen(buf), 0, (struct sockaddr*)&server, len);

                ssize_t size = recvfrom(_sockfd, buf, sizeof(buf)-1, 0, (struct sockaddr*)&server, &len);
                buf[size] = '\0';
                if(size > 0)
                {
                    std::cout << buf << std::endl;
                }

            }
        }

    private:
         // ip + port 可以确定网络中唯一进程
         // 该ip和端口号是客户端的ip和端口号
        std::string _ip; // ip地址 ，确定网络中唯一一台主机
        int _port; // 端口号， 用来确定主机中唯一一个进程  
        int _sockfd; // 网络文件描述符
};
