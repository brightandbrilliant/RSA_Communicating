#include "..\lib_\RSA_tcp_server_class.h"


void bind_to_client(sockaddr_in& server_socket_address, 
    sockaddr_in& client_address,
    int server_port, SOCKET& server_sock){
    server_socket_address.sin_family = AF_INET;
    server_socket_address.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    server_socket_address.sin_port = htons(server_port);
    

    int bind_ = bind(server_sock, 
    (struct sockaddr*) &(server_socket_address),
    sizeof(struct sockaddr));
}

void message_send(SOCKET& client_sock,std::string test_message){
    send(client_sock,test_message.c_str(),test_message.length(),0);
};

void accept_client(SOCKET& client_sock, sockaddr_in client_address,socklen_t client_len,
    SOCKET server_sock){
        client_sock = accept(server_sock, 
        (struct sockaddr*)&client_address, &client_len);

        if(client_sock<0){
            perror("Failed to accept.\n");
            exit(-1);
        }
}