#include "server.h"
#include "server_data_procces.h"

int main()
{
create_socket();
bind_socket();
socket_listen();

while (socketfd != -1) {

int accept_status = accept_connection();

if (accept_status != ACCEPT_FAILED) {

    if (recveive_client() == RECVEIVE_PACKET_SUCCES) {

        int user_id = get_or_create_user();

        server_send(user_id);
    }

        socket_close();
    }
}


    return 0;
}
