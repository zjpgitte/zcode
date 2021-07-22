
#pragma once 

#include <iostream>
#include "Sock.hpp"
#include <pthread.h>



class HttpServer{
  private:
    int _lsock; // listen sock
    short _port; 
  public:
    HttpServer(short port)
       :_lsock(-1)
        ,_port(port)
    {
    }

    void InitServer(){
      _lsock = Sock::Socket();
      Sock::SetSockOpt(_lsock);
      Sock::Bind(_lsock, _port);
      Sock::Listen(_lsock);
    }

    static void *Routine(void *args){
      pthread_detach(pthread_self());
      int sock = *(int*)args;
      delete (int*)args;

      int *exit_code = new int(0);
      char buffer[10240];
      ssize_t s = recv(sock, buffer, sizeof(buffer), 0);    
      if (s < 0){
        pthread_exit(exit_code);
      }
      else if (s == 0) {
        close(sock);     
      }
      else {
        buffer[s] = 0;
        std::cout << buffer << std::endl;
      }
      close(sock);

      return exit_code;

    }


    void Start(){
      while(true) {
        int sock = Sock::Accept(_lsock);
        if (sock < 0) {
          continue;
        }

        std::cout << "get a new link ... " << sock << std::endl; 

        // 创建线程服务该套接字。epoll
        pthread_t tid; 
        int* s = new int(sock);
        pthread_create(&tid, nullptr, Routine, s);

        std::cout << tid << std::endl;
        
      }
    }
};
