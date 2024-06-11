#include "RSA_coding.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <string>
#include <cstring>

#define max_client 5

int main(int argc, char* argv[]){
    //预备工作
    if(argc < 2){
        perror("Not enough parameters.\n");
        exit(-1);
    }
    std::vector<ll> key = generating_key();
    int server_port = atoi(argv[1]);

    //创建服务端
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);
    
    SOCKET server_sock,client_sock;
    server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(server_sock==-1){
        perror("Failed to create server socket.\n");
        exit(-1);
    }

    //绑定
    struct sockaddr_in server_socket_address,client_address;
    server_socket_address.sin_family = AF_INET;
    server_socket_address.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    server_socket_address.sin_port = htons(server_port);
    socklen_t client_len = sizeof(client_address);

    int bind_ = bind(server_sock, 
    (struct sockaddr*) &(server_socket_address),
    sizeof(struct sockaddr));

    if(bind_ == -1){
        perror("Failed to bind socket.\n");
        exit(-1);
    }

    listen(server_sock, max_client);
    printf("Server listening on %d.\n",server_port);

    //连接客户端
    client_sock = accept(server_sock, 
        (struct sockaddr*)&client_address, &client_len);

    if(client_sock<0){
        perror("Failed to accept.\n");
        exit(-1);
    }


    //和客户端进行沟通
    while(true){
        //char default_message[1025];
        //memset(default_message, 0, 1025);
        //sscanf(default_message,"You are served by a server now. The public key is e:%lld, N:%lld.\n",&key[0],&key[2]);
        //这里用scanf会出问题，不知道为什么

        std::string default_message = "You are served by a server now. The public key is e:";
        default_message += std::to_string(key[0]);
        default_message += ", ";
        default_message += "N:";
        default_message += std::to_string(key[2]);
        default_message += "\n";

        int send_ = send(client_sock, default_message.c_str(), default_message.length() , 0);

        if(send_==-1){
            perror("Failed to send.\n");
            exit(-1);
        }

        char rec_buf[1025];
        memset(rec_buf, 0, 1025);
        int receive_ = recv(client_sock, rec_buf, 1024, 0);
        if(receive_ == -1){
            perror("Failed to receive.\n");
            exit(-1);
        }

        printf("%s",rec_buf);
    }

    closesocket(client_sock);
    closesocket(server_sock);
}