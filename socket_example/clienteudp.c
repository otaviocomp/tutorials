#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

#define porta 1313

int main(){
	int number = 0;
	struct sockaddr_in servidor, cliente;
	int sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock == -1){
		perror("socket ");
		exit(1);
	}
	cliente.sin_family = AF_INET;
	cliente.sin_port = htons(porta);
	cliente.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(cliente.sin_zero, 0, 8);

	if(bind(sock, (struct sockaddr*) &servidor, sizeof(servidor)) == -1){
		perror("bind ");
		exit(1);
	}

	while(1){
		number++;
		sendto(sock, &number, sizeof(number), 0, (struct sockaddr*) &cliente, sizeof(cliente));
		sleep(1);
	}
}