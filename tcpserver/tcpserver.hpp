#pragma once

#include <sys/socket.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string>

#define BACKLOG 5

class tcpserver{
    private:
        int _sock;
        short _port;
        int _listen;
    public:
        tcpserver(short port = 8080)
            :_port(port)
        {

        }

        void InitServer()
        {
            _sock = socket(AF_INET, SOCK_STREAM, 0);
            sockaddr_in local;
            local.sin_family = AF_INET;
            local.sin_port = htons(_port);
            local.sin_addr.s_addr = htonl(INADDR_ANY);
            if(bind(_sock, (struct sockaddr*)&local, sizeof(local)) == -1)
            {
                std::cerr << "bind Error!" << std::endl;
                exit(1);
            }
            listen(_sock, BACKLOG);
        }

        static void server(int sock)
        {
            char buf[64];
            while(true)
            {
                ssize_t rsize = recv(sock, buf, sizeof(buf) - 1, 0); 
                if(rsize > 0)
                {
                    buf[rsize] = '\0';
                    std::cout << "client: " << buf << std::endl;
                    std::string echo = buf;
                    echo += "[server]";
                    std::cout << echo << std::endl;
                    send(sock, echo.c_str(), echo.size(), 0);
                }
                else if(rsize == 0)
                {
                    
                  std::cout << "a connection shutdown" << std::endl;
                 return ;
                  //exit(1);
                    
                }
                else 
                {
                    std::cerr << "recv error!" << std::endl;
                    return ;
                    //exit(1);
                }
            }
        
        }

        static void *ServerRoutine(void* args)
        {
          pthread_detach(pthread_self());
          int sock = *((int*)args);
          server(sock);
        }

        void Start()
        {
            sockaddr_in peer;
            socklen_t peerLen = sizeof(peer);

            while(1)
            {
                _listen = accept(_sock, (struct sockaddr*)&peer, &peerLen);
                if(_listen == -1)
                {
                  std::cerr << "bind error" << std::endl;
                  continue;
                }
                std::cout << "listen " << _listen << " get a new connect ..."<<std::endl;

                int *plisten = new int(_listen);
                pthread_t tid;
                pthread_create(&tid, nullptr, ServerRoutine, plisten);

                //if(fork() == 0)
                //{
                //  close(_sock);
                //  server(_listen);
                //}
                //close(_listen);
                
            }

            

        }


};
