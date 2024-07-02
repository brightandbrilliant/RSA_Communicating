#include "lib_\RSA_tcp_client_class.h"
#include "lib_\RSA_coding.h"

int main(int argc, char* argv[]){
    if(argc < 2){
        perror("Not enough parameters.\n");
        exit(-1);
    }
    int port = atoi(argv[1]);

    //创建客户端
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);
    SOCKET client_sock;
    client_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    struct sockaddr_in socket_addr;
    connect_to_server(socket_addr,port,client_sock);

    while(true){
        std::string message;
        std::cout<<"Input your message:\n";
        std::cin>>message;
        Hash_coding(message);
        message_send(client_sock, message);
        char recv_[1024];
        memset(recv_, 0, 1024);
        recv(client_sock,recv_,1024,0);
        printf("%s",recv_);
    }

    closesocket(client_sock);
}