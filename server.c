#include"server.h"

int socketfd;
int client_socket;
struct sockaddr_in server_addr;
struct sockaddr_in client_addr;
char receive_buffer[RECV_BUFFER_SIZE];
char send_buffer[SEND_BUFFER_SIZE]; 
 

int create_socket(){

socketfd = socket(AF_INET,SOCK_STREAM,0);

if(socketfd == -1){

    printf("socket error\n");

    return SOCKET_ERROR_CREATION_FAILED;
}

int socket_option = 1;

setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR,&socket_option,sizeof(socket_option));

printf("socket succes\n");

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

printf("bind succes\n");

return SOCKETBIND_SUCCES;
};

int socket_listen(){

int socket_listen_check = listen(socketfd,CLIENT_QUE_SIZE);

if(socket_listen_check == -1){

    printf("error code:%d\n",socket_listen_check);
    
    return LISTEN_FAILED; 
}

printf("listen error code is%d\n",socket_listen_check);

return LISTEN_SUCCES;

};


int accept_connection(){

    socklen_t addres_len_client = sizeof(client_addr);

   client_socket = accept(socketfd,(struct sockaddr*)&client_addr,&addres_len_client);

    if(client_socket == -1){

        printf("error code:%d\n",client_socket);
        
        return ACCEPT_FAILED;

    }

    printf("client connected\n");
     
    return ACCEPT_SUCCES;

}


int recveive_client(){
 
int total_message_size = 0;
int receive_check;

while(total_message_size < 36){

    receive_check = recv(client_socket,receive_buffer + total_message_size,PACKET_SIZE - total_message_size,0);   

     
    if(receive_check <= 0){

    printf("receive error:%d\n", receive_check);

    return RECEIVE_ERROR;
    
}

    total_message_size += receive_check;

     
}
         
 printf("packet complete\n");
 receive_buffer[36] = '\0'; 

printf("recveice packet succes\n");

 return RECVEIVE_PACKET_SUCCES;

};

int server_send(int user_id){

    int user_id_send = htonl(user_id);

    printf("user_id%d",user_id);

    int server_send_check = send(client_socket,&user_id_send,sizeof(user_id_send),0);

    printf("server error code is%d",server_send_check);

    if(server_send_check == -1){

        return server_send_failed;

    }

    if(server_send_check < sizeof(user_id_send)){

        printf("buffer is not fully send\n");

        return server_send_failed;
    }

    return server_send_succes;
};


int socket_close(){

int communication_socket_close_check = close(client_socket);

if(communication_socket_close_check == SOCKET_CLOSE_FAILED){

    printf("communication socket close failed\n");

    return SOCKET_CLOSE_FAILED;
}    


return SOCKET_CLOSE_SUCCES;


}

 
