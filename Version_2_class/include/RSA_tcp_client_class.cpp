#include "..\lib_\RSA_tcp_client_class.h"

 void connect_to_server(sockaddr_in& socket_addr,int port,SOCKET& client_sock){
    socket_addr.sin_family = AF_INET;
    socket_addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    socket_addr.sin_port = htons(port);
    int connect_ = connect(client_sock, (sockaddr*) &(socket_addr),sizeof(socket_addr));
    if(connect_ == -1){
        perror("Failed to connect with the server.\n");
        exit(-1);
    }
    return;
}

void message_send(SOCKET& client_sock,std::string& test_message){
    send(client_sock,test_message.c_str(),test_message.length(),0);
}