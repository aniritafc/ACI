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

int main(void){
  int fd;
  struct sockaddr_in sin_port;
  struct in_addr server_add;

  fd = sConnect (server_add, port);
  server.sin_addr.server_add = inet_addr("127.0.0.1");
  server.sin_family = AF_INET;
  server.sin_port = htons(MYPORT);

  while(1){
    TI = Get_request (fd, op, st, n, val);
    Receive_Modbus_request(fd, APDU);
    W_coils (st, n, val);
    R_coils (st, n, val);
    Send_response(fd, TI, op, st, n, val);
    Send_Modbus_response(fd, APDU_R, APDU_Rlen, TI);

  }
  
  sDisconnect (fd);
  return 0;

}
