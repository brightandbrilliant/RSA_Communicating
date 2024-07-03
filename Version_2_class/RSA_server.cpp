#include "lib_\RSA_tcp_server_class.h"
#include "lib_\RSA_coding.h"

#define max_client 5

int main(int argc, char* argv[]){
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
    struct sockaddr_in server_socket_address,client_address;
    socklen_t client_len = sizeof(client_address);
    bind_to_client(server_socket_address,client_address,server_port,server_sock);

    listen(server_sock, max_client);
    printf("Server listening on %d.\n",server_port);

    //接受客户端
    accept_client(client_sock,client_address,client_len,server_sock);

    //和客户端进行沟通
    while(true){
        std::string test_message = "Hello client!\n";
        message_send(client_sock,test_message);
        char recv_[1024];
        memset(recv_, 0, 1024);
        recv(client_sock,recv_,1024,0);
        std::string recv_str = std::string(recv_);
        Hash_decoding(recv_str);
        printf("%s",recv_str.c_str());
    }

    closesocket(client_sock);
    closesocket(server_sock);
}