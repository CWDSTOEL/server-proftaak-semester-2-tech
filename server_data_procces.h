#ifndef SERVER_DATA_PROCCES_H
#define SERVER_DATA_PROCCES_H

#include<string.h>

#define MAX_USERS 200
#define USER_DATABASE_FULL -1
#define ADD_USER_SUCCES 1
#define USER_NOT_FOUND 0
#define PASSWORD_WAS_NOT_IN_USE 1

typedef struct{

  int  id;
  char  password[37];

}user_data;

extern user_data data_base[MAX_USERS];
extern int aantal_gebruikers;
extern int id_counter;

int add_user_data(char receive_data[37]);
int find_user_password(char receive_data[37]);
int get_or_create_user();



#endif