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

class Client
{
public:
   int clientSocket, ret;

   struct sockaddr_in serverAddr;
   char buffer[1024];

   void vOpenConnect();
   void vCommunicateServer();
};
