#include "lib_\tcp_server_client_class.h"
#include "lib_\RSA_coding.h"
#include "lib_\multi_thread.h"
#define max_client 5

int main(int argc,char* argv[]){
    if(argc<3){
        perror("Not enough parameters.\n");
        exit(-1);
    }

    int port_to_server = atoi(argv[1]);//与server相连接
    int port_to_client = atoi(argv[2]);//提供给client的接口

    tcp_server Server;
    tcp_client Client;
    tcp_communicate Communicator;

    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);
    SOCKET server_sock,client_sock,client_sock_to_server;

    Communicator.socket_create(server_sock);
    Communicator.socket_create(client_sock_to_server);

    struct sockaddr_in socket_addr;
    Client.connect_to_server(socket_addr,port_to_server,client_sock_to_server);

    struct sockaddr_in server_socket_address,client_address;
    socklen_t client_len = sizeof(client_address);
    Server.bind_to_client(server_socket_address,client_address,port_to_client,server_sock);

    listen(server_sock, max_client);
    printf("Transister listening on %d.\n",port_to_client);
    Server.accept_client(client_sock,client_address,client_len,server_sock);

    while(true){
        transistor_handle_client handler;
        handler.Communicator = Communicator;
        handler.client_sock = client_sock;
        handler.client_sock_to_server = client_sock_to_server;
        transis_client_handle(handler);
    }

    WSACleanup();
    closesocket(server_sock);
    closesocket(client_sock_to_server);
}