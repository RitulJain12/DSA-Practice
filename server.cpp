#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {

    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (sockaddr*)&server, sizeof(server));

    listen(server_socket, 5);

    cout << "Server running on port 8080..." << endl;

    while(true)
    {
        sockaddr_in client_addr;
        int c = sizeof(client_addr);

        int client_socket = accept(server_socket,(sockaddr*)&client_addr,&c);

        char buffer[3000];

        int bytes = recv(client_socket, buffer, 3000, 0);
        buffer[bytes] = '\0';

        cout << "Client Request:\n" << buffer << endl;

        string response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "\r\n"
        "<h1>Hello from C++ Server</h1>";

        send(client_socket, response.c_str(), response.size(), 0);

        closesocket(client_socket);
    }

    closesocket(server_socket);
    WSACleanup();

    return 0;
}