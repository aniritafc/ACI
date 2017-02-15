#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MYPORT 2222
#define BUF_LEN 2000000

int main(){

	int sock, recebido, client;
	struct sockaddr_in server;
	char message[2000], server_reply[2000];

  //Create socket
	sock = socket(AF_INET , SOCK_STREAM , 0);
  if (sock == -1)
  {
      printf("Could not create socket");
  }
  puts("Socket created");

  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  server.sin_family = AF_INET;
  server.sin_port = htons(MYPORT);

  //Connect to remote server
  if (connect(sock , (struct sockaddr*)&server , sizeof(server)) < 0)
  {
      perror("Connect failed");
      return 1;
  }

  puts("Connected\n");

  //keep communicating with server
  while(1){

      printf("Enter message :");
      scanf("%s", message);
     putchar('\n');

      //Send some data
      if( send(client, message ,2000 , 0) < 0){
          puts("Send failed");
          return 1;
      }

      if(send(client, message , 2000, 0) > 0) {
          puts("Sended");
          putchar('\n');
        }


      //Receive a reply from the server
      if( recv(client, server_reply ,2000 , 0) < 0){
          puts("Recv failed");
          break;
      }
      if(recv(client, server_reply , 2000 , 0) > 0){
          puts("Received");
          putchar('\n');
      }
      

      puts("Server reply:");
      puts(server_reply);
    }

  close(sock);
  return 0;

}