#include "server_data_procces.h"
#include "server.h"

 
user_data data_base[MAX_USERS];
int aantal_gebruikers = 0;
int id_counter = 1;



int add_user_data(char receive_data[37]){

if(aantal_gebruikers >= MAX_USERS){

    printf("database is full");

    return USER_DATABASE_FULL;
}

memcpy(data_base[aantal_gebruikers].password, receive_data,36);

data_base[aantal_gebruikers].password[36] = '\0';
data_base[aantal_gebruikers].id = id_counter++; 

int user_id = data_base[aantal_gebruikers].id;

aantal_gebruikers++;

return user_id;
}

int find_user_password(char receive_data[37]){

for(int i = 0; i < aantal_gebruikers; i++){

if (strcmp(receive_data,data_base[i].password) == 0){

    return data_base[i].id;
}

}

return USER_NOT_FOUND;

}

int get_or_create_user(){

int user_id = find_user_password(receive_buffer);

if(user_id != USER_NOT_FOUND){

    printf("password is already in use\n");
    
    return user_id;


}

 return add_user_data(receive_buffer);

}