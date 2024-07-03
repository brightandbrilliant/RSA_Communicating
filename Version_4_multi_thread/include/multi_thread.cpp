#include "..\lib_\multi_thread.h"

void transis_client_handle(transistor_handle_client handler){
    std::string receive_server_message = 
            handler.Communicator.receive_message(handler.client_sock_to_server);
        handler.Communicator.message_send(handler.client_sock,receive_server_message);

        std::string receive_client_message = 
            handler.Communicator.receive_message(handler.client_sock);
        handler.Communicator.message_send(handler.client_sock_to_server,receive_client_message);

        printf("Message from client: %s\n",receive_client_message.c_str());
}