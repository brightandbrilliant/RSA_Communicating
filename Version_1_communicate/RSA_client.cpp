#include "RSA_coding.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include<string>
#include <windows.h>

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

    //连接客户端
    struct sockaddr_in socket_addr;
    socket_addr.sin_family = AF_INET;
    socket_addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    socket_addr.sin_port = htons(port);
    int connect_ = connect(client_sock, (sockaddr*) &(socket_addr),sizeof(socket_addr));
    if(connect_ == -1){
        perror("Failed to connect with the server.\n");
        exit(-1);
    }

    //接受信息，输出信息
    while(true){
        char receive_buf[1025];
        memset(receive_buf, 0 , 1025);
        int receive = recv(client_sock, receive_buf, 1024, 0);
        if(receive == -1){
            perror("Failed to receive.\n");
            exit(-1);
        }
        printf("%s",receive_buf);
        std::string message;
        printf("Please input the mod and power keys and the message.\n");
        ll mod,e;
        printf("mod:");
        std::cin>>mod;
        printf("e:");
        std::cin>>e;
        getline(std::cin,message);
        printf("message:");
        getline(std::cin,message);
        int i=0;
        while(message[i]!='\0'){
            message[i] = RSA_coding_decoding(message[i], e, mod);
            i++;
        }
        send(client_sock,message.c_str(),message.length(),0);
        Sleep(1000);
    }

    closesocket(client_sock);
}