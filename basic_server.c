#include "pipe_networking.h"


int main() {

  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );
  printf("recreating well known-pipe");
  char data[BUFFER_SIZE];
  read(from_client,data,BUFFER_SIZE);
  printf("The client says %s",data);
  char *response="generic string";
  write(to_client,response,strlen(response));
}
