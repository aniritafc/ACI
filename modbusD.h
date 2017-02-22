#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>

#define port 2222


int Send_Modbus_request (fd, APDU, APDUlen, APDU_R){
  int rd;
  // generates TI (trans.ID  sequence number)
  PDU = APDU(SDU) + MBAP
  write (fd, PDU, PDUlen) // sends Modbus TCP PDU
  rd = read (fd, PDU_R, PDU_Rlen);
  if(rd <0){
    printf("Erro");
    exit(1);
  }
  if(rd>0){
    printf("Mensagem recebida: %s\n", APDU_R);
    gets(APDU_R);
    puts("A escrever: ");
    send(sock, APDU_R, 1024, 0);
  }
  //if response, remove MBAP, PDU_R   APDU_R
  // returns: APDU_R and 0 – ok, <0 – error (timeout)
}
//////////////////////////////////////
while(!STOP){
		printf("\nWrite something\n ");
		//scanf("%s", buf);
		fgets (buf, BUF_LEN, stdin);
		/* Remove trailing newline, if there. */
	  if ((strlen(buf)>0) && (buf[strlen (buf) - 1] == '\n'))
	        buf[strlen (buf) - 1] = '\0';


		len=send(sock, buf, strlen(buf)+1, 0);
		if(len!=strlen(buf)+1)	printf("\nSEND ERROR\n");
		printf("\nSent:%d\n\n",len);

		/*Check if it's terminating char*/
		if (buf[0]=='#'){
			printf("\nTERMINATING CHAR SENT\n");
			STOP=1;
			continue;
		}

		recv(sock, buf_in, BUF_LEN,0);
		if(len==-1){
			printf("RECV ERROR\n");
			continue;
		}
		printf("Received data:\n %s \n Size: %d\n",buf_in,len);
	}
///////////////////////////////////////

int Receive_Modbus_request (fd, APDU){
  read (fd, PDU(MBAP), 7 ) // read MBAP of request PDU
  //remove MBAP: TI and length (APDUlen + 1)
  read (fd, APDU, APDUlen) // read request APDU
  // returns: APDU and TI – ok, <0 – erro
}
//////////////////////////////////
while(!STOP){
		len=recv(sd, buf, BUF_LEN, 0);
		if(len==-1){
			printf("RECV ERROR\n");
			STOP=1;
			continue;
		}

		printf("Received data:\n %s\n Size: %d\n",buf,len);

		if(buf[0]=='#'){
			printf("\nTERMINATING CHAR RECEIVED\n");
			STOP=1;
			continue;
		}

		for(i=0;i<strlen(buf);i++){
			if(buf[i]>='a' && buf[i]<='z'){
				buf[i]=(char)(buf[i]-32);
			}
		}

		send(sd,buf,len,0);
		if(len!=strlen(buf)+1)	printf("SEND ERROR\n");
		printf("\nSent:%d\n\n",len);
	}
////////////////////////////////
int Send_Modbus_response (fd, APDU_R, APDU_Rlen, TI){
  // assembles PDU = APDU_R + MBAP (with TI)
  write (fd, PDU, PDUlen)//sends ModbusTCP response PDU // returns: >0 – ok, <0 – erro
}


int R_coils (st, n, val){
  // read n regs/ coils starting from st and write in val
  // returns: num regs/coils read, values in val – ok, <0 – error
}


int W_coils (st, n, val){
  // write n regs/ coils starting from st using values from val
  // returns: num regs/ coils written – ok, <0 – error
}
