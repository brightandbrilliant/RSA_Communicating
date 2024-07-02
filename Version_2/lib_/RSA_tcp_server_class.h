#ifndef _RSA_TCP_SERVER_CLASS
#define _RSA_TCP_SERVER_CLASS

#include<string>
#include<vector>
#include<winsock2.h>
#include<iostream>
#include <ws2tcpip.h>
#include <windows.h>


void bind_to_client(sockaddr_in& server_socket_address, 
    sockaddr_in& client_address,
    int server_port, SOCKET& server_sock);

void message_send(SOCKET& client_sock,std::string test_message);

void accept_client(SOCKET& client_sock, sockaddr_in client_address,socklen_t client_len,SOCKET server_sock);

#endif