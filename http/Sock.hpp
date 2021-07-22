#pragma once 

#include "Log.hpp"
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>


enum{
  SocketErr = 1,
  SetOptErr,
  BindErr,
  ListenErr,
  AcceptErr
};

#define BACKLOG 5


class Sock{
  public:
    // 创建套接字
    static int Socket(){
      int sock = socket(AF_INET, SOCK_STREAM, 0);
      if (sock < 0) {
        //向日志打印错误信息
        std::cout << "socket error!" << std::endl;
        exit(SocketErr);

      }
      return sock;
    }

    static void SetSockOpt(int sock){
      int opt = 1;
      // 设置套接字地址课复用
      int ret = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)); 
      if (ret < 0) {
        // warning
        std::cout << "set error!" << std::endl;
        exit(SetOptErr);
      }
    }

    static void Bind(int sock, int port){
      struct sockaddr_in local;
      local.sin_family = AF_INET;
      local.sin_port = htons(port);
      local.sin_addr.s_addr = htons(INADDR_ANY);
      if (bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0) {
        //log 
        std::cout << "bind error!" << std::endl;
        exit(BindErr);
      }
    }

    static void Listen(int sock){
      if(listen(sock, BACKLOG) < 0){
        std::cout << "listen error!" << std::endl;
        exit(ListenErr);
      } 
    }

    static int Accept(int sock) {
      struct sockaddr_in peer;
      socklen_t len = sizeof(peer);
      int s = accept(sock, (struct sockaddr*)&peer, &len);
      if (s < 0) {
        //log
        std::cout << "accept error!" << std::endl;
      }


      return s;
    }

};
