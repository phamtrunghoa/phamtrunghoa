#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>

using namespace std;

#define PORT 4444

class Server
{
public:
   int sockfd, ret;
   struct sockaddr_in serverAddr;

   int newSocket;
   struct sockaddr_in newAddr;

   socklen_t addr_size;
   char buffer[1024];

   pid_t childpid;

   void vCreateServer();
   void vConnectClient();
};
