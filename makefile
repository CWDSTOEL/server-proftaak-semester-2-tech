all:
	gcc -Wall -Wextra main.c server.c server_data_procces.c -o server_program

clean:
	rm -f server_program