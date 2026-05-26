#include "server.h"

int main(){

create_socket();
bind_socket();
socket_listen();

while(socketfd != -1){

    int accept_status = accept_connection();

    if(accept_status != ACCEPT_FAILED){

        recveive_client();
        server_send(); 

        close_socket();
    }

};

close_socket();

    return 0;

};
