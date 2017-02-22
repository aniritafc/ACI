#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "modbus.h"

#define MYPORT 2222


int sConnect (server_add, port){

  fd = socket(AF_INET, SOCK_STREAM, 0); // cria o socket
	if(fd < 0){
		printf("Erro criacao do socket\n");
		exit(1);
    return 0;
	}

	else{
		printf("Socket created\n");
    return fd;
	}

	////////////////bind///////////////////

  bi = bind(fd, (struct sockaddr*)&loc, addlen);
	if(bi == -1){
		exit(1);
		puts("Erro no bind\n");
	}
	else{
		puts("Bind\n");
	}

  ///////////////listen////////////////

	listen (fd, 10);

  //////// entra num ciclo ate aceitar um cliente?///////////
  while(1){
	 client = accept(so, (struct sockaddr*)&rem, &addlen);
	 if(client>0){
		puts("Accept. Waiting Requests\n");
		break;
	 }
  }

}

int sDisconnect(fd){
	close(fd);
	if (close(fd)<0){
		puts("Erro na disconecao\n");
	}
	else{
		puts("Disconectado\n");
		return 0;
  }
}
