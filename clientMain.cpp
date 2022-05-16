#include "client.h"

int main()
{
    Client client;
    client.vOpenConnect();
    client.vCommunicateServer();
    return 0;
}
