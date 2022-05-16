#include "client.h"

void Client::vOpenConnect()
{
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0)
    {
        printf("[-]Error in connection.\n");
        exit(1);
    }
    printf("[+]Client Socket is created.\n");

    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    ret = connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    if (ret < 0)
    {
        printf("[-]Error in connection.\n");
        exit(1);
    }
    printf("[+]Connected to Server.\n");
}

void Client::vCommunicateServer()
{
    while (1)
    {
        cout << "Chon option: \n";
        cout << "1. LOGON\n";
        cout << "2. LOGOFF\n";
        cout << "3. STATUS_REQ\n";
        cout << "4. Exit\n";
        scanf("%s", &buffer[0]);
        send(clientSocket, buffer, strlen(buffer), 0);

        if (strcmp(buffer, "Exit") == 0)
        {
            close(clientSocket);
            printf("[-]Disconnected from server.\n");
            exit(1);
        }

        if (recv(clientSocket, buffer, 1024, 0) < 0)
        {
            printf("[-]Error in receiving data.\n");
        }
        if (strcmp(buffer, "LOGON") == 0)
        {
            cout << "OK\n";
        }
        if (strcmp(buffer, "LOGOFF") == 0)
        {
            cout << "OK\n";
        }
        if (strcmp(buffer, "STATUS_REQ") == 0)
        {
            cout << "Status on\n";
        }
        else
        {
            // printf("Server: \t%s\n", buffer);
        }
    }
}
