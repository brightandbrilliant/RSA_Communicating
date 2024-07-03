#include "lib_\tcp_server_client_class.h"
#include "lib_\RSA_coding.h"

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

    server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(server_sock==-1){
        perror("Failed to create server socket.\n");
        exit(-1);
    }

    client_sock_to_server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(client_sock_to_server ==-1){
        perror("Failed to create client socket.\n");
        exit(-1);
    }

    struct sockaddr_in socket_addr;
    Client.connect_to_server(socket_addr,port_to_server,client_sock_to_server);

    struct sockaddr_in server_socket_address,client_address;
    socklen_t client_len = sizeof(client_address);
    Server.bind_to_client(server_socket_address,client_address,port_to_client,server_sock);

    listen(server_sock, max_client);
    printf("Transister listening on %d.\n",port_to_client);
    Server.accept_client(client_sock,client_address,client_len,server_sock);
    bool begin_flag=true;

    while(true){
        if(begin_flag){
            std::cout<<"You are connected to the server now.\n";
            begin_flag = false;
        }

        std::string receive_server_message = 
            Communicator.receive_message(client_sock_to_server);
        Communicator.message_send(client_sock,receive_server_message);

        std::string receive_client_message = 
            Communicator.receive_message(client_sock);
        Communicator.message_send(client_sock_to_server,receive_client_message);

        printf("Message from client: %s\n",receive_client_message.c_str());
    }

}