#include"server.h"

int socketfd;
int client_socket;
struct sockaddr_in server_addr;
struct sockaddr_in client_addr;
//int8_t send_buffer[BUFFER_LENGHT];  
int8_t receive_buffer[BUFFER_LENGHT]; 
socklen_t addres_len_server = sizeof(server_addr);


int create_socket(){

socketfd = socket(AF_INET,SOCK_STREAM,0);

if(socketfd == -1){

    printf("socket error");

    return SOCKET_ERROR_CREATION_FAILED;
}

int socket_option = 1;

setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR,&socket_option,sizeof(socket_option));

return SOCKET_SUCCES;
};

int bind_socket(){

memset(&server_addr, 0,sizeof(server_addr)); 
server_addr.sin_family = AF_INET;
server_addr.sin_port = htons(portnumber);
server_addr.sin_addr.s_addr = htonl(INADDR_ANY); 

int bind_check = bind(socketfd,(struct sockaddr*) &server_addr,sizeof(server_addr));

if(bind_check != 0){

    return SOCKETBIND_fail;
}

return SOCKETBIND_SUCCES;
};

int socket_listen(){

int socket_listen_check = listen(socketfd,CLIENT_QUE_SIZE);

if(socket_listen_check == -1){

    printf("error code:%d",socket_listen_check);
    
    return LISTEN_FAILED; 
}

return LISTEN_SUCCES;

};


int accept_connection(){

    socklen_t addres_len_client = sizeof(client_addr);

   client_socket = accept(socketfd,(struct sockaddr*)&client_addr,&addres_len_client);

    if(client_socket == -1){

        printf("error code:%d",client_socket);
        
        return ACCEPT_FAILED;

    }

    return ACCEPT_SUCCES;

}


int recveive_client(){

int receive_check = recv(client_socket,receive_buffer,sizeof(receive_buffer),0);   


if(receive_check <= 0){

    printf("receive error:%d", receive_check);

    return RECEIVE_ERROR;
}
         
return receive_check;

};

int server_send(){

    int size_send_buffer = sizeof(send_buffer);

    int server_send_check = send(client_socket,receive_buffer,sizeof(receive_buffer),0);

    if(server_send_check != -1){

        return server_send_failed;

    }

    if(server_send_check < size_send_buffer){

        printf("buffer is not fully send");

        return server_send_failed;
    }

    return server_send_succes;
};


int socket_close(){

socket_close();

}

 
