#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MYPORT 2222
#define BUF_LEN 2000


int main(void){

  int sock, recebido, servidor, len,STOP=1;
  struct sockaddr_in server;
  char send_data[1024], received_data[1024];
  printf("Cliente\n");

  sock = socket(AF_INET , SOCK_STREAM , 0);
  if (sock == -1){
    printf("Could not create socket");
  }

  else{
  puts("Socket created");
  }

  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  server.sin_family = AF_INET;
  server.sin_port = htons(MYPORT);

  //Connect to remote server
  if (connect(sock, (struct sockaddr*)&server , sizeof(server))< 0){
    perror("Conecção falhou");
    return 1;
  }

  else{
    puts("Conectado\n");
  }

  while(STOP){
    gets(send_data);
    puts("A escrever: ");
    send(sock, send_data, 1024, 0);

    len=recv(sock, received_data, 1024, 0);
    received_data[len]='\0';
    if(len>0){
        printf("Mensagem recebida: %s\n", received_data);
    }

    if(received_data[0]=='#'){
		  printf("\nChat terminado\n");
			STOP=0;
			continue;
	  }
  }
  close(sock);
  return 0;

}
