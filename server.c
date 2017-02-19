#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MYPORT 2222
#define BUF_LEN 1024

int main(void){
  struct in_addr s_addr, sin_addr;
  int client, so, bi, len;
  struct sockaddr_in loc, rem, serv, sin_family, sin_port;
  socklen_t addlen = sizeof(loc);
  char buf[BUF_LEN], received_data[1024];


  so = socket(AF_INET, SOCK_STREAM,0);
	if(so < 0){
    exit(1);
  }

  else{
    printf("Socket created\n");
  }

	loc.sin_family= AF_INET;
	loc.sin_port=htons(MYPORT);
	inet_aton("127.0.0.1",&loc.sin_addr);

	bi=bind(so, (struct sockaddr*)&loc, addlen);
	if(bi == -1){
    exit(1);
  }
  else{
    puts("Bind\n");
  }

	listen (so, 10);

  while(1){

	   client = accept(so, (struct sockaddr*)&rem, &addlen);
     puts("Accept\n");
     while(1){
       gets(buf);
       send(client, buf, strlen(buf), 0);
      //  printf("Aguardar resposta...");

      len= recv(client, received_data, 1024, 0);
      received_data[len]='\0';

      if(len == 0){
        puts("Client disconnected");
        fflush(stdout);
      }
      else if(len == -1){
        perror("recv failed");
      }
      else{
        printf("\n Dados recebidos = %s\n", received_data);
      }

    }
  }
  close(so);

  return 0;

}
