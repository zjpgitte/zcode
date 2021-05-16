#ifndef __SOCKET_HPP__
#define __SOCKET_HPP__

#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
//套接字文件类
class Sock 
{
    private:
        int _sockfd;
        sockaddr_in _selfAddr;  // 记录该socket文件自身的ip + sort 
                                // 服务器的需要指定端口号, 客户端不关心端口号由操作系统随机分配 
        sockaddr_in _endPointAddr; // 记录通信对端的 ip + sort
        
        socklen_t _endPointLen;
    public:
        
        Sock(short port = 8080)
            :_sockfd(-1)
             ,_endPointLen(sizeof(_endPointAddr))
        {
            
        }
        ~Sock()
        {
            close(_sockfd);
        }

        bool SetEndPointAddr(const std::string& ip, short port)
        {
            _endPointAddr.sin_family = AF_INET;
            _endPointAddr.sin_port = htons(port);
            _endPointAddr.sin_addr.s_addr = inet_addr(ip.c_str());
        }
        
        void InitSock()
        {
            //创建 UDP、ipv4类型的socket
            _sockfd = socket(AF_INET, SOCK_DGRAM, 0);
            std::cout << "socket: " << _sockfd << std::endl;
        }

        //服务器端的socket文件需要显式绑定ip + sort
        void Bind(int port = 8080)
        {
            _selfAddr.sin_family = AF_INET;
            _selfAddr.sin_port = htons(port);
            _selfAddr.sin_addr.s_addr = 0;  //ip用0表示接收来自本主机任意ip的数据

            if(bind(_sockfd, (struct sockaddr*)&_selfAddr, sizeof(_selfAddr)) == -1)
            {
                std::cerr << "bind error!" << std::endl;
            }

        }

        //接收数据
        ssize_t Receive(char *buf, int bufSize)
        {
            
            // 接收数据时同时可以拿到对端的 sockaddr(ip+sock)， 目的是为了给对端发送消息。
            // 最后一个参数，既是把自己的sockaddr长度拿过去，又作为输出形参数获取对端sockaddr。
            ssize_t recvSize = recvfrom(_sockfd, buf, bufSize, 0, (struct sockaddr*)&_endPointAddr, &_endPointLen);

            
            return recvSize;
        }

        void Send(const char *buf, int bufSize)
        {
            sendto(_sockfd, buf, bufSize, 0, (struct sockaddr*)&_endPointAddr, _endPointLen);
        }

};

#endif

