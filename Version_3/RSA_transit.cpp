#include "lib_\RSA_tcp_server_class.h"
#include "lib_\RSA_tcp_client_class.h"
#include "lib_\RSA_coding.h"

int main(int argc,char* argv[]){
    if(argc<3){
        perror("Not enough parameters.\n");
        exit(-1);
    }

    int port_to_server = atoi(argv[1]);//与server相连接
    int port_to_client = atoi(argv[2]);//提供给client的接口

    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);
}