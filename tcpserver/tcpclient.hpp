
#pragma once 
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <algorithm>

class tcpclient
{
  private:
    int _sock;
    std::string _ser_ip;
    short _ser_port;
  public:
    tcpclient(std::string ip = "127.0.0.1", short port = 8080)
      :_ser_ip(ip), _ser_port(port)
    {}

    void InitClient(){
      _sock = socket(AF_INET, SOCK_STREAM, 0);
    }

    void Start(){
      sockaddr_in seraddr;
      seraddr.sin_family = AF_INET;
      seraddr.sin_port = htons(_ser_port);
      seraddr.sin_addr.s_addr = inet_addr(_ser_ip.c_str());
      if(connect(_sock, (struct sockaddr*)&seraddr, sizeof(seraddr)) == -1)
      {
        std::cerr << "connect error!" << std::endl;
        exit(1);
      }

      std::string buf;
      char rbuf[64];
      while(true)
      {
        std::cout << "please Enter # " ;
        fflush(nullptr);
        getline(std::cin, buf);
        send(_sock, buf.c_str(), buf.size(), 0);

        ssize_t rsize = recv(_sock, rbuf, sizeof(rbuf)-1, 0);
        if(rsize > 0)
        {
          rbuf[rsize] = '\0';
          std::cout << "server echo # " << rbuf << std::endl;
        }
        else if(rsize == 0)
        {
          std::cout << "not connection" << std::endl;
          exit(1);
        }
        else 
        {
          std::cout << "client recv error!" << std::endl;
          exit(1);
        }
      }


    }

    ~tcpclient(){
      close(_sock);
    }

};
