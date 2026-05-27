#ifndef SERVER_H
#define SERVER_H

#include <stdio.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>


#define portnumber 8000


#define SOCKET_ERROR_CREATION_FAILED 0
#define SOCKET_SUCCES 1
#define SOCKETBIND_SUCCES 0
#define SOCKETBIND_fail -1
#define message_lenght 10
#define RECEIVE_ERROR -1
#define BUFFER_LENGHT 1024
#define ACCEPT_FAILED -1
#define ACCEPT_SUCCES 0
#define LISTEN_FAILED -1
#define LISTEN_SUCCES 0
#define CLIENT_QUE_SIZE 3
#define server_send_succes 0
#define server_send_failed -1
#define SOCKET_CLOSE_FAILED -1
#define SOCKET_CLOSE_SUCCES 1
#define RECVEIVE_PACKET_SUCCES 1
#define PACKET_SIZE 36
#define SEND_BUFFER_SIZE 240
#define RECV_BUFFER_SIZE 240

 
extern int socketfd;
extern int client_socket;
extern char receive_buffer[RECV_BUFFER_SIZE];
extern char send_buffer[SEND_BUFFER_SIZE];

 


int create_socket();
int bind_socket();
int socket_listen();
int accept_connection();
int recveive_client();
int server_send(int user_id);
int socket_close();


#endif 
