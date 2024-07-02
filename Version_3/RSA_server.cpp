#include "lib_\tcp_server_client_class.h"
#include "lib_\RSA_coding.h"

#define max_client 5

int main(int argc, char* argv[]){
    if(argc < 2){
        perror("Not enough parameters.\n");
        exit(-1);
    }
    std::vector<ll> key = generating_key();
    int server_port = atoi(argv[1]);

    tcp_server Server;
    tcp_communicate Communicator;

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
    Server.bind_to_client(server_socket_address,client_address,server_port,server_sock);

    listen(server_sock, max_client);
    printf("Server listening on %d.\n",server_port);

    //接受客户端
    Server.accept_client(client_sock,client_address,client_len,server_sock);

    //和客户端进行沟通
    while(true){
        std::string test_message = "You are connected to the server now.\n";
        Communicator.message_send(client_sock,test_message);

        std::string recv_str = Communicator.receive_message(client_sock);
        Hash_decoding(recv_str);
        printf("Receive message: %s\n",recv_str.c_str());
    }

    closesocket(client_sock);
    closesocket(server_sock);
}