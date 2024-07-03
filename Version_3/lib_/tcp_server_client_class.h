#ifndef TCP_SERVER_CLLIENT_CLASS
#define TCP_SERVER_CLLIENT_CLASS

#include<string>
#include<vector>
#include<winsock2.h>
#include<iostream>
#include <ws2tcpip.h>
#include <windows.h>

class tcp_server{
    public:
    void bind_to_client(sockaddr_in& server_socket_address, 
    sockaddr_in& client_address, int server_port, SOCKET& server_sock);

    void accept_client(SOCKET& client_sock, sockaddr_in client_address,
    socklen_t client_len,SOCKET server_sock);
};

class tcp_client{
    public:
    void connect_to_server(sockaddr_in& socket_addr,int port,SOCKET& client_sock);
};

class tcp_communicate{
    public:
        void message_send(SOCKET& client_sock,const std::string& test_message);
        void input_message(std::string& message);
        std::string receive_message(SOCKET& client_sock);
        void input_mod_power(int& N,int& e);
};


#endif