#ifndef SERVER_DATA_PROCCES_H
#define SERVER_DATA_PROCCES_H

#define MAX_USERS 200

typedef struct{

  int  id[10];
  char  password[10];

}user_data;

user_data data_base[MAX_USERS];
int aantal_gebruikers;

int add_user_data(int receive_data);
int find_id();



#endif