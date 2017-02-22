#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "modbus.h"

#define port 2222


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

int cConnect (server_add, port){
  fd = socket(AF_INET, SOCK_STREAM,0);
  if(fd < 0){
    printf("Erro");
    exit(1);
    return 0;
  }
  else{
    printf("Socket criada\n");
    return fd;
  }

  if (connect(fd, (struct sockaddr*)&server_add , sizeof(server_add))< 0){
    printf("Conexão falhou");
    return 1;
  }
  else{
    puts("Conectado\n");
  }
}

int cDisconnect(fd){
  close(fd);
  if(close(fd)<0){
    printf("Erro");
    exit(1);
  }
  else{
  printf("Desconectada");
  }
}

int Get_request(fd,op,st,n,val){
  uint16_t TI;

  TI=Receive_Modbus_request(fd,APDU)
}

int Write_multiple_regs(fd, st_r, n_r,val){
  Send_Modbus_request(fd,APDU, APDUlen, APDU_R)
}

int Read_h_regs(fd,st_r, n_r,val){
  Send_Modbus_request(fd,APDU, APDUlen,APDU_R)
}
