#include "pipe_networking.h"


int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );
  while(1){
    char *response=calloc(BUFFER_SIZE,sizeof(char));
    printf("Type Message to Server:");
    fgets(response,BUFFER_SIZE,stdin);
    write(to_server,response,strlen(response));
    char* data=calloc(BUFFER_SIZE,sizeof(char));
    read(from_server,data,BUFFER_SIZE);
    printf("The server says %s\n",data);
    free(data);
    free(response);
  }
}
