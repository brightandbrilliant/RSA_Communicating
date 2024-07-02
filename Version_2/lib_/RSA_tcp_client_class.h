#ifndef _RSA_TCP_CLIENT_CLASS_H
#define _RSA_TCP_CLIENT_CLASS_H

#include<string>
#include<vector>
#include<winsock2.h>
#include<iostream>

void connect_to_server(sockaddr_in& socket_addr,int port,SOCKET& client_sock);

void message_send(SOCKET& client_sock,std::string& test_message);


#endif