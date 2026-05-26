all:
	gcc -Wall main.c server.c -o server_program

clean:
	rm -f server_program