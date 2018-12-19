#include "pipe_networking.h"


int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );
  printf("creating well known-pipe");
  char response[BUFFER_SIZE];
  fgets(response,BUFFER_SIZE,stdin);
  write(to_server,response,strlen(response));
  char data[BUFFER_SIZE];
  read(from_server,data,BUFFER_SIZE);
  printf("The server says %s",data);
}
