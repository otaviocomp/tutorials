#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

#define port 2000

struct sockaddr_in cliente;

int main(){
	int tamcliente = sizeof(cliente);
	int server;
	int number = 0;
	// criar socket
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	
	// testa se o socket foi criado com sucesso
	if(sock == -1){
		perror("socket ");
		exit(1);
	}

	// setar a estrutura de dados cliente
	cliente.sin_family = AF_INET;
	cliente.sin_port = htons(port);
	cliente.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(cliente.sin_zero, 0, 8);

	// conectar ao servidor
	int conectar = connect(sock,(struct sockaddr*) &cliente, tamcliente); 
	if(conectar == -1){
		perror("connect ");
		exit(1);
	}

	while(1){
		number++;
		send(sock, &number, sizeof(number), 0);
		sleep(1);
	}
}
