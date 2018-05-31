#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define port 2000

struct sockaddr_in servidor;

int main(){
	int tamservidor = sizeof(servidor);
	int number;
	// criar socket
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	
	// testa se o socket foi criado com sucesso
	if(sock == -1){
		perror("socket ");
		exit(1);
	}

	// setar a estrutura de dados servidor
	servidor.sin_family = AF_INET;
	servidor.sin_port = htons(port);
	memset(servidor.sin_zero, 0, 8);

	// associa um endereço ip a uma porta
	int ok = bind(sock, (struct sockaddr*) &servidor, sizeof(servidor));
	if(ok == -1){
		perror("bind ");
		exit(1);
	}

	// ouve a porta e espera por um cliente 
	listen(sock, 1);
	printf("servidor iniciado com sucesso!\n");
	int conectado = accept(sock,(struct sockaddr*) &servidor, &tamservidor);
	if(conectado == -1){
		perror("accept ");
		exit(1);
	}
	
	while(1){
		if(recv(conectado, &number, sizeof(number), 0) > 0){
			printf("%d\n", number);
		}
	}
}
