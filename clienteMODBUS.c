#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "modbusD.h"
#include "modbusAP.h"

#define port 2222
#define buffer 2000

int main(void){
  int fd;
  struct sockaddr_in sin_port;
  struct in_addr server_add;
  uint8_t buf[buffer];
  
  fd = cConnect (server_add, port);
  server.sin_addr.server_add = inet_addr("127.0.0.1");
  server.sin_family = AF_INET;
  server.sin_port = htons(port);

  while(1){// cena do STOP

    switch()
      case WR: Write_multiple_regs(fd, st_r, n_r,val);
      case RD: Read_h_regs(fd,st_r,n_r,val);

  }
  cDisconnect(so);
  return 0;
}
