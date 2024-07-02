#include "..\lib_\tcp_server_client_class.h"


void tcp_server::accept_client(SOCKET& client_sock, sockaddr_in client_address,socklen_t client_len,
    SOCKET server_sock){
        client_sock = accept(server_sock, 
        (struct sockaddr*)&client_address, &client_len);

        if(client_sock<0){
            perror("Failed to accept.\n");
            exit(-1);
        }
}

void tcp_server::bind_to_client(sockaddr_in& server_socket_address, 
    sockaddr_in& client_address,
    int server_port, SOCKET& server_sock){
    server_socket_address.sin_family = AF_INET;
    server_socket_address.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    server_socket_address.sin_port = htons(server_port);
    
    int bind_ = bind(server_sock, 
    (struct sockaddr*) &(server_socket_address),
    sizeof(struct sockaddr));
}




 void tcp_client::connect_to_server(sockaddr_in& socket_addr,int port,SOCKET& client_sock){
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


void tcp_communicate::message_send(SOCKET& client_sock,const std::string& test_message){
    send(client_sock,test_message.c_str(),test_message.length(),0);
};

void tcp_communicate::input_message(std::string& message){
    std::cout<<"Please input your message:\n";
    getline(std::cin,message);
    return;
};

std::string tcp_communicate::receive_message(SOCKET& client_sock){
    char recv_[1024];
    memset(recv_, 0, 1024);
    recv(client_sock,recv_,1024,0);
    return std::string(recv_);
}