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

	struct in_addr s_addr, sin_addr;
	int client, so, bi, read_size;
	struct sockaddr_in loc, rem, serv, sin_family, sin_port;
	socklen_t addlen = sizeof(loc);
	char buf[BUF_LEN];

    so= sConnect(s_addr, MYPORT)
	{
		so = socket(AF_INET, SOCK_STREAM,0);
		if(so < 0){
			exit(-1);
			/* ver se o socket foi criado */
		}
			 
		puts("Socket created");
		
		loc.sin_family= AF_INET;
		loc.sin_port=htons(MYPORT);
		inet_aton("127.0.0.1",&loc.sin_addr);

	}

	//bind
	bi=bind(so, (struct sockaddr*)&loc, addlen);
	if(bi < 0){
		exit(-1);
	}
	puts("Bind");

	//listen
	listen (so, 10);

	//accept
	client = accept(so, (struct sockaddr*)&rem, &addlen);
	if(client < 0) {
		exit(-1);
	}
	puts("Accept");

	// send and recive
	read_size = recv(client, buf, BUF_LEN, 0);

	if(read_size >0){
		write(client, buf , strlen(buf));
	}
	if(read_size == 0){
      puts("Client disconnected");
      fflush(stdout);
	}
	else if(read_size == -1){
      perror("recv failed");
	}
	sDisconnect(so){
	close(so);
	return 0;
	}
