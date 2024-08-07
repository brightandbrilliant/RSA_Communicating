#include "lib_\tcp_server_client_class.h"
#include "lib_\RSA_coding.h"

int main(int argc, char* argv[]){
    if(argc < 2){
        perror("Not enough parameters.\n");
        exit(-1);
    }
    int port = atoi(argv[1]);

    tcp_client Client;
    tcp_communicate Communicator;

    //创建客户端
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);
    SOCKET client_sock;
    Communicator.socket_create(client_sock);
    struct sockaddr_in socket_addr;
    Client.connect_to_server(socket_addr,port,client_sock);

    bool begin_flag = true;
    int N=0;
    int e=0;
    while(true){
        if(begin_flag){
            std::cout<<"You are connected to the server now.\n";
            Communicator.input_mod_power(N,e);
            begin_flag=false;
        }
        
        std::string message;
        Communicator.input_message(message);
        message = RSA_coding_string(message,N,e);
        Communicator.message_send(client_sock, message);
        std::cout<<std::endl;
        std::string recv_ = Communicator.receive_message(client_sock);
        printf("%s",recv_.c_str());
    }

    closesocket(client_sock);
    WSACleanup();
}