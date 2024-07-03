#ifndef _MULTI_THREAD_H
#define _MULTI_THREAD_H

#include<string>
#include<vector>
#include<winsock2.h>
#include<iostream>
#include<ws2tcpip.h>
#include<windows.h>
#include<mutex>
#include<thread>
#include "tcp_server_client_class.h"

typedef struct transistor_handle_client{
    SOCKET client_sock;
    SOCKET client_sock_to_server;
    tcp_communicate Communicator;
}transistor_handle_client;

void transis_client_handle(transistor_handle_client handler);

#endif